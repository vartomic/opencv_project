#include "model/model_mtcnn.h"

void MTCNNModel::visualize(cv::Mat& image, std::vector<Face>& faces) {
    for (size_t i = 0; i < faces.size(); ++i) {
        auto rect = faces[i].bbox.getRect();
        //нарисовать прямоугольник, вывести частоту, разрешение
        rectangle(image, rect, cv::Scalar(0, 0, 255));
    }  
}
cv::Mat MTCNNModel::process(cv::Mat frame) {
    //  Checks if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    //  Tickmeter
    cv::TickMeter tm;
    //  Tickmeter starts
    tm.start();
    //  Creates clone of an input image
    cv::Mat image = frame.clone();

    auto faces = detector->detect(image, 20.f, 0.709f);
    //  Tickmeter stops
    tm.stop();
    //
    visualize(image, faces);
    //
	return image;
}