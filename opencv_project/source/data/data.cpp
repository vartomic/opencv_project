#include "data/data.h"

void Data::setFlag(bool ready) {
	_ready = ready;
}

bool Data::getFlag() {
	return _ready;
}