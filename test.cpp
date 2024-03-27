#include <iostream>
#include "Image_Class.h"

using namespace std;

Image resizee(int x, int y, string filename){
    int newWidth = x, newHeight = y;

    Image image(filename);
    // creating a new image with the desired width and height
    Image newImage(newWidth,newHeight);
    int oldWidth = image.width,oldHeight = image.height;
    // getting the relative width and height
    float relativeWidth = (float)newWidth/image.width,relativeHeight = (float)newHeight/image.height;

    for(int i = 0;i < newImage.width;i++){
        for(int j = 0;j < newImage.height;j++){
            int x = floor((float)i/relativeWidth),y = floor((float)j/relativeHeight);
            // checking the x-axis if it is in inside the old image
            if(x > oldWidth - 1){
                x = oldWidth - 1;
            }else if(x < 0){
                x = 0;
            }
            // checking the y-axis if it is in inside the old image
            if(y > oldHeight - 1){
                y = oldHeight - 1;
            }else if(y < 0){
                y = 0;
            }
            // setting the new image pixel
            newImage(i,j,0) = image(x,y,0);
            newImage(i,j,1) = image(x,y,1);
            newImage(i,j,2) = image(x,y,2);
        }
    }
    newImage.saveImage(filename);
    return newImage;
}

Image resizee_2(int x, int y, string filename){
    int newWidth = x, newHeight = y;

    Image image(filename);
    // creating a new image with the desired width and height
    Image newImage(newWidth,newHeight);
    int oldWidth = image.width,oldHeight = image.height;
    // getting the relative width and height
    float relativeWidth = (float)newWidth/image.width,relativeHeight = (float)newHeight/image.height;

    for(int i = 0;i < newImage.width;i++){
        for(int j = 0;j < newImage.height;j++){
            int x = floor((float)i/relativeWidth),y = floor((float)j/relativeHeight);
            // checking the x-axis if it is in inside the old image
            if(x > oldWidth - 1){
                x = oldWidth - 1;
            }else if(x < 0){
                x = 0;
            }
            // checking the y-axis if it is in inside the old image
            if(y > oldHeight - 1){
                y = oldHeight - 1;
            }else if(y < 0){
                y = 0;
            }
            // setting the new image pixel
            newImage(i,j,0) = image(x,y,0);
            newImage(i,j,1) = image(x,y,1);
            newImage(i,j,2) = image(x,y,2);
        }
    }
    newImage.saveImage(filename);
    return newImage;
}

int main() {
    string filename1, filename2, new_filename;
    cout << "Please enter the first image name: ";
    cin >> filename1;
    cout << "\n";
    cout << "Please enter the second image name: ";
    cin >> filename2;

    Image first_image(filename1);
    Image second_image(filename2);

    int NewHeight = max(first_image.height, second_image.height), NewWidth = max(first_image.width, second_image.width);
    Image final_image(NewWidth,NewHeight);
    if(first_image.width != second_image.width || first_image.height != second_image.height){
        resizee_2(NewWidth, NewHeight, filename1);
        resizee(NewWidth, NewHeight, filename2);
        Image NewImage_1(resizee_2(NewWidth, NewHeight, filename1));
        Image NewImage_2(resizee(NewWidth, NewHeight, filename2));
        int MidPoint = 0;
         for(int i = 0; i < NewWidth; i++){
            for(int j = 0; j < NewHeight; j++) {
                for (int k = 0; k < 3; k++) {
                    MidPoint = (NewImage_1(i, j, k) + NewImage_2(i, j, k)) / 2;
                    final_image(i, j, k) = MidPoint;
                }
            }
         }
    }
    else{
        int MidPoint = 0;
        for(int i = 0; i < first_image.width; i++){
            for(int j = 0; j < first_image.height; j++){
                for(int k = 0; k < 3; k++){
                    MidPoint = (first_image(i,j,k) + second_image(i,j,k))/2;
                    final_image(i,j,k) = MidPoint;
                }
            }
        }
    }
    cout << "Please enter image name to score new image\n";
    cout << "and specify extension .jpg .bmp .png .tga: ";

    cin >> new_filename;

    final_image.saveImage(new_filename);
    system(new_filename.c_str());

    return 0;
}
