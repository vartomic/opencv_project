#pragma once
#include <opencv2/opencv.hpp>
#include <dlib/opencv.h>
#include <dlib/image_processing/frontal_face_detector.h>
#include "model/model.h"

class DlibModel: public Model {

public:
	// Load face detection and pose estimation models.
	dlib::frontal_face_detector detector;
	//	Vector for dlib rectangles
	std::vector<dlib::rectangle> faces;
	//	Constructor
	DlibModel() {
		//	Face detector
		detector = dlib::get_frontal_face_detector();
	}
	//	Draws rectangles around faces and puts on image resolution and fps properties of an image
	void drawRectangles(cv::Mat& image, std::vector<dlib::rectangle>& faces, int thickness = 2);
	//	Function detects faces and call visualize function for drawing rectangles around faces
	cv::Mat process(cv::Mat frame);
};