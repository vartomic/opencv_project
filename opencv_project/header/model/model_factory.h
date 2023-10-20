#pragma once

#include "model/model.h"
#include "model/gray_model.h"
#include "model/canny_model.h"
#include "model/hsv_model.h"
#include "model/dnn_model.h"
#include "model/haar_model.h"


class ModelFactory {

public:
	//enum with types of models
	enum class TypeModel { TypeGrayModel, TypeCannyModel, TypeHSVModel, TypeDNNModel, TypeHaarModel };

	//func for getting specific type of model
	Model* getModel(enum TypeModel type);
};
