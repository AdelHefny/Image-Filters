#include <iostream>
#include "Image_Class.h"
#include <cmath>

using namespace std;

// Function to apply the Night Mood filter to the image
void NightMood(int width, int height, Image& image) {
    // Iterate over each pixel in the image
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++){
            // Iterate over each color channel (R, G, B) of the pixel
            for (int k = 0; k < 3; k++){

                // Retrieve the pixel value for the current channel
                int PixelValue = image(i,j,k);



                // Apply different multipliers to each channel to achieve the night mood effect
                if(k == 0) { // Red channel
                    PixelValue *= 0.5; // Reduce intensity by 50%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    image(i,j,0) = PixelValue; // Update the pixel value for the Red channel
                }
                else if (k == 1) { // Green channel
                    PixelValue *= 0.5; // Reduce intensity by 50%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    image(i,j,1) = PixelValue; // Update the pixel value for the Green channel
                }
                else {
                    // Blue channel
                    PixelValue *= 0.7; // Reduce intensity by 30%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    image(i,j,2) = PixelValue; // Update the pixel value for the Blue channel
                }
            }
        }
    }
}

int main() {
    string filename, new_filename;
    cout << "Please enter the first image name: ";
    cin >> filename;

    // Load the original image
    Image image(filename);

    // Apply the Night Mood filter to the image
    NightMood(image.width, image.height, image);

    cout << endl << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";
    cin >> new_filename;

    // Save the resulting image
    image.saveImage(new_filename);
    system(new_filename.c_str());

    return 0;
}
