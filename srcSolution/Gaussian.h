#ifndef SOURCE_DIRECTORY__GAUSSIAN_H_
#define SOURCE_DIRECTORY__GAUSSIAN_H_

#include <iostream>
using namespace std;

#include <opencv2/opencv.hpp>
using namespace cv;

/**
 * This class performs a Gaussian blur on the input image
 */
class Gaussian {
private:
	string inputFilePath;
	Mat inputImage;
	Mat blurredImage;
	string outputFilePath;
	int kernelSize;

public:
	/**
	 * Default constructor
	 */
	Gaussian();
	/**
	 * Destructor
	 */
	virtual ~Gaussian();

	/**
	 * Open and load an image located in the system at filePath
	 */
	bool open(string filePath);

	/**
	 * Shows the interface with the input image
	 */
	void show();

	// TODO implement these methods
	/**
	 * Blurs inputImage and show the result another window
	 */
	static void blurImage(int value, void* data);
	/**
	 * Saves the blurred image to a png file.
	 */
	static void onMouseClick(int event, int x, int y, int flags, void* userdata);
};

#endif
