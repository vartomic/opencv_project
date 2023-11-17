#include "model/model_dlib.h"

void DlibModel::visualize(cv::Mat& image) {
    //  Text string with fps value formatted from double to float
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //  Receives the width of input image
    int width = image.size().width;
    //  Receives the height of input image
    int height = image.size().height;
    //  Text string with width and height of input image
    std::string resolutionString = cv::format("Resolution : %d x %d", width, height);
	// Detect faces 
	std::vector<dlib::rectangle> faces = detector(image);

	std::vector<dlib::full_object_detection> shapes;
	for (unsigned long i = 0; i < faces.size(); ++i)
		//shapes.push_back(image, faces[i]));//
}

cv::Mat process(cv::Mat frame) {
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
    
    //  Tickmeter stops
    tm.stop();

    //  Returns processed image
    return image;

}