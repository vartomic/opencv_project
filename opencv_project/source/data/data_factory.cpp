#include "data/data_photo.h"
#include "data/data_camera.h"
#include "data/data_video.h"
#include "data/data_factory.h"

Data* DataFactory::getData(enum TypeData type){
    //  Static pointer to photo = 0
    static DataPhoto *dataPhoto = 0;
    //  Static pointer to video = 0
    static DataVideo* dataVideo = 0;
    //  Static pointer to video from camera = 0
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
    if (type == TypeData::TypeDataVideo) {
        //  If pointer to video = 0
        if (dataVideo == nullptr) {
            //  Allocate memory for new video
            dataVideo = new DataVideo();
        }
        dataVideo->setFlag(true);
        //  Pointer calls DataVideo class function nextVideo
        dataVideo->nextVideo();
        //  Returns photo
        return dataVideo;
    }
    //  If type of data = video from camera
    else if (type == TypeData::TypeDataCamera){
        //  If pointer to video = 0
        if (dataCamera == nullptr){
            //  Allocate memory for new video
            dataCamera = new DataCamera();
        }
        //  Returns video
        return dataCamera;
    }
    return 0;
}