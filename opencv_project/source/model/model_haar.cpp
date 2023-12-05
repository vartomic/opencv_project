#include "model/model_haar.h"

void HaarModel::detect(cv::Mat& image, std::vector<cv::Rect>& faces) {
    cv::Mat gray;
    //  Converts image to gray color
    cvtColor(image, gray, cv::COLOR_BGR2GRAY);
    //  Equalizes the histogram of a grayscale image
    equalizeHist(gray, gray);
    //  Detects selected object in the input image with given paramteres = input image, vector of faces, scalefactor,
    //  min amount of neighbours, min and max size of object 
    cascade.detectMultiScale(gray, faces,
        1.1, 2, 0 | cv::CASCADE_SCALE_IMAGE, cv::Size(30, 30));
}
void HaarModel::visualize(cv::Mat& image, std::vector<cv::Rect>& faces, double fps, int processedFrames, int totalFaceScore, double timeElapsed, int thickness) {
    //  Text string with fps value formatted from double to float
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //  Receives the width of input image
    int width = image.size().width;
    //  Receives the height of input image
    int height = image.size().height;
    //  Text string with width and height of input image
    std::string resolutionString = cv::format("Resolution : %d x %d", width, height);
    //  Text string with the name of the model 
    std::string modelNameString = "Model: Haar Cascades";
    //  Text string with number of processed frames
    std::string processedFramesString = cv::format("Processed frames : %d", processedFrames);
    //  Text string with total number of founded faces
    std::string faceScoreString = cv::format("Total score of faces: %d", totalFaceScore);
    //  Text string with total elapsed time
    std::string timeElapsedString = cv::format("Time elapsed: %.2f ms", timeElapsed);
    //  Loop for all faces
    for (size_t i = 0; i < faces.size(); i++){
        //  2D rectangle
        cv::Rect r = faces[i];
        //  Draws rectangle using 4 rounded coordinates
        rectangle(image, cv::Point(cvRound(r.x), cvRound(r.y)),
            cv::Point(cvRound(r.x + r.width - 1), cvRound(r.y + r.height - 1)),
           cv::Scalar(0, 164, 213), thickness);
    }
    //  Function draws the text string with the name of the model
    putText(image, modelNameString, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(255, 0, 0), thickness);
    //  Function draws the text string with fps value in the image
    putText(image, fpsString, cv::Point(0, 35), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 255, 255), thickness);
    //  Function draws the text string with resolution of input image on the image
    putText(image, resolutionString, cv::Point(0, 55), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), thickness);
    //  Function draws the text string with total elapsed time
    putText(image, timeElapsedString, cv::Point(0, 75), cv::FONT_ITALIC, 0.5, cv::Scalar(146, 47, 76), thickness);
    //  Function draws the text string with number of processed frames
    putText(image, processedFramesString, cv::Point(0, 95), cv::FONT_ITALIC, 0.5, cv::Scalar(146, 47, 76), thickness);
    //  Function draws the text string with total number of founded faces
    putText(image, faceScoreString, cv::Point(0, 115), cv::FONT_ITALIC, 0.5, cv::Scalar(146, 47, 76), thickness);
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
    _processedFrames++;
    //  Tickmeter stops
    tm.stop();
    //  _totalTime sums to itself number of milliseconds spent on each frame
    _totalTime += tm.getTimeMilli();
    //  Function draws rectangles around faces, tickmeter receives fps value
    visualize(image, faces, tm.getFPS(), _processedFrames, _totalFaceScore, _totalTime);
    //  Returns processed image
	return image;
}