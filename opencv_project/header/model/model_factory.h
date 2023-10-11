#pragma once

#include "model/model.h"
#include "model/gray_model.h"
#include "model/canny_model.h"
#include "model/hsv_model.h"

//enum with types of models
enum class TypeModel { TypeGrayModel, TypeCannyModel, TypeHSVModel };

//func for getting specific type of model
Model* getModel(enum TypeModel type);