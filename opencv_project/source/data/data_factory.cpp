#include "data/data_factory.h"

Data* DataFactory::getData(enum TypeData type){
    //  Static pointer to photo = 0
    static DataPhoto *dataPhoto = 0;
    //  Static pointer to video = 0
    static DataVideo *dataVideo = 0;

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
    else if (type == TypeData::TypeDataVideo){
        //  If pointer to video = 0
        if (dataVideo == nullptr){
            //  Allocate memory for new photo
            dataVideo = new DataVideo();
        }
        //  Returns video
        return dataVideo;
    }
    return 0;
}