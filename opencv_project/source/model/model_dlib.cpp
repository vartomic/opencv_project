#include "model/model_dlib.h"

void DlibModel::visualize(cv::Mat& image, int frame, std::vector<dlib::rectangle>& faces, double fps, int thickness) {
    // Text string with fps value formatted from double to float
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
    //  Loop for all faces
    for (size_t i = 0; i < faces.size(); i++) {
        //  2D rectangle
        dlib::rectangle r = faces[i];
        //  Draws rectangle using 4/  Function draws rectangles around faces, tickmeter receives fps value coordinates
        rectangle(image, cv::Point2i(r.left(), r.top()), cv::Point2i(r.right() + 1, r.bottom() + 1),
            cv::Scalar(255, 255, 0), thickness);
    }
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
    //  Converts mat to dlib image
    dlib::cv_image<dlib::bgr_pixel> dlibImage(image);
    // Detects faces 
    faces = detector(dlibImage);
    //  Function draws rectangles around faces, tickmeter receives fps value
    visualize(image, -1, faces, tm.getFPS());
    //  Tickmeter stops
    tm.stop();    
    //  Returns processed image
    return image;

}