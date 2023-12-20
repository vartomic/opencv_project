#include <filesystem>
#include "data/data_photo.h"

namespace fs = std::filesystem;

void DataPhoto::setFlag(bool ready) {
	_ready = ready;
}

bool DataPhoto::getFlag() {
	return _ready;
}

cv::Mat DataPhoto::getData() {
	if (getFlag() == false) {
		return cv::Mat();
	}
	else {
		setFlag(false);
		return _imageFrame;
	}
}

void DataPhoto::nextImage() {
	//	Path to images
	const std::string IMG_PATH = "img/faces/";
	//	Vector for images
	std::vector<cv::String> vectorOfimg;
	//	fs::path represents paths on a filesystem
	//	directory_iterator iterates over the elements of a directory (but does not visit the subdirectories)
	for (const fs::path& p : fs::directory_iterator(IMG_PATH)) {
		if (fs::is_regular_file(p)) {
			//	File paths are being converted in string and placed in a vector
			vectorOfimg.push_back(p.string());
		}
	}
	//	Reads img
	_imageFrame = cv::imread(vectorOfimg[_curImageIndex]);
	//	If not data
	if (!_imageFrame.data) {
		std::cout << "Image is missing" << std::endl;
	}
	setFlag(true);
	//	Index increases on 1
	_curImageIndex++;
	//	If current index of array greater than size of array current index equalizes to 0
	if (_curImageIndex >= vectorOfimg.size()) {
		_curImageIndex = 0;
	}
}