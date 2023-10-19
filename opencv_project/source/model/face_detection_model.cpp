#include "model/face_detection_model.h"

void FaceDetectModel::visualize(cv::Mat & input, int frame, cv::Mat & faces, double fps, int thickness){
    //fps to double
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);

    int width = input.size().width;

    int height = input.size().height;

    std::string resolutionString = cv::format("Resolution : %d x %d", width, height);

    //if frame >= 0
    if (frame >= 0)
        //output frame
        std::cout << "Frame " << frame << ", ";
    //output fps
    std::cout << "FPS: " << fpsString << std::endl;
    //for i = 0 to last row of faces
    for (int i = 0; i < faces.rows; i++)
    {
        // Print results
        std::cout << "Face " << i
            //coordinates of top-left corner
            << ", top-left coordinates: (" << faces.at<float>(i, 0) << ", " << faces.at<float>(i, 1) << "), "
            //width and height of bounding box 
            << "box width: " << faces.at<float>(i, 2) << ", box height: " << faces.at<float>(i, 3) << ", "
            //face score
            << "score: " << cv::format("%.2f", faces.at<float>(i, 14))
            << std::endl;

        // Draw bounding box
        rectangle(input, cv::Rect2i(int(faces.at<float>(i, 0)), int(faces.at<float>(i, 1)), int(faces.at<float>(i, 2)), int(faces.at<float>(i, 3))), cv::Scalar(0, 255, 0), thickness);
        // Draw landmarks
        //right eye
        circle(input, cv::Point2i(int(faces.at<float>(i, 4)), int(faces.at<float>(i, 5))), 2, cv::Scalar(255, 0, 0), thickness);
        //left eye
        circle(input, cv::Point2i(int(faces.at<float>(i, 6)), int(faces.at<float>(i, 7))), 2, cv::Scalar(0, 0, 255), thickness);
        //tip of nose
        circle(input, cv::Point2i(int(faces.at<float>(i, 8)), int(faces.at<float>(i, 9))), 2, cv::Scalar(0, 255, 0), thickness);
        //right corner of mouth
        circle(input, cv::Point2i(int(faces.at<float>(i, 10)), int(faces.at<float>(i, 11))), 2, cv::Scalar(255, 0, 255), thickness);
        //left corner of mouth
        circle(input, cv::Point2i(int(faces.at<float>(i, 12)), int(faces.at<float>(i, 13))), 2, cv::Scalar(0, 255, 255), thickness);

        cv::Point2i pt1 = cv::Point2i(int(faces.at<float>(i, 8)), int(faces.at<float>(i, 9)));

        cv::Point2i pt2 = cv::Point2i(int(faces.at<float>(i, 10)), int(faces.at<float>(i, 11)));

        cv::Point2i pt3 = cv::Point2i(int(faces.at<float>(i, 12)), int(faces.at<float>(i, 13)));

        cv::line(input, pt1, pt2, cv::Scalar(0, 0, 255), 1, cv::LINE_8, 0);

        cv::line(input, pt2, pt3, cv::Scalar(0, 0, 255), 1, cv::LINE_8, 0);

        cv::line(input, pt1, pt3, cv::Scalar(0, 0, 255), 1, cv::LINE_8, 0);
    }
    //puts fps value on image
    putText(input, fpsString, cv::Point(0, 15), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(0, 255, 0), 2);

    putText(input, resolutionString, cv::Point(0, 35), cv::FONT_HERSHEY_SIMPLEX, 0.5, cv::Scalar(255, 0, 0), 1);


}

cv::Mat FaceDetectModel::process(cv::Mat frame) {

    //check if frame is empty
    if (frame.empty()) {
        return cv::Mat();
    }

    cv::TickMeter tm;

    tm.start();
  
    cv::Mat image = frame.clone();
    // Set input size before inference
    detector->setInputSize(image.size());

    cv::Mat faces;
    detector->detect(image, faces);

    tm.stop();
    // Draw results on the input image
    visualize(image, -1, faces, tm.getFPS());
    //соединить линиями уголки рта и носа, чтобы получился треугольник


    return image;
}