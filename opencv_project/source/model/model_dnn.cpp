#include "model/model_dnn.h"

void DNNModel::visualize(cv::Mat & image, cv::Mat & faces, double fps, int processedFrames, int totalFaceScore, double timeElapsed, int thickness){ 
    //  Text string with fps value formatted from double to float
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //  Receives the width of input image
    int width = image.size().width;
    //  Receives the height of input image
    int height = image.size().height;
    //  Text string with width and height of input image
    std::string resolutionString = cv::format("Resolution : %d x %d", width, height);
    std::string modelNameString = "Model: DNN";
    //  Outputs fps
    std::cout << fpsString << std::endl;
    //  For i = 0 to the last row of faces
    for (int i = 0; i < faces.rows; i++) {
        //  Draws bounding box by the 4 coordinates of a face
        rectangle(image, cv::Rect2i(int(faces.at<float>(i, 0)), int(faces.at<float>(i, 1)), int(faces.at<float>(i, 2)), int(faces.at<float>(i, 3))), cv::Scalar(0, 255, 0), thickness);
        // Draw landmarks
        //  Landmark of the right eye
        circle(image, cv::Point2i(int(faces.at<float>(i, 4)), int(faces.at<float>(i, 5))), 2, cv::Scalar(255, 0, 0), thickness);
        //  Landmark of the left eye
        circle(image, cv::Point2i(int(faces.at<float>(i, 6)), int(faces.at<float>(i, 7))), 2, cv::Scalar(0, 0, 255), thickness);
        //  Landmark of the tip of the nose
        circle(image, cv::Point2i(int(faces.at<float>(i, 8)), int(faces.at<float>(i, 9))), 2, cv::Scalar(0, 255, 0), thickness);
        //  Landmark of right corner of the mouth
        circle(image, cv::Point2i(int(faces.at<float>(i, 10)), int(faces.at<float>(i, 11))), 2, cv::Scalar(255, 0, 255), thickness);
        //  Landmark of left corner of the mouth
        circle(image, cv::Point2i(int(faces.at<float>(i, 12)), int(faces.at<float>(i, 13))), 2, cv::Scalar(0, 255, 255), thickness);

        //cv::Point2i pt1 = cv::Point2i(int(faces.at<float>(i, 8)), int(faces.at<float>(i, 9)));
        //cv::Point2i pt2 = cv::Point2i(int(faces.at<float>(i, 10)), int(faces.at<float>(i, 11)));
        //cv::Point2i pt3 = cv::Point2i(int(faces.at<float>(i, 12)), int(faces.at<float>(i, 13)));
        //cv::line(input, pt1, pt2, cv::Scalar(0, 0, 255), 1, cv::LINE_8, 0);
        //cv::line(input, pt2, pt3, cv::Scalar(0, 0, 255), 1, cv::LINE_8, 0);
        //cv::line(input, pt1, pt3, cv::Scalar(0, 0, 255), 1, cv::LINE_8, 0);  
        //  
        totalFaceScore++;
        //std::cout << cv::format("Inference time: %.2f ms", timeElapsed) << std::endl;
    }
    //
    putText(image, modelNameString, cv::Point(0, 15), cv::FONT_ITALIC, 0.5, cv::Scalar(255, 0, 0), thickness);
    //  Function draws the text string with fps value in the image
    putText(image, fpsString, cv::Point(0, 35), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 255, 255), thickness);
    //  Function draws the text string with resolution of input image on the image
    putText(image, resolutionString, cv::Point(0, 55), cv::FONT_ITALIC, 0.5, cv::Scalar(0, 0, 255), thickness);
    //
    std::cout << "Total score of faces: " << totalFaceScore << std::endl;
    //
    //std::cout << "Processed frames: " << processedFrames << std::endl;

}
cv::Mat DNNModel::process(cv::Mat frame) {
    //  Checks if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }
    //  Tickmeter measures passed time
    cv::TickMeter tm;
    //  Tickmeter starts
    tm.start();
    //  Creates a clone of an input image
    cv::Mat image = frame.clone();
    //  Sets input size before inference
    detector->setInputSize(image.size());
    cv::Mat faces;
    //  Detects faces in the input image
    detector->detect(image, faces);
    //  Tickmeter stops
    tm.stop();
    //  Function draws rectangles around faces and landmarks on faces, tickmeter receives fps value
    visualize(image, faces, tm.getFPS(), _processedFrames, _totalFaceScore, tm.getTimeMilli());
    //  Returns processed image
    return image;
}