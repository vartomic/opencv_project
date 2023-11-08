#pragma once
#include "controller/controller.h"
#include "data/data_factory.h"
#include "model/model_factory.h"
#include "view/view_src.h"

//	Function returns datatype and modeltype due to pressed key. 
// Arguments of function are links to Controller, DataFactory, ModelFactory, ViewSrc objects
void keyProcess(Controller &refController, DataFactory &data, ModelFactory& model, ViewSrc &windSecond);