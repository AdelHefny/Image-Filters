//  Assignment 3, Task 1
//  program :   This program is a collection of 5 filers required in the assignment  with a menu interface
//  to make the user choose the filter he wants and save them
//
//  Authors :
//  Name                           |      id       |      Problems
//  Ahmed Mohamed Mahmoud Ahmed    |   20230598    |  filter 3
//
//  Adel ahmed Mohamed El hefny    |   20230198    |  filter 2,5
//
//  Ahmed Mohamed Noureldin Ahmed  |   20230035    |  filter 1,4
//
//  Emails:
//  adelahmedhefny@gmail.com
//  ahmednourr278@gmail.com
//  ahmedabdellatif5355@gmail.com
//
//  version: 1.0.0
//  Date : 27/3/2024

#include <iostream>
#include "Image_Class.h"
#include <regex>
using namespace std;

void load_image(Image &image,string &filename){
    while(true){
        cout << "Enter the filename:" << endl;
        cin >> filename;
        if(!regex_match(filename,regex("^[a-zA-Z1-9]+\\.(PNG|png|BMP|bmp|JPG|jpg|TGA|tga)$"))){
            cout << "invalid path" << endl;
            continue;
        }
        try{
            image.loadNewImage(filename);
        } catch(exception& e) {
            cout << e.what() << endl;
            continue;
        }
        break;
    }
}

int taking_choice(int range){
    int choice;
    while(true){
        try {
            cout << "Enter your choice:";
            cin >> choice;
            if (cin.fail()) {
                cin.clear(); // Clear the fail state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard remaining characters
                throw runtime_error("Invalid input. Please enter an integer.");
            }
        } catch (exception& e) {
            cout << e.what() << endl; // Print error message
        }
        if(choice < 1 || choice > range){
            cout << "choice must be in range of 1 and " << range << endl;
            continue;
        }
        break;
    }
    return choice;
}
void savingImage(Image& newImage,string& filename){
    cout << "1) save in current image\n" << "2) enter new image filename\n";
    int choice = taking_choice(2);
    if(choice == 1){
        newImage.saveImage(filename);
    }else{
        while(true){
            cout << "please enter the file name you want the image to be saved as " << endl;
            cout << "please specify the image type .jpg .bmp, .png, .tga:" << endl;
            cin >> filename;
            if(regex_match(filename,regex("^[a-zA-Z1-9]+\\.(PNG|png|BMP|bmp|JPG|jpg|TGA|tga)$"))){
                newImage.saveImage(filename);
            }else{
                continue;
            }
            break;
        }
    }
    // Open the saved image using the default system viewer
    system(filename.c_str());
}
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
    // saving the resized image
    newImage.saveImage(filename);
    return newImage;
}

// Function to resize an image (second version)
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
    // saving the resized image
    newImage.saveImage(filename);
    return newImage;
}

Image merge(const Image& image,const string& filename1){
    string filename2;

    Image first_image = image;

    Image second_image;

    load_image(second_image,filename2);
    // Determine dimensions of the final image
    int NewHeight = max(first_image.height, second_image.height), NewWidth = max(first_image.width, second_image.width);
    Image final_image(NewWidth,NewHeight);

    // If dimensions of images are different, resize them
    if(first_image.width != second_image.width || first_image.height != second_image.height){
        resizee_2(NewWidth, NewHeight, filename1);
        resizee(NewWidth, NewHeight, filename2);
        Image NewImage_1(resizee_2(NewWidth, NewHeight, filename1));
        Image NewImage_2(resizee(NewWidth, NewHeight, filename2));
        int MidPoint = 0;
        for(int i = 0; i < NewWidth; i++){
            for(int j = 0; j < NewHeight; j++) {
                for (int k = 0; k < 3; k++) {
                    // Average RGB values of corresponding pixels
                    MidPoint = (NewImage_1(i, j, k) + NewImage_2(i, j, k)) / 2;
                    final_image(i, j, k) = MidPoint;
                }
            }
        }
    }
        // If dimensions are same, merge images directly
    else{
        int MidPoint = 0;
        for(int i = 0; i < first_image.width; i++){
            for(int j = 0; j < first_image.height; j++){
                for(int k = 0; k < 3; k++){
                    // Average RGB values of corresponding pixels
                    MidPoint = (first_image(i,j,k) + second_image(i,j,k))/2;
                    final_image(i,j,k) = MidPoint;
                }
            }
        }
    }
    return final_image;
}

