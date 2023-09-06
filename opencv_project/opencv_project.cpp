#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "controller/controller.h"
#include "data/data_photo.h"
#include "data/data_video.h"
#include "data/data.h"
#include "view/view.h"
#include "view/view_src.h"
#include "model/model.h"
#include "model/gray_model.h"
#include "model/canny_model.h"
#include "model/hsv_model.h"

int main(){

	//create controller object
	Controller controller;

	//create img object
	DataPhoto dataP;

	DataVideo dataV;

	GrayModel grayM;

	CannyModel cannyM;

	HSVModel hsvM;

	//create window1
	ViewSrc windFirst("Test_window1", cv::WINDOW_AUTOSIZE);

	//create window2
	ViewSrc windSecond("Test_window2", cv::WINDOW_AUTOSIZE);

	windSecond.setTrackbar("par1", controller.getPar1());
	windSecond.setTrackbar("par2", controller.getPar2());

	//send img to controller
	controller.setData(&dataP);

	//send video to controller
	controller.setData(&dataV);

	//send window1 to controller
	controller.setView1(&windFirst);

	//send window2 to controller
	controller.setView2(&windSecond);

	controller.setModel(&grayM);

	while (true) {

		const int delay = 100;
		//waits for pressing key for 100 milliseconds
		int key = cv::waitKey(delay);

		//exit if ESC, 'Q' or 'q' key is pressed
		if ((key == tolower(81)) || (key == toupper(81)) || (key == 27)){
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
			controller.setModel(&hsvM);
			windSecond.setHSVtrackbar("par1", 240, 50);
			windSecond.setHSVtrackbar("par2", 240, 25);
		}
		controller.work();
	}
}
