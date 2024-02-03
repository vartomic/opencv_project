#include "model/model_haar.h"

void HaarModel::detect(cv::Mat& image, std::vector<cv::Rect>& faces) {
    cv::Mat gray;
    //  Converts image to gray color
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    //  Equalizes the histogram of a grayscale image
    equalizeHist(gray, gray);
    //  Detects selected object in the input image with given parameters = input image, vector of faces, scalefactor,
    //  min amount of neighbours, min and max size of object 
    cascade.detectMultiScale(gray, faces,
        1.1, 2, cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
}

void HaarModel::drawRectangles(cv::Mat& image, std::vector<cv::Rect>& faces, int thickness) {
    for (size_t i = 0; i < faces.size(); i++){
        //  2D rectangle
        cv::Rect r = faces[i];
        //  Draws rectangle using 4 rounded coordinates
        rectangle(image, cv::Point(cvRound(r.x), cvRound(r.y)),
            cv::Point(cvRound(r.x + r.width - 1), cvRound(r.y + r.height - 1)),
           cv::Scalar(0, 255, 255), thickness);
    }
}

cv::Mat HaarModel::process(cv::Mat frame) {
    //  Checks if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    //  Creates a clone of an input image
    cv::Mat image = frame.clone();
    //  Tickmeter measures passed time
    cv::TickMeter tm;
    //  Tickmeter starts
    tm.start();
    //  Detects selected object in the input image
    detect(image, faces);
    //  Number of founded faces resides in rows of matrix faces. _totalFaceScore adds that number to itself
    _totalFaceScore += faces.size();
    //  Counter of processed frames increments
    _processedFrames++;
    //  Tickmeter stops
    tm.stop();
    //  _totalTime sums to itself number of milliseconds spent on each frame
    _totalTime += tm.getTimeMilli();
    drawRectangles(image, faces);
    //  Function draws rectangles around faces, tickmeter receives fps value
    visualize(image, tm.getFPS(), "Haar Cascades", _processedFrames, _totalFaceScore, _totalTime);
    //  Returns processed image
	return image;
}