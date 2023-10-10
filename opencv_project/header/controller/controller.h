#pragma once

#include "data\data.h"
#include "data\data_factory.h"
#include "data\data_photo.h"
#include "data\data_video.h"
#include "view/view.h"
#include "view/view_src.h"
#include "model/model.h"
#include "model/gray_model.h"
#include "model/canny_model.h"
#include "model/hsv_model.h"

class Controller {

private:
	
	Data* _data = 0;

	//window object
	ViewSrc* _controllerView1 = 0;

	ViewSrc* _controllerView2 = 0;

	Model* _model = 0;

	int* trackbar;

	int _par1 = 0;
	int _par2 = 0;

public:

	Controller() {}
	
	//controller gets window
	void setView1(ViewSrc* view1);

	void setView2(ViewSrc* view2);

	void setData(Data* data);

	void setModel(Model* _model);

	int* getPar1();
	int* getPar2();

	//controller starts
	void work();

};
