#include "key_processing.h"
#include "view/view.h"
#include "view/view_src.h"

void keyProcess(Controller &controller, DataFactory &data, ModelFactory &model, ViewSrc &windSecond) {
    const int delay = 100;
    //  Waits for pressing key for 100 milliseconds
    int key = cv::waitKey(delay);
    //  Exits if ESC, 'Q' or 'q' key is pressed
    if ((key == tolower(81)) || (key == toupper(81)) || (key == 27)) {
        (exit(0));
    }
    //  If 'p' key is pressed
    else if (tolower(key) == 'p') {
        //  DataFactory object calls function getData() and returns photo type. Controller sets that datatype inside itself
        controller.setData(data.getData(DataFactory::TypeData::TypeDataPhoto));
    }
    //  If 'v' key is pressed
    else if (tolower(key) == 'v') {
        //  DataFactory object calls function getData() and returns photo type. Controller sets that datatype inside itself
        controller.setData(data.getData(DataFactory::TypeData::TypeDataVideo));
    }
    //  If '1' key is pressed
    else if (tolower(key) == '1') {
        //  ModelFactory object calls function getData() and returns gray model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeGrayModel));
    }
    //  If '2' key is pressed
    else if (tolower(key) == '2') {
        //  ModelFactory object calls function getData() and returns canny model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeCannyModel));
    }
    //  If '3' key is pressed
    else if (tolower(key) == '3') {
        //  ViewSrc object calls function setHSVtrackbar to create trackbar 
        windSecond.setHSVtrackbar("par1", /*max=*/240, /*pos=*/100);
        //  ViewSrc object calls function setHSVtrackbar to create trackbar 
        windSecond.setHSVtrackbar("par2", /*max=*/240, /*pos=*/100);
        //  ModelFactory object calls function getData() and returns hsv model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeHSVModel));
    }        
    //  If '4' key is pressed
    else if (tolower(key) == '4') {
        //  ModelFactory object calls function getData() and returns dnn model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeDNNModel));
    }
    //  If '5' key is pressed
    else if (tolower(key) == '5') {
        //  ModelFactory object calls function getData() and returns haar model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeHaarModel));
    }
    //  If '6' key is pressed
    else if (tolower(key) == '6') {
        //  ModelFactory object calls function getData() and returns mtcnn model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeMTCNNModel));
    }
}

