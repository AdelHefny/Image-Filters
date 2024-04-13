#include <iostream>
#include "Image_Class.h"
#include <cmath>

using namespace std;

// Function to apply Sepia Tone filter to the image
void SepiaTone(int width, int height, Image& image) {

    int newR, newG, newB;

    // Iterate over each pixel in the image
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // For each pixel, calculate new RGB values based on the sepia tone effect
            for (int k = 0; k < 3; k++) {
                int PixelValue = image(i, j, k);
                if (k == 0) {
                    // Calculate new Red value
                    newR = min(255, (int)(0.393 * PixelValue + 0.769 * image(i, j, 1) + 0.189 * image(i, j, 2)));
                }
                else if (k == 1) {
                    // Calculate new Green value
                    newG = min(255, (int)(0.349 * image(i, j, 0) + 0.686 * PixelValue + 0.168 * image(i, j, 2)));
                }
                else {
                    // Calculate new Blue value
                    newB = min(255, (int)(0.272 * image(i, j, 0) + 0.534 * image(i, j, 1) + 0.131 * PixelValue));
                }
            }

            // Update the pixel with the new RGB values
            image(i, j, 0) = newR;
            image(i, j, 1) = newG;
            image(i, j, 2) = newB;
        }
    }
}

int main() {
    string filename, new_filename;
    cout << "Please enter the first image name: ";
    cin >> filename;

    // Load the original image
    Image image(filename);

    // Apply the sepia tone filter
    SepiaTone(image.width, image.height, image);

    // Get the filename for the filtered image
    cout << endl << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";
    cin >> new_filename;

    // Save the filtered image
    image.saveImage(new_filename);
    system(new_filename.c_str());

    return 0;
}
