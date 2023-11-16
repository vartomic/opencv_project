#include <filesystem>
#include "data/data_photo.h"

namespace fs = std::filesystem;

cv::Mat DataPhoto::getData() {
	if (ready = false) {
		return cv::Mat();
	}
	else {
		ready = false;
		return _img;
	}
}
void DataPhoto::nextImage() {
	//	Path to images
	const std::string IMG_PATH = "img/faces/";
	//	Vector for images
	std::vector<cv::String> vecImg;
	//	fs::path represents paths on a filesystem
	//	directory_iterator iterates over the elements of a directory (but does not visit the subdirectories)
	for (const fs::path& p : fs::directory_iterator(IMG_PATH)) {
		if (fs::is_regular_file(p)) {
			//	File paths are being converted in string and placed in a vector
			vecImg.push_back(p.string());
		}
	}
	//	Reads img
	_img = cv::imread(vecImg[_curImageIndex]);
	//	If not data
	if (!_img.data) {
		std::cout << "Image is missing" << std::endl;
	}
	//
	ready = true;
	//	Index increases on 1
	_curImageIndex++;
	//	If current index of array greater than size of array current index equalizes to 0
	if (_curImageIndex >= vecImg.size()) {
		_curImageIndex = 0;
	}
}