             #include "model/model_dnn.h"

void DNNModel::drawRectangles(cv::Mat & image, cv::Mat & faces, int thickness){  
    //  For i = 0 to the last row of faces
    for (int i = 0; i < faces.rows; i++) {
        //  Draws bounding box by the 4 coordinates of a face
        rectangle(image, cv::Rect2i(int(faces.at<float>(i, 0)), int(faces.at<float>(i, 1)), int(faces.at<float>(i, 2)), int(faces.at<float>(i, 3))), cv::Scalar(0, 255, 0), thickness);
    }
}

cv::Mat DNNModel::process(cv::Mat frame) {
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
    //  Sets input size before inference
    detector->setInputSize(image.size());
    cv::Mat faces;
    //  Detects faces in the input image
    detector->detect(image, faces);
    //  Number of founded faces resides in rows of matrix faces. _totalFaceScore adds that number to itself
    _totalFaceScore += faces.rows;
    //  Counter of processed frames increments
    _processedFrames++;
    //  Tickmeter stops
    tm.stop();
    //  _totalTime sums to itself number of milliseconds spent on each frame
    _totalTime += tm.getTimeMilli();
    //  Function draws rectangles around faces and landmarks on faces, tickmeter receives fps value
    drawRectangles(image, faces);
    //	Renders text with fps value, number of processed frames, number of founded faces and ellapsed time in the input image  
    visualize(image, tm.getFPS(), "DNN", _processedFrames, _totalFaceScore, _totalTime);
    //  Returns processed image
    return image;
}