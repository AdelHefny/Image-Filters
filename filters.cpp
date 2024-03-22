#include <iostream>
#include "Image_Class.h"
using namespace std;

int main(){
    string filename;
    cout << "adel" << endl;
    cout << "Enter the filename: " << endl;
    cin >> filename;

    Image image(filename);

    for(int i = 0;i < image.width;i++){
        for(int j = 0;j < image.height;j++){
            int avg = 0;
            for(int k = 0;k < 3;k++){
                avg += image(i,j,k);
            }
            avg /= 3;
            avg = (avg > 127 ? 255 : 0);
            image(i,j,0) = avg;
            image(i,j,1) = avg;
            image(i,j,2) = avg;
        }
    }

    cout << "please enter the file name you want the image to be saved as " << endl;
    cout << "please specify the image type .jpg .bmp, .png, .tga:" << endl;

    cin >> filename;
    image.saveImage(filename);
    return 0;
}