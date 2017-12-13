#include "Gaussian.h"

Gaussian::Gaussian() {
}

Gaussian::~Gaussian() {
}

bool Gaussian::open(string filePath) {
	inputImage = imread(filePath, IMREAD_COLOR);
	if (inputImage.empty())
		return false;

	stringstream ss;
	ss << filePath << "Blurred.png";
	this->outputFilePath = ss.str();
	return true;
}

void Gaussian::show() {
	namedWindow("Input Image", WINDOW_AUTOSIZE);
	createTrackbar("Blur", "Input Image", &kernelSize, 30, blurImage, this);
	imshow("Input Image", inputImage);
	waitKey(0);
}

void Gaussian::blurImage(int value, void* data) {
	Mat inputImage = ((Gaussian*) data)->inputImage;
	cout << "calling " << value << endl;
	((Gaussian*) data)->blurredImage = inputImage.clone();
	GaussianBlur(inputImage, ((Gaussian*) data)->blurredImage,
			Size(1 + 2 * value, 1 + 2 * value), 0, 0);
	imshow("Blurred Image", ((Gaussian*) data)->blurredImage);
	setMouseCallback("Blurred Image", onMouseClick, data);
}

void Gaussian::onMouseClick(int event, int x, int y, int flags, void* data) {
	if (event == EVENT_LBUTTONUP) {
		imwrite(((Gaussian*) data)->outputFilePath,
				((Gaussian*) data)->blurredImage);
		cout << "saved to " << ((Gaussian*) data)->outputFilePath << endl;
	}
}
