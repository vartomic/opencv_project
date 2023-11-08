#pragma once
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "data/data.h"
#include "view/view.h"
#include "view/view_src.h"
#include "model/model.h"

class Controller {
	//	Pointer to photo or video data object
	Data* _data = 0;
	//	Pointer to window object
	ViewSrc* _controllerView1 = 0;
	//	Pointer to window object
	ViewSrc* _controllerView2 = 0;
	//	Pointer to model object
	Model* _model = 0;
	//	Pointer to trackbar
	int* _trackbar;
	//	Slider value in trackbar
	int _par1 = 0;
	//	Slider value in trackbar
	int _par2 = 0;

public:
	//	Empty constructor
	Controller() {}
	//	Function sets window object to controller. Input argument of function are pointer to view object from View class,
	//	controller assigns it to view object in controller class
	void setView1(ViewSrc* view1);
	//	Function sets window object to controller. Input argument of function are pointer to view object from View class,
	//	controller assigns it to view object in controller class
	void setView2(ViewSrc* view2);
	//	Function sets data object to controller. Input of function is pointer to data object from Data class, 
	//	controller assigns it to data object in controller class
	void setData(Data* data);
	//	Function sets model object to controller. Input of function is pointer to model object from Model class, 
	//	controller assigns it to model object in controller class
	void setModel(Model* model);
	//	Function returns link to slider parameter from Model class. Model class assigns slider its current value
	int* getPar1();
	//	Function returns link to slider parameter from Model class. Model class assigns slider its current value
	int* getPar2();
	//	Function gets datatype, modeltype, resize image for specified window, 
	// sets slider values of the trackbar and displays them inside the window
	void work();
};
