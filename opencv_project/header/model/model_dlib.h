#pragma once
#include <opencv2/opencv.hpp>
#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>

class DlibModel {

public:
	// Load face detection and pose estimation models.
	dlib::frontal_face_detector detector;
	//
	std::vector<dlib::rectangle> faces;
	//
	DlibModel() {
		//
		detector = dlib::get_frontal_face_detector();
	}
	//
	void visualize(cv::Mat& image, int frame, std::vector<dlib::rectangle>& faces, double fps, int thickness = 2);
	//
	cv::Mat process(cv::Mat frame);

};