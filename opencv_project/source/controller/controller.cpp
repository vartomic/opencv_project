#include <opencv2/opencv.hpp>
#include "controller\controller.h"

//	Pointer to instance of the controller = nullptr
Controller* Controller::controllerInstance = 0;

Controller& Controller::getInstance() {
	//	If instance of controller does not exist
	if (!controllerInstance) {
		//	Allocate memory for new controller instance
		controllerInstance = new Controller();
	}
	//	Returns pointer to new controller instance
	return *controllerInstance;
}

void Controller::setData(Data* data) {
	_data = data;
	_newData = true;
}

void Controller::setView1(ViewSrc* view1) {
	_controllerView1 = view1;
}

void Controller::setView2(ViewSrc* view2) {
	_controllerView2 = view2;
}

void Controller::setModel(Model* model) {
	_model = model;
	_newModel = true;
}

bool Controller::getDataFlag() {
	return _newData;
}

void Controller::work() {
	//	If data or model is not 0
	if (_data == 0 || _model == 0) {
		exit(0);
	}
	//
	if (_newData == true || _newModel == true) {
		//
		_model->reset();
		_newData = false;
		_newModel = false;
	}
	cv::Mat frame;
	// Pointer to Data object of Controller class calls getData function. getData() returns image
	frame = _data->getData();
	cv::Mat frameFromModel;
	//	Pointer to Model object of Controller class calls process function. 
	// process() function process the model according to chosen model type
	frameFromModel = _model->process(frame);
	//	Pointer to model instance calls function sendArray, which returns vector of string. Then vector assigned to variable frameText.
	auto frameText = _model->sendArray();
	//	If view is not 0
	if (_controllerView1 != 0)
		//	Pointer to ViewSrc object of Controller class calls showFrame function with input image parameter.
		//  Function showFrame returns image with window frame
		_controllerView1->showFrame(frame);	
	//	If view is not 0
	if (_controllerView2 != 0) {
		//	Pointer to ViewSrc object of Controller class calls getFrameText function with vector as input parameter.
		//  Function getFrameText assigns vector of tring from Model class to Controller class.
		_controllerView2->getFrameText(frameText);
		//	Pointer to ViewSrc object of Controller class calls showFrame function with input image parameter.
		//  Function showFrame returns image with window frame
		_controllerView2->showFrame(frameFromModel);
	}
}