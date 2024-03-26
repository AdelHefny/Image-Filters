#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename;
    cout << "Please enter colored image name to turn to gray scale: ";
    cin >> filename;

    Image image(filename);

    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0;

            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }

            avg /= 3;
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = avg;
            }
        }
    }

    cout << "Please enter image name to score new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";

    cin >> filename;

    image.saveImage(filename);
    system(filename.c_str());

    return 0;
}
