#include "model/model_haar.h"

void HaarModel::detect(cv::Mat& image, std::vector<cv::Rect>& faces) {

    cv::Mat gray;
    //change image to gray color
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    //Equalizes the histogram of a grayscale image
    equalizeHist(gray, gray);
    //detects faces
    cascade.detectMultiScale(gray, faces,
        1.1, 2, 0
        //|CASCADE_FIND_BIGGEST_OBJECT
        //|CASCADE_DO_ROUGH_SEARCH
        | cv::CASCADE_SCALE_IMAGE,
        cv::Size(30, 30));
}

void HaarModel::visualize(cv::Mat& image, std::vector<cv::Rect>& faces, double fps) {
    //string for fps
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //puts fps value on image
    putText(image, fpsString, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 255, 255), 1);
    //for size of faces
    for (size_t i = 0; i < faces.size(); i++){
        cv::Rect r = faces[i];
        //draws rectangle
        rectangle(image, cv::Point(cvRound(r.x), cvRound(r.y)),
            cv::Point(cvRound(r.x + r.width - 1), cvRound(r.y + r.height - 1)),
           cv::Scalar(0, 255, 255));
    }
}

cv::Mat HaarModel::process(cv::Mat frame) {

    //check if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    //clones image
    cv::Mat image = frame.clone();
    cv::TickMeter tm;
    tm.start();
    //detects faces
    detect(image, faces);
    tm.stop();
    //Draws results on the input image
    visualize(image, faces, tm.getFPS());
	return image;
}