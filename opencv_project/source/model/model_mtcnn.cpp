#include "model/model_mtcnn.h"

void MTCNNModel::drawRectangles(cv::Mat& image, std::vector<Face>& faces, int thickness) {
    //  Loop for all faces
    for (size_t i = 0; i < faces.size(); ++i) {
        //  Finds all faces and receives a rectangle froom each face 
        auto rect = faces[i].bbox.getRect();
        //  Draws rectangle around face
        rectangle(image, rect, cv::Scalar(255, 0, 0), thickness);
    }  
}

cv::Mat MTCNNModel::process(cv::Mat frame) {
    //  Checks if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    //  Creates clone of an input image
    cv::Mat image = frame.clone();
    //  Tickmeter measures passed time
    cv::TickMeter tm;
    //  Tickmeter starts
    tm.start();
    //  Detector finds faces and puts them into vector of faces
    auto faces = detector->detect(image, 20.f, 0.709f);
    //  Number of founded faces resides in rows of matrix faces. _totalFaceScore adds that number to itself
    _totalFaceScore += faces.size();
    //  Counter of processed frames increments
    _processedFrames++;
    //  Tickmeter stops
    tm.stop();
    //  _totalTime sums to itself number of milliseconds spent on each frame
    _totalTime += tm.getTimeMilli();
    //  Function draws rectangles around faces and landmarks on faces, tickmeter receives fps value
    drawRectangles(image, faces);
    //  Renders text with fps value, number of processed frames, number of founded faces and ellapsed time in the input image
    visualize(image, tm.getFPS(), _processedFrames, _totalFaceScore, _totalTime);
    //  Returns processed image
	return image;
}