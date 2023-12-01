#pragma once
#include <opencv2/opencv.hpp>
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
		//  Draws bounding box around founded face, landmarks on the eyes, tip of a nose and corners of the mouth by 4 coordinates,
		// renders text with fps value in the input image
		void visualize(cv::Mat& image, cv::Mat& faces, double fps, int thickness = 2);
		//	Function starts tickmeter, creates clone of an input image, calls the detector for resizing and finding faces in input image,
		//	calls visualizing function for drawing rectangles and landmarks on the founded face
		cv::Mat process(cv::Mat frame);
};