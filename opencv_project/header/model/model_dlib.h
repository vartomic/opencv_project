#pragma once
#include <opencv2/opencv.hpp>
#include <dlib/image_processing/frontal_face_detector.h>

class DlibModel {

public:
	// Load face detection and pose estimation models.
	dlib::frontal_face_detector detector;

	DlibModel() {
		//
		detector = dlib::get_frontal_face_detector();
	}

	void visualize(cv::Mat& image);

	cv::Mat process(cv::Mat frame);
};