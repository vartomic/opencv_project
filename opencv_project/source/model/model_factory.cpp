#include "model/model_factory.h"

Model* ModelFactory::getModel(enum TypeModel type) {
    //static pointer to gray model = 0
    static GrayModel *grayModel = 0;
    //static pointer to canny model = 0
    static CannyModel *cannyModel = 0;
    //static pointer to hsv model = 0
    static HSVModel *hsvModel = 0;
    //static pointer to face detection model = 0
    static FaceDetectModel* faceDetectModel = 0;

    //if type of model = gray model
    if (type == TypeModel::TypeGrayModel) {
        //if pointer to gray model = 0
        if (grayModel == nullptr) {
            //allocate memory for new gray model
            grayModel = new GrayModel();
        }
        //return gray model
        return grayModel;
    }
    //if type of model = canny model
    else if (type == TypeModel::TypeCannyModel) {
        //if pointer to canny model = 0
        if (cannyModel == nullptr) {
            //allocate memory for new canny model
            cannyModel = new CannyModel();
        }
        //return canny model
        return cannyModel;
    }
    //if type of model = hsv model
    else if (type == TypeModel::TypeHSVModel) {
        //if pointer to hsv model = 0
        if (hsvModel == nullptr) {
            //allocate memory for new hsv model
            hsvModel = new HSVModel();
        }
        //return hsv model
        return hsvModel;
    }
    //if type of model = hsv model
    else if (type == TypeModel::TypeFaceDetectModel) {
        //if pointer to face detection model = 0
        if (faceDetectModel == nullptr) {
            //allocate memory for new face detection model
            faceDetectModel = new FaceDetectModel();
        }
        //return face detection model
        return faceDetectModel;
    }
    return 0;
}