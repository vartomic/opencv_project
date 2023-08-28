#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>
#include "controller/controller.h"
#include "data/dataPhoto.h"
#include "data/dataVideo.h"
#include "data/data.h"
#include "view/view.h"
#include "view/viewSrc.h"
#include "model/model.h"
#include "model/grayModel.h"
#include "model/cannyModel.h"

int main(){

	//create controller object
	Controller controller;

	//create img object
	DataPhoto dataP;

	DataVideo dataV;

	GrayModel grayM;

	CannyModel cannyM;

	//create window1
	ViewSrc windFirst("Test_window1", cv::WINDOW_AUTOSIZE);

	//create window2
	ViewSrc windSecond("Test_window2", cv::WINDOW_AUTOSIZE);

	//windSecond.setTrackBar();

	//send img to controller
	controller.setData(&dataP);

	//send video to controller
	controller.setData(&dataV);

	//send window1 to controller
	controller.setView1(&windFirst);

	//send window2 to controller
	controller.setView2(&windSecond);

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
		else if (tolower(key) == 'c') {
			//sets model to canny
			controller.setModel(&cannyM);
		}
		else if (tolower(key) == 'g') {
			//sets model to gray
			controller.setModel(&grayM);
		}
		controller.work();
	}
}
