#pragma once
#include "controller/controller.h"
#include "data/data_factory.h"
#include "model/model_factory.h"

//func for key processing, args = pointers to controller and second output window
void keyProcess(Controller &refController, DataFactory &data, ModelFactory& model, ViewSrc &windSecond);