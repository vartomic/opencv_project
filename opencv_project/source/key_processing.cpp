#include "header/key_processing.h"

void keyProcess(Controller& refController) {
    const int delay = 100;
    //waits for pressing key for 100 milliseconds
    int key = cv::waitKey(delay);

    //exit if ESC, 'Q' or 'q' key is pressed
    if ((key == tolower(81)) || (key == toupper(81)) || (key == 27)) {
        (exit(0));
    }
    else if (tolower(key) == 'p') {
        //sets model to photo
        controller.setData(&dataP);
    }
    else if (tolower(key) == 'v') {
        //sets model to video
        controller.setData(&dataV);
    }
    else if (tolower(key) == '1') {
        //sets model to gray
        controller.setModel(&grayM);
    }
    else if (tolower(key) == '2') {
        //sets model to canny
        controller.setModel(&cannyM);
    }
    else if (tolower(key) == '3') {
        //sets model to hsv
        //windSecond.setMaxTrackbar("par1", /*max=*/240, /*pos=*/100);
        //windSecond.setMaxTrackbar("par2", /*max=*/240, /*pos=*/100);
        controller.setModel(&hsvM);
    }               
}

