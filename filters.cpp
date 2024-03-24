#include <iostream>
#include "Image_Class.h"
using namespace std;

// test

void blackAndWhite(){
    string filename;
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
}

void resize(){
    cout << "Enter the file name: " << endl;
    string filename;
    cin >> filename;

    cout << "New with and new height" << endl;
    int newWidth,newHeight;
    cin >> newWidth >> newHeight;

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
    cout << "enter new image name" << endl;
    cin >> filename;
    newImage.saveImage(filename);
}

void flip(){
    string filename;
    cout << "Enter filename: " << endl;
    cin >> filename;

    Image image(filename);

    cout << "1) horizontal" << endl << "2) vertical" << endl;
    int choice;
    try {
        while(true){
            cin >> choice;
            if(choice > 2 || choice < 1){
                continue;
            }
            if (cin.fail())
                throw "Please enter an integer";

            break;
        }
    }catch (exception &e){
        cout << e.what() << endl;
    }

    if(choice == 2){
        for(int i = 0;i < image.width;i++){
            for(int j = 0;j < image.height/2;j++){
                for(int k = 0;k < 3;k++){
                    int p = image(i,j,k);
                    image(i,j,k) = image(i,image.height - j - 1,k);
                    image(i,image.height - j - 1,k) = p;
                }
            }
        }
    }else{
        for(int i = 0;i < image.width/2;i++){
            for(int j = 0;j < image.height;j++){
                for(int k = 0;k < 3;k++){
                    int p = image(i,j,k);
                    image(i,j,k) = image(image.width - i - 1,j,k);
                    image(image.width - i - 1,j,k) = p;
                }
            }
        }
    }
    cout << "enter new filename" << endl;
    cin >> filename;
    image.saveImage(filename);
}

void crop(){
    // elephant.jpg
    string filename;
    cout << "Enter the filename:" << endl;
    cin >> filename;

    Image image(filename);

    cout << "Enter the from x and y: " << endl;
    int fromX,fromY;
    cin >> fromX >> fromY;

    cout << "Enter the to x and y: " << endl;
    int toX,toY;
    cin >> toX >> toY;

    Image newImage(toX - fromX + 1,toY - fromY + 1);
    int counterX = 0,counterY = 0;
    for(int i = fromX - 1;i < toX;i++){
        for(int j = fromY - 1;j < toY;j++){
            for(int k = 0;k < 3;k++){
                newImage(counterX,counterY,k) = image(i,j,k);
            }
            counterY++;
        }
        counterX++;
        counterY = 0;
    }
    cout << "please enter the file name you want the image to be saved as" << endl << "please specify the image type .jpg .bmp, .png, .tga:" << endl;
    cin >> filename;
    newImage.saveImage(filename);
}

int main(){
    crop();
    return 0;
}