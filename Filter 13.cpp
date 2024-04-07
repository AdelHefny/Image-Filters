#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename, new_filename;

    cout << "Please enter the first image name: ";
    cin >> filename;

    Image image(filename);

    Image sunlight(image.width, image.height);
    Image final_image(image.width, image.height);

    // Apply sunlight effect to the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            // Adjust pixel values for sunlight effect
            sunlight(i,j,0) = min(image(i,j,0) + 30, 255);
            sunlight(i,j,1) = min(image(i,j,1) + 30, 255);
            sunlight(i,j,2) = max(0, image(i,j,2) - 50);
        }
    }

    // Copy sunlight effect to the final image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                final_image(i,j,k) = sunlight(i,j,k);
            }
        }
    }

    cout << endl << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";
    cin >> new_filename;

    final_image.saveImage(new_filename);
    system(new_filename.c_str());

    return 0;
}
