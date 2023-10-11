#include "data/data_factory.h"

Data* getData(enum TypeData type){
    //static pointer to photo = 0
    static DataPhoto *dataPhoto = 0;
    //static pointer to video = 0
    static DataVideo *dataVideo = 0;

    //if type of data = photo
    if (type == TypeData::TypeDataPhoto) {
        //if pointer to photo = 0
        if (dataPhoto == nullptr) {
            //allocate memory for new photo
            dataPhoto = new DataPhoto();
        }
        //return photo
        return dataPhoto;
    }
    //if type of data = video
    else if (type == TypeData::TypeDataVideo){
        //if pointer to video = 0
        if (dataVideo == nullptr){
            //allocate memory for new photo
            dataVideo = new DataVideo();
        }
        //return video
        return dataVideo;
    }
    return 0;
}