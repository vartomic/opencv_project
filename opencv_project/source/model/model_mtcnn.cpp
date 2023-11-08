#include "model/model_mtcnn.h"

void MTCNNModel::visualize(std::vector<Face>& faces, std::vector<rectPoints>& data) {
    for (size_t i = 0; i < faces.size(); ++i) {
        std::vector<cv::Point> pts;
        for (int p = 0; p < NUM_PTS; ++p) {
            pts.push_back(
                cv::Point(faces[i].ptsCoords[2 * p], faces[i].ptsCoords[2 * p + 1]));
        }
        auto rect = faces[i].bbox.getRect();
        auto d = std::make_pair(rect, pts);
        data.push_back(d);
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

    faces = detector->detect(image, 20.f, 0.709f);
    //  Tickmeter stops
    tm.stop();
    //
    visualize(faces, data);
    //
	return image;
}