#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class HaarModel : public Model {
	public:
		//	Cascade for searching item in image
		cv::CascadeClassifier cascade;

		//добавить переключение каскадов

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
		//
		void detect(cv::Mat& image, std::vector<cv::Rect>& faces);
		//
		void visualize(cv::Mat& image, std::vector<cv::Rect>& faces, double fps);
		//main function in model, calls other functions
		cv::Mat process(cv::Mat frame);
};