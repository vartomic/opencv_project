#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"

class DNNModel : public Model {

	public:
		//	Path to the model
		std::string fdModelPath = "./onnx/face_detection_yunet_2023mar.onnx";
		//	Filters out faces of score that smaller than score_threshold
		float scoreThreshold = 0.9;
		//	Suppresses bounding boxes that greater or equal nmsThreshold
		float nmsThreshold = 0.3;
		//	Keeps top_k bounding boxes before NMS
		int topK = 5000;
		//	Face detector initialiser
		cv::Ptr<cv::FaceDetectorYN> detector;

		//	Constructor
		DNNModel() {
			//	Creates an instance of face detector with given parameters
			detector = cv::FaceDetectorYN::create(fdModelPath, "", cv::Size(320, 320), scoreThreshold, nmsThreshold, topK);
		}
		//	Function visualizes faces
		void visualize(cv::Mat& image, int frame, cv::Mat& faces, double fps, int thickness = 2);
		//
		cv::Mat process(cv::Mat frame);
};