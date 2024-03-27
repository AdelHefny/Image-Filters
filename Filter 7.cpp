#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename, new_filename;
    int choice;
    cout << "DO YOU WANT TO INCREASE THE BRIGHTNESS OR DECREASE IT BY 50%?\n";
    cout << "1) Increase the brightness          2) Decrease the brightness: ";
    cin >> choice;
    cout << "Please enter the first image name: ";
    cin >> filename;

    Image image(filename);
    Image final_image(image.width, image.height);

    if (choice == 1) {
        int increase_brightness;
        // Loop through each pixel in the image
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    // Get the pixel value at (i, j) for channel k
                    int pixel_value = image(i, j, k);
                    // Increase the brightness by multiplying the pixel value by 1.5
                    increase_brightness = min(int(pixel_value * 1.5), 255);
                    // Store the adjusted pixel value in the final image
                    final_image(i, j, k) = increase_brightness;
                }
            }
        }
    } else {
        int decrease_brightness;
        // Loop through each pixel in the image
        for (int i = 0; i < image.width; i++) {
            for (int j = 0; j < image.height; j++) {
                for (int k = 0; k < 3; k++) {
                    // Get the pixel value at (i, j) for channel k
                    int pixel_value = image(i, j, k);
                    // Decrease the brightness by multiplying the pixel value by 0.5
                    decrease_brightness = max(int(pixel_value * 0.5), 0);
                    // Store the adjusted pixel value in the final image
                    final_image(i, j, k) = decrease_brightness;
                }
            }
        }
    }

    cout << endl << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";

    cin >> new_filename;
    // Save the final image and display it
    final_image.saveImage(new_filename);
    system(new_filename.c_str());

    return 0;
}
