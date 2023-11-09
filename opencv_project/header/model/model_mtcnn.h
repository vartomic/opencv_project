#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "model/model.h"
#include <mtcnn/detector.h>

class MTCNNModel: public Model {
	//
	MTCNNDetector *detector;
	//
	cv::String modelDir = "./mtcnn/data/models/";

public:
	MTCNNModel() {
		ProposalNetwork::Config pConfig;
		pConfig.caffeModel = modelDir + "det1.caffemodel";
		pConfig.protoText = modelDir + "det1.prototxt";

		RefineNetwork::Config rConfig;
		rConfig.caffeModel = modelDir + "det2.caffemodel";
		rConfig.protoText = modelDir + "det2.prototxt";

		OutputNetwork::Config oConfig;
		oConfig.caffeModel = modelDir + "det3.caffemodel";
		oConfig.protoText = modelDir + "det3.prototxt";

		detector = new MTCNNDetector(pConfig, rConfig, oConfig);
	}
	//	Destructor
	~MTCNNModel() {};
	//
	void visualize(cv::Mat& image, std::vector<Face>& faces);
	//
	cv::Mat process(cv::Mat frame);
};
