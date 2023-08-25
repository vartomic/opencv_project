#include "controller\controller.h"

//controller gets image
void Controller::setData(Data* data) {
	_data = data;
}

//controller gets window
void Controller::setView1(ViewSrc* view1) {
	_controllerView1 = view1;
}

void Controller::setView2(ViewSrc* view2) {
	_controllerView2 = view2;
}

void Controller::setModel(Model* grayModel) {
	_model = grayModel;
}

void Controller::work() {

	cv::Mat frame;

	//check if data is 0
	if (_data != 0)
		//gets model
		frame = _data->getData();

	//controller gets window
	if (_controllerView1 != 0)
		_controllerView1->showFrame(frame);

	cv::Mat frameFromModel;

	if (_model != 0)
		//model to gray
		frameFromModel = _model->process(frame);

	if (_controllerView2 != 0)
		//gets frame in window
		_controllerView2->showFrame(frameFromModel);
}