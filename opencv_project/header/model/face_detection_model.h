#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class FaceDetectModel : public Model {

	public:
		void visualize(Mat& input, int frame, Mat& faces, double fps, int thickness = 2);
};