#pragma once

#include "data.h"
#include "data/data_photo.h"
#include "data/data_video.h"

//enum with datatypes
enum class TypeData { TypeDataPhoto, TypeDataVideo };

//func for getting specific type of data
Data* getData(enum TypeData type);