#include <iostream> 
#include "Image_Class.h" 

using namespace std; 

int main() {
    string filename; 
    cout << "Please enter colored image name to turn to gray scale: ";
    cin >> filename; 

    
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

    cout << "Please enter image name to save the new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";

    cin >> filename; 

    // Save the modified image with the provided filename
    image.saveImage(filename);

    // Open the saved image using the default system viewer
    system(filename.c_str());

    return 0; 
}
