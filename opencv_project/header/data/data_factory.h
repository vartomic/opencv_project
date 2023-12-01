#pragma once
#include "data.h"
//
class DataFactory {

public:
	//	Enum with datatypes
	enum class TypeData { TypeDataPhoto, TypeDataVideo, TypeDataCamera };
	//	Function returns pointer to datatype, that object of DataFactory class calls from main function
	Data* getData(enum TypeData type);
};

