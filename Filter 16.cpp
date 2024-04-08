#include <iostream>
#include "Image_Class.h"

using namespace std;

int main() {
    string filename, new_filename;

    // Prompt the user to enter the filename of the image
    cout << "Please enter the first image name: ";
    cin >> filename;

    // Load the image
    Image image(filename);

    // Create a new image for the purple effect
    Image purple(image.width, image.height);

    // Create a final image to store the modified result
    Image final_image(image.width, image.height);

    // Apply the purple effect to the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            // Adjust RGB values to create a purple effect
            purple(i, j, 0) = min(image(i, j, 0) + 20, 255);  // Increase red
            purple(i, j, 1) = max(image(i, j, 1) - 30, 0);   // Decrease green
            purple(i, j, 2) = min(image(i, j, 2) + 20, 255);  // Increase blue
        }
    }

    // Copy the purple image to the final image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            for (int k = 0; k < 3; k++) {
                final_image(i, j, k) = purple(i, j, k);
            }
        }
    }

    // Prompt the user to enter the filename to save the new image
    cout << endl << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";
    cin >> new_filename;

    // Save the final image
    final_image.saveImage(new_filename);

    // Display the new image
    system(new_filename.c_str());

    return 0;
}
