#pragma once

#include "model/model.h"
#include "model/gray_model.h"
#include "model/canny_model.h"
#include "model/hsv_model.h"

enum class TypeModel { TypeGrayModel, TypeCannyModel, TypeHSVModel };

Model* getModel(enum TypeModel type);