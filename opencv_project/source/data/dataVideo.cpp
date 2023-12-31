#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/videoio.hpp>

#include "data/dataVideo.h"
#include "data/data.h"

cv::Mat DataVideo::getData() {

	cv::Mat frame;

	//init videocamera
	cv::VideoCapture cap(0);

	//check if not video
	if (!cap.read(frame)) {
		std::cout << "Video is missing" << std::endl;
		return cv::Mat();
	}
	return frame;
}