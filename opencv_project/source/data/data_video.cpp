#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>
#include "data/data_video.h"

cv::Mat DataVideo::getData() {
	cv::Mat frame;
	//	Initialises webcamera
	static cv::VideoCapture cap(0);
	//	If not video
	if (!cap.read(frame)) {
		std::cout << "Video is missing" << std::endl;
		//return empty frame
		return cv::Mat();
	}
	return frame;
}