#include <filesystem>
#include "data/data_video.h"

namespace fs = std::filesystem;

cv::Mat DataVideo::getData() {
	//	Changes position of the flag
	setFlag(false);
	cv::Mat frame;
	while (!_videoFrame.read(frame)) {
		//
		frame = _videoFrame.set(cv::CAP_PROP_POS_FRAMES, 0);
	}
	// Read the current frame
	_videoFrame.read(frame);
	return frame;
}

void DataVideo::nextVideo() {
	//	Path to videos
	const std::string VID_PATH = "vid/faces/";
	//	Vector for videos
	std::vector<cv::String> vectorOfvideo;
	//	fs::path represents paths on a filesystem
	//	directory_iterator iterates over the elements of a directory (but does not visit the subdirectories)
	for (const fs::path& p : fs::directory_iterator(VID_PATH)) {
		if (fs::is_regular_file(p)) {
			if (p.extension() == ".avi") {
				//	File paths are being converted in string and placed in a vector
				vectorOfvideo.push_back(p.string());
			}
		}	
	}
	//	Opens videofile
	_videoFrame.open(vectorOfvideo[_curVideoIndex]);
	//	Checks if not video
	if (!_videoFrame.isOpened()) {
		std::cout << "Video is missing" << std::endl;
	}
	setFlag(true);
	//	Index increases on 1
	_curVideoIndex++;
	//	If current index of array greater than size of array current index equalizes to 0
	if (_curVideoIndex >= vectorOfvideo.size()) {
		_curVideoIndex = 0;
	}
}