#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class HaarModel : public Model {

	public:
		//
		cv::CascadeClassifier cascade;

		//добавить переключение каскадов

		//cascade path name
		std::string cascadeName = "./haarcascades/haarcascade_frontalface_alt.xml";
		//
		std::vector<cv::Rect> faces;
		//constructor
		HaarModel() {
			if (!cascade.load(cascadeName))
			{
				std::cerr << "ERROR: Could not load classifier cascade" << std::endl;
			}
		}
		//detect facess
		void detect(cv::Mat& image, std::vector<cv::Rect>& faces);
		//visualizes model
		void visualize(cv::Mat& image, std::vector<cv::Rect>& faces, double fps);
		cv::Mat process(cv::Mat frame);
};