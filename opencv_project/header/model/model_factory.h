#pragma once
#include "model/model.h"
#include "model/gray_model.h"
#include "model/canny_model.h"
#include "model/hsv_model.h"
#include "model/dnn_model.h"
#include "model/haar_model.h"
#include "model/mtcnn_model.h"

class ModelFactory {

public:
	//	Enum with types of models
	enum class TypeModel { TypeGrayModel, TypeCannyModel, TypeHSVModel, TypeDNNModel, TypeHaarModel, TypeMTCNNModel };
	//	Function returns pointer to type of model, that object of ModelFactory class calls from main function
	Model* getModel(enum TypeModel type);
};
