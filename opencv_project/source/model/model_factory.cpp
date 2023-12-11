#include "model/model_factory.h"

Model* ModelFactory::getModel(enum TypeModel type) {
    //  Static pointer to dnn model = 0
    static DNNModel* dnnModel = 0;
    //  Static pointer to haar model = 0
    static HaarModel* haarModel = 0;
    //  Static pointer to mtcnn model = 0
    static MTCNNModel* mtcnnModel = 0;
    //  Static pointer to dlib model = 0
    static DlibModel* dlibModel = 0;

    //  If type of model = dnn model
    if (type == TypeModel::TypeDNNModel) {
        //  If pointer to face detection model = 0
        if (dnnModel == nullptr) {
            //  Allocate memory for new face detection model
            dnnModel = new DNNModel();
        }
        //  Returns face detection model
        return dnnModel;
    }
    //  If type of model = haar model
    else if (type == TypeModel::TypeHaarModel) {
        //  If pointer to haar model = 0
        if (haarModel == nullptr) {
            //  Allocate memory for new haar model
            haarModel = new HaarModel();
        }
        //  Returns haar model
        return haarModel;
    }
    //  If type of model = mtcnn model
    else if (type == TypeModel::TypeMTCNNModel) {
        //  If pointer to mtcnn model = 0
        if (mtcnnModel == nullptr) {
            //  Allocate memory for new mtcnn model
            mtcnnModel = new MTCNNModel();
        }
        //  Returns mtcnn model
        return mtcnnModel;
    }
    //  If type of model = dlib model
    else if (type == TypeModel::TypeDlibModel) {
        //  If pointer to dlib model = 0
        if (dlibModel == nullptr) {
            //  Allocate memory for new dlib model
            dlibModel = new DlibModel();
        }
        //  Returns dlib model
        return dlibModel;
    }
    return 0;
}