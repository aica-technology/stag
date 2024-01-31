#include "opencv2/opencv.hpp"
#include "stag/Stag.h"
#include "stag/StagDetector.h"


int main(int argc, char** argv)
{
	cv::Mat image = cv::imread("/path/to/examples/STag-HD23.jpg", cv::IMREAD_GRAYSCALE);

	auto corners = std::vector<std::vector<cv::Point2f>>();
    auto ids = std::vector<int>();

    StagDetector stag(23, 9);

	stag.detectMarkers(image);
	stag.logResults("/path/to/examples/output/");
}
