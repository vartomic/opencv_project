#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class FaceDetectModel : public Model {

	public:
		std::string fd_modelPath = "C:/Users/Arina/Desktop/visual_studio/cpp_projects/opencv_project/opencv_project/onnx";
		float scoreThreshold = 0.9;
		float nmsThreshold = 0.3;
		int topK = 5000;

		FaceDetectModel() {
			cv::FaceDetectorYN::create(fd_modelPath, "", cv::Size(320, 320), scoreThreshold, nmsThreshold, topK);
		}

		void visualize(cv::Mat& input, int frame, cv::Mat& faces, double fps, int thickness = 2);
};