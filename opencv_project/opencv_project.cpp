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

int main(){

	//create controller object
	Controller controller;

	//create img object
	DataPhoto dataP;

	DataVideo dataV;

	GrayModel grayM;

	//create window1
	ViewSrc windFirst("Test_window1", cv::WINDOW_AUTOSIZE);

	//create window2
	ViewSrc windSecond("Test_window2", cv::WINDOW_AUTOSIZE);

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
		controller.work();
	}
}
