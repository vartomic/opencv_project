#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "controller\controller.h"

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
int* Controller::getPar1() {
	return &_par1;
}
int* Controller::getPar2() {
	return &_par2;
}
int* Controller::getPar3() {
	return &_par3;
}
void Controller::work() {
	cv::Mat frame;
	//	If data is not 0
	if (_data != 0)
		// Pointer to Data object of Controller class calls getData function. getData() returns image
		frame = _data->getData();
	//	If window frame is not 0
	if (_controllerView1 != 0)
		//	Pointer to ViewSrc object of Controller class calls showFrame function with input image parameter.
		//  Function showFrame(frame) returns image with window frame
		_controllerView1->showFrame(frame);
	cv::Mat frameFromModel;
	//	If model is not 0
	if (_model != 0) {
		//	Pointer to Model object of Controller class calls setParams function. 
		// setParams() sends Controller class value of slider to Model class, Model class assignes them to itself
		// and Controller class returns links of that values back.
		_model->setParams(_par1, _par2, _par3);
		//	Pointer to Model object of Controller class calls process function. 
		// process() function process the model according to chosen model type
		frameFromModel = _model->process(frame);
	}
	//	If view is not 0
	if (_controllerView2 != 0)
		//	Pointer to ViewSrc object of Controller class calls showFrame function with input image parameter.
		//  Function showFrame(frame) returns image with window frame
		_controllerView2->showFrame(frameFromModel);
}