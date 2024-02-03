#pragma once
#include <opencv2/opencv.hpp>
#include "model/model.h"

class HaarModel : public Model {
	public:
		//	Cascade for searching item in image
		cv::CascadeClassifier cascade;
		//	Cascade path name
		std::string cascadeName = "./haarcascades/haarcascade_frontalface_alt2.xml";
		//	Vector for faces
		std::vector<cv::Rect> faces;
		//	Constructor
		HaarModel() {
			//	Checks for cascade path
			if (!cascade.load(cascadeName))
			{
				std::cerr << "ERROR: Could not load classifier cascade" << std::endl;
			}
		}
		//	Function converts image to gray color, equalizes the histogram of a grayscale image
		//  and detects selected object in the input image
		void detect(cv::Mat& image, std::vector<cv::Rect>& faces);
		//	Draws rectangle using 4 rounded coordinates
		void drawRectangles(cv::Mat& image, std::vector<cv::Rect>& faces, int thickness = 2);
		//	Function starts tickmeter, creates clone of an input image, calls the detector for finding faces in input image,
		//	calls visualizing function for drawing rectangles around founded face
		cv::Mat process(cv::Mat frame);
};