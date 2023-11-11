#include "model/model_mtcnn.h"

void MTCNNModel::visualize(cv::Mat& image, std::vector<Face>& faces, double fps, int thickness) {
    //  Text string with fps value formatted from double to float
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //  Receives the width of input image
    int width = image.size().width;
    //  Receives the height of input image
    int height = image.size().height;
    //  Text string with width and height of input image
    std::string resolutionString = cv::format("Resolution : %d x %d", width, height);
    //  Loop for all faces
    for (size_t i = 0; i < faces.size(); ++i) {
        //  Finds all faces and receives a rectangle froom each face 
        auto rect = faces[i].bbox.getRect();
        //  Draws rectangle around face
        rectangle(image, rect, cv::Scalar(0, 0, 255), thickness);
    }  
    //  Function draws the text string with fps value in the image
    putText(image, fpsString, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 255, 255), thickness);
    //  Function draws the text string with resolution of input image on the image
    putText(image, resolutionString, cv::Point(0, 35), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), thickness);
}
cv::Mat MTCNNModel::process(cv::Mat frame) {
    //  Checks if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    //  Tickmeter measures passed time
    cv::TickMeter tm;
    //  Tickmeter starts
    tm.start();
    //  Creates clone of an input image
    cv::Mat image = frame.clone();
    //  Detector finds faces and puts them into vector of faces
    auto faces = detector->detect(image, 20.f, 0.709f);
    //  Tickmeter stops
    tm.stop();
    visualize(image, faces, tm.getFPS());
    //  Returns processed image
	return image;
}