#include "model/model.h"

void Model::reset() {
	_totalTime = 0.0;
	_processedFrames = 0;
	_totalFaceScore = 0;
}

std::vector<std::string> Model::sendArray() {
    return _frameText;
}

void Model::visualize(cv::Mat& image, double fps, std::string modelName, int processedFrames, int totalFaceScore, double timeElapsed, int thickness) {
    //  Text string with fps value formatted from double to float
    std::string fpsStr = cv::format("FPS : %.2f", (float)fps);
    //  Receives the width of input image
    int width = image.size().width;
    //  Receives the height of input image
    int height = image.size().height;
    //  Text string with width and height of input image
    std::string resolutionStr = cv::format("Resolution : %d x %d", width, height);
    //  Text string with number of processed frames
    std::string processedFramesStr = cv::format("Processed frames : %d", processedFrames);
    //  Text string with total number of founded faces
    std::string faceScoreStr = cv::format("Total score of faces: %d", totalFaceScore);
    //  Text string with total elapsed time
    std::string timeElapsedStr = cv::format("Time elapsed: %.2f ms", timeElapsed);

    _frameText.push_back(fpsStr);
    _frameText.push_back(resolutionStr);
    _frameText.push_back(processedFramesStr);
    _frameText.push_back(faceScoreStr);
    _frameText.push_back(timeElapsedStr);




    

    ////  Function draws the text string with the name of the model
    //putText(image, "Model : " + modelName, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 0), thickness, cv::LINE_AA);
    //putText(image, "Model : " + modelName, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    ////  Function draws the text string with fps value in the image
    //putText(image, fpsString, cv::Point(0, 35), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 0), thickness, cv::LINE_AA);
    //putText(image, fpsString, cv::Point(0, 35), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    ////  Function draws the text string with resolution of input image on the image
    //putText(image, resolutionString, cv::Point(0, 55), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 0), thickness, cv::LINE_AA);
    //putText(image, resolutionString, cv::Point(0, 55), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    ////  Function draws the text string with total elapsed time
    //putText(image, timeElapsedString, cv::Point(0, 75), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 0), thickness, cv::LINE_AA);
    //putText(image, timeElapsedString, cv::Point(0, 75), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    ////  Function draws the text string with number of processed frames
    //putText(image, processedFramesString, cv::Point(0, 95), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 0), thickness, cv::LINE_AA);
    //putText(image, processedFramesString, cv::Point(0, 95), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
    ////  Function draws the text string with total number of founded faces
    //putText(image, faceScoreString, cv::Point(0, 115), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 0), thickness, cv::LINE_AA);
    //putText(image, faceScoreString, cv::Point(0, 115), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), 1, cv::LINE_AA);
}