#pragma once

#include "data.h"
#include "data/data_photo.h"
#include "data/data_video.h"

enum class TypeData { TypeDataPhoto, TypeDataVideo };

Data* getData(enum TypeData type);