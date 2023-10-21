#include "model/haar_model.h"

void HaarModel::detect(cv::Mat& image, std::vector<cv::Rect>& faces) {

    cv::Mat gray, smallImg;
    //
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    //
    equalizeHist(smallImg, smallImg);
    //
    cascade.detectMultiScale(smallImg, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        | cv::CASCADE_SCALE_IMAGE,
        cv::Size(30, 30));      
}

void HaarModel::visualize(cv::Mat& image, std::vector<cv::Rect>& faces, double fps) {

    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //puts fps value on image
    putText(image, fpsString, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), 1);



    for (int i = 0; i < faces.size(); i++) {
        // Draw bounding box
        rectangle(image, cv::Rect2i(int(faces.at<float>(i, 0)), int(faces.at<float>(i, 1)), int(faces.at<float>(i, 2)), int(faces.at<float>(i, 3))), cv::Scalar(0, 255, 0));
    }

}

cv::Mat HaarModel::process(cv::Mat frame) {

    //check if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    //
    cv::Mat image = frame.clone();
    cv::TickMeter tm;
    //
    tm.start();
    //
    detect(image, faces);
    tm.stop();
    //
    visualize(image, faces, tm.getFPS());

	return image;
}