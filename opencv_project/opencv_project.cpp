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
#include "header/key_processing.h"

int main(){

	//create controller object
	Controller controller;

	//create img object
	DataPhoto dataP;

	DataVideo dataV;

	GrayModel grayM;

	CannyModel cannyM;

	HSVmodel hsvM;

	//create window
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
		keyProcess(controller, windSecond);
		controller.work();
	}
}
