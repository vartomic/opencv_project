#include "model/haar_model.h"

void HaarModel::visualize(cv::Mat& img, cv::CascadeClassifier& cascade, cv::CascadeClassifier& nestedCascade,
	double scale, bool tryflip) {

    double t = 0;
    std::vector<cv::Rect> faces, faces2;
    const static cv::Scalar colors[] =
    {
        cv::Scalar(255,0,0),
        cv::Scalar(255,128,0),
        cv::Scalar(255,255,0),
        cv::Scalar(0,255,0),
        cv::Scalar(0,128,255),
        cv::Scalar(0,255,255),
        cv::Scalar(0,0,255),
        cv::Scalar(255,0,255)
    };
    cv::Mat gray, smallImg;

    //input to gray
    cvtColor(img, gray, cv::COLOR_BGR2GRAY);
    double fx = 1 / scale;
    resize(gray, smallImg, cv::Size(), fx, fx, cv::INTER_LINEAR_EXACT);
    equalizeHist(smallImg, smallImg);

    t = (double)cv::getTickCount();
    cascade.detectMultiScale(smallImg, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        | cv::CASCADE_SCALE_IMAGE,
        cv::Size(30, 30));
    if (tryflip)
    {
        flip(smallImg, smallImg, 1);
        cascade.detectMultiScale(smallImg, faces2,
            1.1, 2, 0
            //|CASCADE_FIND_BIGGEST_OBJECT
            //|CASCADE_DO_ROUGH_SEARCH
            | cv::CASCADE_SCALE_IMAGE,
            cv::Size(30, 30));
        for (std::vector<cv::Rect>::const_iterator r = faces2.begin(); r != faces2.end(); ++r)
        {
            faces.push_back(cv::Rect(smallImg.cols - r->x - r->width, r->y, r->width, r->height));
        }
    }
    t = (double)cv::getTickCount() - t;
    printf("detection time = %g ms\n", t * 1000 / cv::getTickFrequency());
    for (size_t i = 0; i < faces.size(); i++)
    {
        cv::Rect r = faces[i];
        cv::Mat smallImgROI;
        std::vector<cv::Rect> nestedObjects;
        cv::Point center;
        cv::Scalar color = colors[i % 8];
        int radius;

        double aspect_ratio = (double)r.width / r.height;
        if (0.75 < aspect_ratio && aspect_ratio < 1.3)
        {
            center.x = cvRound((r.x + r.width * 0.5) * scale);
            center.y = cvRound((r.y + r.height * 0.5) * scale);
            radius = cvRound((r.width + r.height) * 0.25 * scale);
            circle(img, center, radius, color, 3, 8, 0);
        }
        else
            rectangle(img, cv::Point(cvRound(r.x * scale), cvRound(r.y * scale)),
                cv::Point(cvRound((r.x + r.width - 1) * scale), cvRound((r.y + r.height - 1) * scale)),
                color, 3, 8, 0);
        if (nestedCascade.empty())
            continue;
        smallImgROI = smallImg(r);
        nestedCascade.detectMultiScale(smallImgROI, nestedObjects,
            1.1, 2, 0
            //|CASCADE_FIND_BIGGEST_OBJECT
            //|CASCADE_DO_ROUGH_SEARCH
            //|CASCADE_DO_CANNY_PRUNING
            | cv::CASCADE_SCALE_IMAGE,
            cv::Size(30, 30));
        for (size_t j = 0; j < nestedObjects.size(); j++)
        {
            cv::Rect nr = nestedObjects[j];
            center.x = cvRound((r.x + nr.x + nr.width * 0.5) * scale);
            center.y = cvRound((r.y + nr.y + nr.height * 0.5) * scale);
            radius = cvRound((nr.width + nr.height) * 0.25 * scale);
            circle(img, center, radius, color, 3, 8, 0);
        }
    }
}

cv::Mat HaarModel::process(cv::Mat frame) {

    //check if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    if (scale < 1)
        scale = 1;

    cv::TickMeter tm;

    tm.start();

    cv::Mat image = frame.clone();

    visualize(image, cascade, nestedCascade, scale, false);

    tm.stop();

	return image;
}