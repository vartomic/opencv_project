#pragma once
#include <opencv2/opencv.hpp>
#include "model/model.h"
#include "../../lib_mtcnn/include/mtcnn/detector.h"

class MTCNNModel: public Model {
	//	Declaration of new mtcnn detector
	MTCNNDetector *detector;
	//	Path to the model
	cv::String modelDir = "./mtcnn/data/models/";

public:
	//	Constructor
	MTCNNModel() {
		ProposalNetwork::Config pConfig;
		//	A caffeModel file is a machine learning model created by Caffe. 
		//	It contains an image classification or image segmentation model that has been trained using Caffe. 
		pConfig.caffeModel = modelDir + "det1.caffemodel";
		//	caffeModel files are created from .prototxt files.
		pConfig.protoText = modelDir + "det1.prototxt";
		pConfig.threshold = 0.6f;
		RefineNetwork::Config rConfig;
		rConfig.caffeModel = modelDir + "det2.caffemodel";
		rConfig.protoText = modelDir + "det2.prototxt";
		rConfig.threshold = 0.7f;
		OutputNetwork::Config oConfig;
		oConfig.caffeModel = modelDir + "det3.caffemodel";
		oConfig.protoText = modelDir + "det3.prototxt";
		oConfig.threshold = 0.7f;
		//	Allocates memory for new detector
		detector = new MTCNNDetector(pConfig, rConfig, oConfig);
	}
	//	Destructor
	~MTCNNModel() {};
	//	Receives a rectangle from each face and draws rectangle around face
	void visualize(cv::Mat& image, std::vector<Face>& faces, double fps, int thickness = 2);
	//	Function starts tickmeter, creates clone of an input image, calls the detector for finding faces in input image,
	//	calls visualizing function for drawing rectangles around founded face
	cv::Mat process(cv::Mat frame);
};
