#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class HaarModel : public Model {

	public:

		cv::CascadeClassifier cascade, nestedCascade;

		//добавить переключение каскадов

		//cascade path name
		std::string cascadeName = "./haarcascades/haarcascade_frontalface_alt.xml";
		//nested cascade path name
		std::string nestedCascadeName = "./haarcascades/haarcascade_eye_tree_eyeglasses.xml";
		//
		double scale = 1;
		//
		bool tryflip = true;
		//constructor
		HaarModel() {
			if (!cascade.load(cascadeName))
			{
				std::cerr << "ERROR: Could not load classifier cascade" << std::endl;
			}
		}
		//visualize model
		void visualize(cv::Mat& img, cv::CascadeClassifier& cascade, cv::CascadeClassifier& nestedCascade,
			double scale, bool tryflip);

		cv::Mat process(cv::Mat frame);
};