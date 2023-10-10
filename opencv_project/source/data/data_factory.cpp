#include "data/data_factory.h"
#include "data/data_photo.h"
#include "data/data_video.h"

Data* getData(enum TypeData type){
    static DataPhoto *dataPhoto = 0;
    static DataVideo *dataVideo = 0;

    if (type == TypeDataPhoto){
        if (dataPhoto == nullptr){
            dataPhoto = new DataPhoto();
            return &dataPhoto;
        }
    else if (type == TypeDataVideo){
        if (dataVideo == nullptr){
            dataVideo = new DataVideo();
            return &dataVideo;
        }
    }
    return 0;
}