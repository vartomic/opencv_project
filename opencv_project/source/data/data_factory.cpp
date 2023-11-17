#include "data/data_factory.h"

Data* DataFactory::getData(enum TypeData type){
    //  Static pointer to photo = 0
    static DataPhoto *dataPhoto = 0;
    //  Static pointer to video = 0
    static DataCamera *dataCamera = 0;

    //  If type of data = photo
    if (type == TypeData::TypeDataPhoto) {
        //  If pointer to photo = 0
        if (dataPhoto == nullptr) {
            //  Allocate memory for new photo
            dataPhoto = new DataPhoto();
        }
        //  Pointer calls DataPhoto class function nextImage
        dataPhoto->nextImage();
        //  Returns photo
        return dataPhoto;
    }
    //  If type of data = video
    else if (type == TypeData::TypeDataCamera){
        //  If pointer to video = 0
        if (dataCamera == nullptr){
            //  Allocate memory for new photo
            dataCamera = new DataCamera();
        }
        //  Returns video
        return dataCamera;
    }
    return 0;
}