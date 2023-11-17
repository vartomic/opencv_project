#include "data/data_camera.h"

cv::Mat DataCamera::getData() {
	cv::Mat frame;
	//	Initializes webcamera
	static cv::VideoCapture cap(0);
	//	If not video
	if (!cap.read(frame)) {
		std::cout << "Video is missing" << std::endl;
		//return empty frame
		return cv::Mat();
	}
	return frame;
}