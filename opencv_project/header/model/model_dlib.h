#pragma once
#include <dlib/image_processing/frontal_face_detector.h>

class DlibModel {

public:
	DlibModel() {
		// Load face detection and pose estimation models.
		frontal_face_detector detector = get_frontal_face_detector();
		shape_predictor pose_model;
		deserialize("shape_predictor_68_face_landmarks.dat") >> pose_model;
	}
};