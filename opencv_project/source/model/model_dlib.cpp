#include "model/model_dlib.h"

void DlibModel::drawRectangles(cv::Mat& image, std::vector<dlib::rectangle>& faces, int thickness) {
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
    //  Number of founded faces resides in rows of matrix faces. _totalFaceScore adds that number to itself
    _totalFaceScore += faces.size();
    //  Tickmeter stops
    tm.stop();    
    //  Counter of processed frames increments
    _processedFrames++;
    //  _totalTime sums to itself number of milliseconds spent on each frame
    _totalTime += tm.getTimeMilli();
    //  Function draws rectangles around faces and landmarks on faces, tickmeter receives fps value
    drawRectangles(image, faces);
    //	Renders text with fps value, number of processed frames, number of founded faces and ellapsed time in the input image  
    visualize(image, tm.getFPS(), "Dlib", _processedFrames, _totalFaceScore, _totalTime);
    //  Returns processed image
    return image;

}