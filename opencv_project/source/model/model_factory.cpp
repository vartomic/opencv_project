#include "model/model_factory.h"

Model* getModel(enum TypeModel type) {
    static Model *grayModel = 0;
    static Model *cannyModel = 0;
    static Model *hsvModel = 0;

    if (type == TypeModel::TypeGrayModel) {
        if (grayModel == nullptr) {
            grayModel = new Model();
        }
        return grayModel;
    }
    else if (type == TypeModel::TypeCannyModel) {
        if (cannyModel == nullptr) {
            cannyModel = new Model();
        }
        return cannyModel;
    }
    else if (type == TypeModel::TypeHSVModel) {
        if (hsvModel == nullptr) {
            hsvModel = new Model();
        }
        return hsvModel;
    }
    return 0;
}