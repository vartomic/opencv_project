#include "key_processing.h"
#include "view/view.h"
#include "view/view_src.h"

void keyProcess(Controller &controller, DataFactory &data, ModelFactory &model, ViewSrc &windSecond) {

    const int delay = 100;
    //waits for pressing key for 100 milliseconds
    int key = cv::waitKey(delay);

    //exit if ESC, 'Q' or 'q' key is pressed
    if ((key == tolower(81)) || (key == toupper(81)) || (key == 27)) {
        (exit(0));
    }
    else if (tolower(key) == 'p') {
        //sets data to controller
        controller.setData(data.getData(DataFactory::TypeData::TypeDataPhoto));
    }
    else if (tolower(key) == 'v') {
        //sets model to video
        controller.setData(data.getData(DataFactory::TypeData::TypeDataVideo));
    }
    else if (tolower(key) == '1') {
        //sets model to gray
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeGrayModel));
    }
    else if (tolower(key) == '2') {
        //sets model to canny
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeCannyModel));
    }
    else if (tolower(key) == '3') {
        //creates trackbars
        windSecond.setHSVtrackbar("par1", /*max=*/240, /*pos=*/100);
        windSecond.setHSVtrackbar("par2", /*max=*/240, /*pos=*/100);
        //sets model to hsv
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeHSVModel));
    }        
    else if (tolower(key) == '4') {
        //sets model to face detection
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeDNNModel));
    }
    else if (tolower(key) == '5') {
        //sets model to face detection
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeHaarModel));
    }
    else if (tolower(key) == '6') {
        //sets model to face detection
        controller.setModel(model.getModel(ModelFactory::TypeModel::TypeMTCNNModel));
    }
}

