#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "data/data_photo.h"

namespace fs = std::filesystem;

cv::Mat DataPhoto::getData() {
	return _img;
void DataPhoto::nextImage() {
	//	Path to images
	std::string imgPath = "img/faces/";
	//	Vector for images
	std::vector<cv::String> VEC_IMAGES;
	//	fs::path represents paths on a filesystem
	//	directory_iterator iterates over the elements of a directory (but does not visit the subdirectories)
	for (const fs::path& p : fs::directory_iterator(imgPath)) {
		//	File paths are being converted in string and placed in a vector
		VEC_IMAGES.push_back(p.string());
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