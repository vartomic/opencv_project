#pragma once
#include <opencv2/opencv.hpp>

//	Basic class for DataPhoto, DataVideo and DataCamera classes. It's virtual function returns original frame. Function containt bool variable,
//	which derived classes are changing for their checking if they are receiving not empty frame
class Data {

protected:
	//	Img object
	cv::Mat _img;

public:
	// Virtual function returns image
	virtual cv::Mat getData() {
		return _img;
	}
};