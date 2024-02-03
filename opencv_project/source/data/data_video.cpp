#include <filesystem>
#include "data/data_video.h"

namespace fs = std::filesystem;

cv::Mat DataVideo::getData() {
	cv::Mat frame;
	// Read the current frame
	_videoFrame.read(frame);
	return frame;
}

void DataVideo::nextVideo() {
	//	Path to videos
	const std::string VID_PATH = "vid/faces/";
	//	Vector for videos
	std::vector<cv::String> vectorOfVideo;
	//	fs::path represents paths on a filesystem
	//	directory_iterator iterates over the elements of a directory (but does not visit the subdirectories)
	for (const fs::path& p : fs::directory_iterator(VID_PATH)) {
		if (fs::is_regular_file(p)) {
			if (p.extension() == ".avi") {
				//	File paths are being converted in string and placed in a vector
				vectorOfVideo.push_back(p.string());
			}
		}	
	}
	//	Opens videofile
	_videoFrame.open(vectorOfVideo[_curVideoIndex]);
	//	Checks if not video
	if (!_videoFrame.isOpened()) {
		std::cout << "Video is missing" << std::endl;
	}
	//	Index increases on 1
	_curVideoIndex++;
	//	If current index of array greater than size of array current index equalizes to 0
	if (_curVideoIndex >= vectorOfVideo.size()) {
		_curVideoIndex = 0;
	}
}