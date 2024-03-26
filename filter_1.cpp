#include <iostream> // Include the input-output stream library
#include "Image_Class.h" // Include the header file for the Image class

using namespace std; // Using the standard namespace

int main() {
    string filename; // Declare a string variable to store the filename
    cout << "Please enter colored image name to turn to gray scale: ";
    cin >> filename; // Get the filename from user input

    // Create an Image object with the provided filename
    Image image(filename);

    // Loop through each pixel in the image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            unsigned  int avg = 0; // Initialize an integer variable to store the average value

            // Calculate the average value of RGB channels for each pixel
            for (int k = 0; k < 3; ++k) {
                avg += image(i, j, k);
            }

            avg /= 3; // Calculate the final average value

            // Set the RGB values of the pixel to the calculated average
            for (int k = 0; k < 3; ++k) {
                image(i, j, k) = avg;
            }
        }
    }

    // Prompt the user to enter a filename to save the modified image
    cout << "Please enter image name to save the new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";

    cin >> filename; // Get the filename for the new image from user input

    // Save the modified image with the provided filename
    image.saveImage(filename);

    // Open the saved image using the default system viewer
    system(filename.c_str());

    return 0; // Return 0 to indicate successful completion
}
