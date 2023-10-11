#include "data/data_factory.h"

Data* getData(enum TypeData type){
    static DataPhoto *dataPhoto = 0;
    static DataVideo *dataVideo = 0;

    if (type == TypeData::TypeDataPhoto) {
        if (dataPhoto == nullptr) {
            dataPhoto = new DataPhoto();
        }
        return dataPhoto;
    }
    else if (type == TypeData::TypeDataVideo){
        if (dataVideo == nullptr){
            dataVideo = new DataVideo();
        }
        return dataVideo;
    }
    return 0;
}