Image brightness(Image image){
    int choice;
    cout << "DO YOU WANT TO INCREASE THE BRIGHTNESS OR DECREASE IT BY 50%?\n";
    cout << "1) Increase the brightness          2) Decrease the brightness: ";
    cin >> choice;

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
    return final_image;
}
Image gray_scale(Image image){
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
    return image;
}
Image blackAndWhite(Image image){
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
    return image;
}

Image resize(Image image){

    cout << "New with and new height" << endl;
    int newWidth,newHeight;
    cin >> newWidth >> newHeight;

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
    return newImage;
}

Image flip(Image image){
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
    return image;
}

Image crop(Image image){
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
    return image;
}

Image invert(Image image){
    int r = image.width; // Get the width of the image
    int c = image.height; // Get the height of the image

    for (int i = 0; i < r; ++i){ // Loop through each row of the image
        for (int j = 0; j < c ; ++j){ // Loop through each column of the image
            for (int k = 0; k < 3; ++k){ // Loop through each color channel (RGB)
                image(i, j, k) = 255 - image(i, j, k) ; // Invert the pixel value for each color channel
            }
        }
    }

    return image; // return the image
}
Image applyOilPaintFilter(Image& image) {
    int radius = 5;
    Image new_image(image.width,image.height);
    for(int i = 0;i < image.width;i++){
        for(int j = 0;j < image.height;j++){
            vector<int> intenistyLevels(255),averageR(255),averageG(255),averageB(255);
            int maxIntenisty = 0;
            int beginRaw = max(0,i-radius),endRaw = min(i+radius,image.width-1);
            int beginCol = max(0,j-radius),endCol = min(j+radius,image.height-1);
            for(int k = beginRaw;k <= endRaw;k++){
                for(int l = beginCol;l <= endCol;l++){
                    int intenisty = (image(k,l,0)+image(k,l,1)+image(k,l,2))/3;
                    intenistyLevels[intenisty]++;
                    averageR[intenisty] += image(k,l,0);
                    averageG[intenisty] += image(k,l,1);
                    averageB[intenisty] += image(k,l,2);
                }
            }
            int maxIndex;
            for(int k = 0;k < 255;k++){
                if(maxIntenisty < intenistyLevels[k]){
                    maxIntenisty = intenistyLevels[k];
                    maxIndex = k;
                }
            }
            new_image(i,j,0) = averageR[maxIndex]/maxIntenisty;
            new_image(i,j,1) = averageG[maxIndex]/maxIntenisty;
            new_image(i,j,2) = averageB[maxIndex]/maxIntenisty;
        }
    }
    return new_image;
}
int main(){
    cout << "Welcome to image filters app\nChose a filter to start: \n";
    int choice;
    Image image;
    string filename;
    load_image(image,filename);
    bool saved = false;
    while(true){
        cout << "1) Load a new image\n2) Grayscale Conversion\n3) Black and White\n4) Invert\n5) Merge Images\n6) Flip Image\n7) Oil paint image\n8) Save the image\n9) Exit" << endl;
        choice = taking_choice(9);
        if(choice == 1){
            if(!saved){
                cout << "1) Do you want to save ?\n2) Continue" << endl;
                choice = taking_choice(2);
                if(choice == 1){
                    savingImage(image,filename);
                }
            }
            load_image(image,filename);
        }else if(choice == 2){
            saved = false;
            image = gray_scale(image);
        }else if(choice == 3){
            saved = false;
            image = blackAndWhite(image);
        }else if(choice == 4){
            saved = false;
            image = invert(image);
        }else if(choice == 5){
            saved = false;
            image = merge(image,filename);
        }else if(choice == 6){
            saved = false;
            image = flip(image);
        }else if(choice == 7){
            saved = false;
            image = applyOilPaintFilter(image);
        }else if(choice == 8){
            saved = true;
            savingImage(image,filename);
        }else{
            if(!saved){
                cout << "1) Do you want to save ?\n2) Exit" << endl;
                choice = taking_choice(2);
                if(choice == 1){
                    savingImage(image,filename);
                }
                break;
            }else{
                break;
            }
        }
    }
    return 0;
}