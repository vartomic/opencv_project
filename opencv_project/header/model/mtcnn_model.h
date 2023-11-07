#pragma once

#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include <boost/filesystem.hpp>
#include <boost/filesystem/path.hpp>
#include <boost/timer/timer.hpp>
#include "model/model.h"
#include <mtcnn/detector.h>

namespace fs = boost::filesystem;

class MTCNNModel: public Model {
	MTCNNDetector *detector;
	//fs::path modelDir = fs::path("./mtcnn/data/models/");

public:
	MTCNNModel() {
		/*ProposalNetwork::Config pConfig;
		pConfig.caffeModel = (modelDir / "det1.caffemodel").string();
		pConfig.protoText = (modelDir / "det1.prototxt").string();

		RefineNetwork::Config rConfig;
		rConfig.caffeModel = (modelDir / "det2.caffemodel").string();
		rConfig.protoText = (modelDir / "det2.prototxt").string();

		OutputNetwork::Config oConfig;
		oConfig.caffeModel = (modelDir / "det3.caffemodel").string();
		oConfig.protoText = (modelDir / "det3.prototxt").string();

		detector = new MTCNNDetector(pConfig, rConfig, oConfig);*/
	}
	cv::Mat process(cv::Mat frame);
};
