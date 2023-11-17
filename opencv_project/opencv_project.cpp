#include "controller/controller.h"
#include "view/view_src.h"
#include "data/data_factory.h"
#include "model/model_factory.h"
#include "header/key_processing.h"

int main(){
	//	Controller object
	Controller controller;
	//	Data object
	DataFactory data;
	//	Model object
	ModelFactory model;
	//	ViewSrc object creates new window
	ViewSrc windFirst("Test_window1", cv::WINDOW_AUTOSIZE);
	//	ViewSrc object creates new window
	ViewSrc windSecond("Test_window2", cv::WINDOW_AUTOSIZE);
	//	Controller object calls function getPar1(). 
	// Model class sets values of slider current position from Controller class and Controller class returns link to slider values.
	//	VieSrc object calls function setTrackbar(), with trackbar name and value of slider to create trackbar.
	windSecond.setTrackbar("par1", controller.getPar1());
	// Model class sets values of slider current position from Controller class and Controller class returns link to slider values.
	//	VieSrc object calls function setTrackbar(), with trackbar name and value of slider to create trackbar.
	windSecond.setTrackbar("par2", controller.getPar2());
	//	VieSrc object calls function setTrackbar(), with trackbar name and value of slider to create trackbar.
	windSecond.setTrackbar("par3", controller.getPar3());
	//	Sends videoimage to controller
	controller.setData(data.getData(DataFactory::TypeData::TypeDataCamera));
	//	Sends window1 to controller
	controller.setView1(&windFirst);
	//	Sends window2 to controller
	controller.setView2(&windSecond);
	//	Model class calls haar model from enum type and Controller class sets this model to its local variable
	controller.setModel(model.getModel(ModelFactory::TypeModel::TypeMTCNNModel));
	//	Endless loop
	while (true) {
		//	Calls function keyProcess for chosing datatype and modeltype.
		// Input parameters = objects of Controller, Data, Model and ViewSrc classes
		keyProcess(controller, data, model, windSecond);
		//	Controller class calls function work()
		controller.work();
	}
}
