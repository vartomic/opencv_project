#include "key_processing.h"

void keyProcess(Controller &controller, DataFactory &data, ModelFactory &model, ViewSrc &window1, ViewSrc &window2) {
    //
    std::vector<std::string> keyDescription = {"P - change datatype to photo", "V - change datatype to video",
        "C - change datatype to video from webcamera", "1 - change modeltype to DNN", "2 - change modeltype to Haar Cascades",
        "3 - change modeltype to MTCNN", "4 - change modeltype to Dlib" };
    //
    window1.getKeyDescription(keyDescription);
    const int delay = 10;
    //  Waits for pressing key for 10 milliseconds
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
    //  If 'c' key is pressed
    else if (tolower(key) == 'c') {
        //  DataFactory object calls function getData() and returns photo type. Controller sets that datatype inside itself
        controller.setData(data.getData(DataFactory::TypeData::TypeDataCamera));
    }     
    //  If '1' key is pressed
    else if (tolower(key) == '1') {
        //  ModelFactory object calls function getData() and returns dnn model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeDNNModel));
    }
    //  If '2' key is pressed
    else if (tolower(key) == '2') {
        //  ModelFactory object calls function getData() and returns haar model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeHaarModel));
    }
    //  If '3' key is pressed
    else if (tolower(key) == '3') {
        //  ModelFactory object calls function getData() and returns mtcnn model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeMTCNNModel));
    }
    //  If '4' key is pressed
    else if (tolower(key) == '4') {
        //  ModelFactory object calls function getData() and returns dlib model type. Controller sets that modeltype inside itself
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeDlibModel));
    }
}

