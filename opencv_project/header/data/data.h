#pragma once
#include <opencv2/opencv.hpp>
//	Basic class for FataPhoto, DataVideo and FataCamera classes. It's virtual function returns original frame. Function containt bool variable,
//	which derived classes are changing for their checking if they are receiving not empty frame
class Data {

protected:
	//	Img object
	cv::Mat _img;
	//
	bool _ready;

public:
	// Virtual function returns image
	virtual cv::Mat getData() {
		return _img;
	}
	// sets inner class variable _ready in flag position from derived class dataPhoto
	void setFlag(bool ready);
	//	returns flag position
	bool getFlag();
};