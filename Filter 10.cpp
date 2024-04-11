#include <iostream>
#include "Image_Class.h"
#include <cmath>

using namespace std;

// Function to convert image to black and white
void BlackAndWhite(Image& image)
{
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            // Calculate average intensity value across RGB channels
            int avg = 0;
            for(int k = 0; k < 3; k++){
                avg += image(i, j, k);
            }
            avg /= 3;
            // Threshold to binary (black and white)
            avg = (avg > 127 ? 255 : 0);
            // Set RGB values to the same value to convert to grayscale
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}

// Function for edge detection
void EdgeDetection(int width, int height, Image& image)
{
    // Convert image to black and white
    BlackAndWhite(image);

    // Perform edge detection
    for(int i = 0; i < width - 1; i++){
        for(int j = 0; j < height - 1; j++){
            for(int k = 0; k < 3; k++){
                // Compute differences in vertical and horizontal directions
                int diffV = abs(image(i, j, k) - image(i + 1, j, k)); // Vertical difference
                int diffH = abs(image(i, j, k) - image(i, j + 1, k)); // Horizontal difference
                // Compute gradient magnitude using Euclidean distance
                int res = sqrt(diffV * diffV + diffH * diffH);
                // Apply thresholding
                int constant = 100; // Threshold constant (adjust as needed)
                image(i, j, k) = res > constant ? 0 : 255; // Set pixel to black or white based on threshold
            }
        }
    }
}

int main() {
    string filename, new_filename;
    cout << "Please enter the first image name: ";
    cin >> filename;

    // Load image
    Image image(filename);

    // Perform edge detection
    EdgeDetection(image.width, image.height, image);

    // Save and display resulting image
    cout << endl << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";
    cin >> new_filename;
    image.saveImage(new_filename);
    system(new_filename.c_str());

    return 0;
}
