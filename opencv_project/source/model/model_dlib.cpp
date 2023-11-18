#include "model/model_dlib.h"

void DlibModel::visualize(cv::Mat& temp, int frame, std::vector<dlib::rectangle>& faces, double fps, int thickness) {

}

cv::Mat DlibModel::process(cv::Mat frame) {
    //  Checks if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    //  Tickmeter measures passed time
    cv::TickMeter tm;
    //  Tickmeter starts
    tm.start();
    //  Creates a clone of an input image
    cv::Mat image = frame.clone();
    //
    dlib::cv_image<dlib::bgr_pixel> dlibImage(image);
    // Detect faces 
    faces = detector(dlibImage);
    //
    cv::Mat temp = dlib::toMat(dlibImage);
    //
    //visualize(temp, -1, faces, tm.getFPS());
    //  Tickmeter stops
    tm.stop();    
    //  Returns processed image
    return temp;

}