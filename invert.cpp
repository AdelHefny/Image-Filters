#include "Image_Class.h"

using namespace std;

int main(){
    string filename;
    cout << "Pls enter valid image name existing in the file: "; // Prompt the user to enter a valid image filename
    cin >> filename; // Read the filename from the user
    Image image(filename); // Create an Image object using the provided filename
    int r = image.width; // Get the width of the image
    int c = image.height; // Get the height of the image

	for (int i = 0; i < r; ++i){ // Loop through each row of the image
		for (int j = 0; j < c ; ++j){ // Loop through each column of the image
			for (int k = 0; k < 3; ++k){ // Loop through each color channel (RGB)
				image(i, j, k) = 255 - image(i, j, k) ; // Invert the pixel value for each color channel
			}
		}
	}

	image.saveImage("invert.jpg"); // Save the modified image as "invert.jpg"

}
