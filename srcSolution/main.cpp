#include <iostream>
using namespace std;

#include "Gaussian.h"

int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Usage: imageBlur <Image_Path>" << endl;
		return -1;
	}

	Gaussian filter;
	bool opened = filter.open(argv[1]);
	if (!opened) {
		cerr << "Error opening image" << endl;
		cout << "Usage: imageBlur <Image_Path>" << endl;
		return -1;
	}
	filter.show();
}
