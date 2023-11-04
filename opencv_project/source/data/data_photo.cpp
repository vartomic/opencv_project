#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

#include "data/data.h"
#include "data/data_photo.h"
#include "view/view.h"

cv::Mat DataPhoto::getData() {
	//Read img
	static cv::Mat img = cv::imread("img/faces/1.jpg");
	return img;
}

cv::Mat DataPhoto::nextImage() {
	cv::String arr[] = { "img/faces/1.jpg", "img/faces/2.jpg", "img/faces/3.jpg", "img/faces/4.jpg" };

	_curImageIndex = arr[0];

	//Read img
	static cv::Mat img = cv::imread(_curImageIndex);

	//check if not img
	if (!img.data)
	{
		std::cout << "Image is missing" << std::endl;
		return cv::Mat();
	}

	_curImageIndex = arr[+1];
}