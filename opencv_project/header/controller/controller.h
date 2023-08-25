#pragma once

#include "data\data.h"
#include "data\dataPhoto.h"
#include "data\dataVideo.h"
#include "view/view.h"
#include "view/viewSrc.h"
#include "model/model.h"
#include "model/grayModel.h"

class Controller {

private:
	
	Data* _data = 0;

	//window object
	ViewSrc* _controllerView1 = 0;

	ViewSrc* _controllerView2 = 0;

	Model* _model = 0;

public:

	Controller() {}
	
	//controller gets window
	void setView1(ViewSrc* view1);

	void setView2(ViewSrc* view2);

	void setData(Data* data);

	void setModel(Model* _model);

	//controller starts
	void work();

};
