#pragma once
#include "model/model_dnn.h"
#include "model/model_haar.h"
#include "model/model_mtcnn.h"
#include "model/model_dlib.h"

class ModelFactory {

public:
	//	Enum with types of models
	enum class TypeModel { TypeDNNModel, TypeHaarModel, TypeMTCNNModel, TypeDlibModel };
	//	Function returns pointer to type of model, that object of ModelFactory class calls from main function
	Model* getModel(enum TypeModel type);
};
