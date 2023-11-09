#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "data/data_photo.h"

cv::Mat DataPhoto::getData() {
	return _img;
}
void DataPhoto::nextImage() {
	//	Array of image paths
	const cv::String ARR_IMAGES[] = { "img/faces/1.jpg", "img/faces/2.jpg", "img/faces/3.jpg", "img/faces/4.jpg", "img/faces/5.jpg",
	"img/faces/6.jpg", "img/faces/7.jpg", "img/faces/8.jpg", "img/faces/9.jpg", "img/faces/10.jpg"};
	//	Reads img
	_img = cv::imread(ARR_IMAGES[_curImageIndex]);
	//	If not data
	if (!_img.data) {
		std::cout << "Image is missing" << std::endl;
	}
	//	Size of array
	const int ARR_SIZE = sizeof(ARR_IMAGES) / sizeof(ARR_IMAGES[0]);
	//	Index increases on 1
	_curImageIndex++;
	//	If current index of array greater than size of array current index equalizes to 0
	if (_curImageIndex >= ARR_SIZE) {
		_curImageIndex = 0;
	}
}