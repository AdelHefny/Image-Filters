#include <iostream>
#include "Image_Class.h"
#include <cmath>

using namespace std;

Image EdgeDetection(int width, int height, Image& image, Image& final_image)
{
    int SobelX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int SobelY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < width; i++) {
        if(i == width-2)break;
        for (int j = 0; j < height; j++){
               int SumX = 0, SumY = 0;
                if(j == height-2)break;

                for(int k = -1; k <= 1; k++){
                    for(int l = -1; l <= 1; l++){
                            for(int o = 0; o < 3; o++){
                                SumX += image.getPixel(i+k+1, j+l+1,o) * SobelX[k+1][l+1];
                                SumY += image.getPixel(i+k+1, j+l+1,o) * SobelY[k+1][l+1];
                            }
                    }
                }
             int GradientMagnitude = sqrt((SumX*SumX) + (SumY*SumY));
             final_image.getPixel(i,j,0) = GradientMagnitude > 255? 255 : GradientMagnitude;
             final_image.getPixel(i,j,1) = GradientMagnitude > 255? 255 : GradientMagnitude;
             final_image.getPixel(i,j,2) = GradientMagnitude > 255? 255 : GradientMagnitude;
        }

    }
    return final_image;
}



int main() {
    string filename, new_filename;
    cout << "Please enter the first image name: ";
    cin >> filename;

    Image image(filename);
    Image final_image(image.width, image.height);

    EdgeDetection(image.width, image.height, image, final_image);

    cout << endl << "Please enter image name to store new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";
    cin >> new_filename;

    final_image.saveImage(new_filename);
    system(new_filename.c_str());

    return 0;
}
