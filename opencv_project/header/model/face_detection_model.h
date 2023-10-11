#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class FaceDetectModel : public Model {

	public:
		static void visualize(cv::Mat& input, int frame, cv::Mat& faces, double fps, int thickness = 2);
};