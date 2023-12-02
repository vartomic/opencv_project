#include "model/model.h"

cv::Mat Model::process(cv::Mat frame) {


	return frame;
}

void Model::setParams(int par1, int par2, int par3) {
	_par1 = par1;
	_par2 = par2;
	_par3 = par3;
}
void Model::reset() {
	_totalTime = 0.0;
	_frameNum =_faceScore = 0;
}