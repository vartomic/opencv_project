#include "model/model_dlib.h"

void DlibModel::visualize(cv::Mat& image, int frame, std::vector<dlib::rectangle>& faces, double fps, int thickness) {
    //  Text string with fps value formatted from double to float
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //  Receives the width of input image
    int width = image.size().width;
    //  Receives the height of input image
    int height = image.size().height;
    //  Text string with width and height of input image
    std::string resolutionString = cv::format("Resolution : %d x %d", width, height);
    //  Function draws the text string with fps value in the image
    putText(image, fpsString, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 255, 255), thickness);
    //  Function draws the text string with resolution of input image on the image
    putText(image, resolutionString, cv::Point(0, 35), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), thickness);
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
    visualize(temp, -1, faces, tm.getFPS());
    //  Tickmeter stops
    tm.stop();    
    //  Returns processed image
    return temp;

}