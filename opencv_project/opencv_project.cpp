#include "controller/controller.h"
#include "view/view_src.h"
#include "data/data_factory.h"
#include "model/model_factory.h"
#include "header/key_processing.h"

int main(){
	// Access the Controller instance
	Controller& controller = Controller::getInstance();
	//	Data object
	DataFactory data;
	//	Model object
	ModelFactory model;
	//	ViewSrc object creates new window
	ViewSrc window1("Test_window1", cv::WINDOW_AUTOSIZE);
	//	ViewSrc object creates new window
	ViewSrc window2("Test_window2", cv::WINDOW_AUTOSIZE);
	//	Sends videoimage to controller
	controller.setData(data.getData(DataFactory::TypeData::TypeDataVideo));
	//	Sends window1 to controller
	controller.setView1(&window1);
	//	Sends window2 to controller
	controller.setView2(&window2);
	//	Model class calls haar model from enum type and Controller class sets this model to its local variable
	controller.setModel(model.getModel(ModelFactory::TypeModel::TypeDNNModel));
	//	Endless loop
	while (true) {
		//	Calls function keyProcess for chosing datatype and modeltype.
		// Input parameters = objects of Controller, Data, Model and ViewSrc classes
		keyProcess(controller, data, model, window1);
		//	Controller class calls function work()
		controller.work();
	}
}
