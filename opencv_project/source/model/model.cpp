#include "model/model.h"

void Model::setParams(int par1, int par2, int par3) {
	_par1 = par1;
	_par2 = par2;
	_par3 = par3;
}
void Model::reset() {
	_totalTime = 0.0;
	_processedFrames = 0;
	_totalFaceScore = 0;
}

void Model::visualize(cv::Mat& image, double fps, std::string modelName, int processedFrames, int totalFaceScore, double timeElapsed, int thickness) {
    //  Text string with fps value formatted from double to float
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //  Receives the width of input image
    int width = image.size().width;
    //  Receives the height of input image
    int height = image.size().height;
    //  Text string with width and height of input image
    std::string resolutionString = cv::format("Resolution : %d x %d", width, height);
    //  Text string with number of processed frames
    std::string processedFramesString = cv::format("Processed frames : %d", processedFrames);
    //  Text string with total number of founded faces
    std::string faceScoreString = cv::format("Total score of faces: %d", totalFaceScore);
    //  Text string with total elapsed time
    std::string timeElapsedString = cv::format("Time elapsed: %.2f ms", timeElapsed);
    //  Function draws the text string with the name of the model
    putText(image, "Model : " + modelName, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(255, 0, 0), thickness);
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