#include "model/face_detection_model.h"

//func visualize faces
static void FaceDetectModel::visualize(Mat & input, int frame, Mat & faces, double fps, int thickness = 2)
{
    //fps to double
    std::string fpsString = cv::format("FPS : %.2f", (float)fps);
    //if frame >= 0
    if (frame >= 0)
        //output frame
        cout << "Frame " << frame << ", ";
    //output fps
    cout << "FPS: " << fpsString << endl;
    //for i = 0 to last row of faces
    for (int i = 0; i < faces.rows; i++)
    {
        // Print results
        cout << "Face " << i
            //coordinates of top-left corner
            << ", top-left coordinates: (" << faces.at<float>(i, 0) << ", " << faces.at<float>(i, 1) << "), "
            //width and height of bounding box 
            << "box width: " << faces.at<float>(i, 2) << ", box height: " << faces.at<float>(i, 3) << ", "
            //face score
            << "score: " << cv::format("%.2f", faces.at<float>(i, 14))
            << endl;

        // Draw bounding box
        rectangle(input, Rect2i(int(faces.at<float>(i, 0)), int(faces.at<float>(i, 1)), int(faces.at<float>(i, 2)), int(faces.at<float>(i, 3))), Scalar(0, 255, 0), thickness);
        // Draw landmarks
        //right eye
        circle(input, Point2i(int(faces.at<float>(i, 4)), int(faces.at<float>(i, 5))), 2, Scalar(255, 0, 0), thickness);
        //left eye
        circle(input, Point2i(int(faces.at<float>(i, 6)), int(faces.at<float>(i, 7))), 2, Scalar(0, 0, 255), thickness);
        //tip of nose
        circle(input, Point2i(int(faces.at<float>(i, 8)), int(faces.at<float>(i, 9))), 2, Scalar(0, 255, 0), thickness);
        //right corner of mouth
        circle(input, Point2i(int(faces.at<float>(i, 10)), int(faces.at<float>(i, 11))), 2, Scalar(255, 0, 255), thickness);
        //left corner of mouth
        circle(input, Point2i(int(faces.at<float>(i, 12)), int(faces.at<float>(i, 13))), 2, Scalar(0, 255, 255), thickness);
    }
    //puts fps value on image
    putText(input, fpsString, Point(0, 15), FONT_HERSHEY_SIMPLEX, 0.5, Scalar(0, 255, 0), 2);
}