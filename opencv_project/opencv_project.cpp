#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "controller/controller.h"
#include "view/view.h"
#include "view/view_src.h"
#include "data/data_factory.h"
#include "model/model.h"
#include "model/model_factory.h"
#include "model/face_detection_model.h"
#include "header/key_processing.h"

int main(){

	//create controller object
	Controller controller;

	//creates data object
	DataFactory data;

	//creates model object
	ModelFactory model;

	//creates window
	ViewSrc windFirst("Test_window1", cv::WINDOW_AUTOSIZE);

	//creates window2
	ViewSrc windSecond("Test_window2", cv::WINDOW_AUTOSIZE);

	windSecond.setTrackbar("par1", controller.getPar1());
	windSecond.setTrackbar("par2", controller.getPar2());

	//sends img to controller
	controller.setData(data.getData(DataFactory::TypeData::TypeDataPhoto));

	//sends video to controller
	controller.setData(data.getData(DataFactory::TypeData::TypeDataVideo));

	//sends window1 to controller
	controller.setView1(&windFirst);
	
	//sends window2 to controller
	controller.setView2(&windSecond);

	controller.setModel(model.getModel(ModelFactory::TypeModel::TypeGrayModel));	
	
	while (true) {
		keyProcess(controller, data, model, windSecond);
		controller.work();
	}
}
