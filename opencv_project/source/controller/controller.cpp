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
}

void Controller::setView1(ViewSrc* view1) {
	_controllerView1 = view1;
}

void Controller::setView2(ViewSrc* view2) {
	_controllerView2 = view2;
}

void Controller::setModel(Model* model) {
	_model = model;
}

void Controller::work() {
	//	If data or model is not 0
	if (_data == 0 || _model == 0) {
		exit(0);
	}
	//	If data changes
	if (_data->getFlag() == true) {
		//	Resets counter of faces, total amount of ellapsed time and counter of proccesed frames in the model
		_model->reset();
	}
	cv::Mat frame;
	// Pointer to Data object of Controller class calls getData function. getData() returns image
	frame = _data->getData();
	cv::Mat frameFromModel;
	//	Pointer to Model object of Controller class calls process function. 
	// process() function process the model according to chosen model type
	frameFromModel = _model->process(frame);
	//	If view is not 0
	if (_controllerView1 != 0)
		//	Pointer to ViewSrc object of Controller class calls showFrame function with input image parameter.
		//  Function showFrame(frame) returns image with window frame
		_controllerView1->showFrame(frame);	
	//	If view is not 0
	if (_controllerView2 != 0)
		//	Pointer to ViewSrc object of Controller class calls showFrame function with input image parameter.
		//  Function showFrame(frame) returns image with window frame
		_controllerView2->showFrame(frameFromModel);
}