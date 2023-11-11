#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "data/data_photo.h"

namespace fs = std::filesystem;

cv::Mat DataPhoto::getData() {
	return _img;
}
void DataPhoto::nextImage() {
	//	Path to images
	std::string imgPath = "img/faces/";

	std::vector<cv::String> VEC_IMAGES;
	
	for (const fs::path& p : fs::directory_iterator(imgPath)) {
		VEC_IMAGES.push_back(p.u8string());
	}
	//	Reads img
	_img = cv::imread(VEC_IMAGES[_curImageIndex]);
	//	If not data
	if (!_img.data) {
		std::cout << "Image is missing" << std::endl;
	}
	//	Index increases on 1
	_curImageIndex++;

	//	If current index of array greater than size of array current index equalizes to 0
	if (_curImageIndex >= VEC_IMAGES.size()) {
		_curImageIndex = 0;
	}
}