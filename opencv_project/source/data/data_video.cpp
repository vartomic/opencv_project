#include <filesystem>
#include "data/data_video.h"

namespace fs = std::filesystem;

cv::Mat DataVideo::getData() {
	//	Checks the flag position and changes it
	_ready = true;
	cv::Mat frame;
	//	While video not ended  
	while (1) {
		// Read the current frame
		_ready = _video.read(frame);
		return frame;
	}
	//	returns empty frame
	return cv::Mat();
}
void DataVideo::nextVideo() {
	//	fs::path represents paths on a filesystem
	//	directory_iterator iterates over the elements of a directory (but does not visit the subdirectories)
	for (const fs::path& p : fs::directory_iterator(VID_PATH)) {
		if (fs::is_regular_file(p)) {
			if (p.string().find("avi") == std::string::npos) {
			//	//	File paths are being converted in string and placed in a vector
				std::cout << "Video isn't avi" << '\n';
			}
			else { 
				vecVid.push_back(p.string());
			}
			
		}
	}
	//	Opens videofile
	_video.open(vecVid[_curVideoIndex]);
	//	Checks if not video
	if (!_video.isOpened()) {
		std::cout << "Video is missing" << std::endl;
	}
	//	Index increases on 1
	_curVideoIndex++;
	//	If current index of array greater than size of array current index equalizes to 0
	if (_curVideoIndex >= vecVid.size()) {
		_curVideoIndex = 0;
	}
}