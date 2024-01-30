#include "opencv2/opencv.hpp"
#include "stag/Stag.h"


int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("/path/to/examples/STag-HD23.jpg", CV_LOAD_IMAGE_GRAYSCALE);

	stag::Stag stag(23, 7, true);

	stag.detectMarkers(image);
	stag.logResults("/path/to/examples/output/");
}
