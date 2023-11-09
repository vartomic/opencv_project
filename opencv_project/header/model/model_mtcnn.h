#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"
#include <mtcnn/detector.h>

class MTCNNModel: public Model {
	//	Declaration of new mtcnn detector
	MTCNNDetector *detector;
	//	Path to the model
	cv::String modelDir = "./mtcnn/data/models/";

public:
	//	Constructor
	MTCNNModel() {
		//
		ProposalNetwork::Config pConfig;
		//
		pConfig.caffeModel = modelDir + "det1.caffemodel";
		//
		pConfig.protoText = modelDir + "det1.prototxt";
		//
		pConfig.threshold = 0.6f;
		//
		RefineNetwork::Config rConfig;
		//
		rConfig.caffeModel = modelDir + "det2.caffemodel";
		//
		rConfig.protoText = modelDir + "det2.prototxt";
		//
		rConfig.threshold = 0.7f;
		//
		OutputNetwork::Config oConfig;
		//
		oConfig.caffeModel = modelDir + "det3.caffemodel";
		//
		oConfig.protoText = modelDir + "det3.prototxt";
		//
		oConfig.threshold = 0.7f;
		//	Allocates memory for new detector
		detector = new MTCNNDetector(pConfig, rConfig, oConfig);
	}
	//	Destructor
	~MTCNNModel() {};
	//	Finds all faces, receives a rectangle froom each face and draws rectangle around face
	void visualize(cv::Mat& image, std::vector<Face>& faces, double fps, int thickness = 2);
	//	Function starts tickmeter, creates clone of an input image, calls the detector for finding faces in input image,
	//	calls visualizing function for drawing rectangles around founded face
	cv::Mat process(cv::Mat frame);
};
