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
#include <random>
#include "Image_Class.h"
#include <regex>
#include <cmath>
#include <bits/stdc++.h>
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
    choice = taking_choice(2);

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

    cout << "New width and new height" << endl;
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

    cout << "Enter new width: " << endl;
    int width,height;
    cin >> width;
    while(width <= 0 || width > image.width - fromX){
        cout << "Enter new width: " << endl;
        cin >> width;
    }
    cout << "Enter new height: " << endl;
    cin >> height;
    while(height <= 0 || height > image.height - fromY){
        cout << "Enter new height: " << endl;
        cin >> height;
    }
    Image newImage(width,height);
    int counterX = 0,counterY = 0;
    for(int i = fromX; i < fromX + width && i < image.width; i++){
        for(int j = fromY; j < fromY + height && j < image.height; j++){
            for(int k = 0; k < 3; k++){
                newImage(counterX,counterY,k) = image(i,j,k);
            }
            counterY++;
        }
        counterX++;
        counterY = 0; // Reset counterY for the next row
    }
    return newImage;
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

Image Purple(Image& image){
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
    return final_image;
}

Image infrared(Image& image) {
    for(int i = 0;i < image.width;i++){
        for(int j = 0;j < image.height;j++){
            image(i,j,0) = 255;
            int intenisty = (image(i,j,1)+image(i,j,2))/2;
            image(i,j,1) = 255 - intenisty;
            image(i,j,2) = 255 - intenisty;
        }
    }
    return image;
}
// Function to apply Sepia Tone filter to the image
Image SepiaTone( Image& ogImage) {
    int width = ogImage.width,height = ogImage.height;
    Image image = ogImage;
    int newR, newG, newB;

    // Iterate over each pixel in the image
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            // For each pixel, calculate new RGB values based on the sepia tone effect
            for (int k = 0; k < 3; k++) {
                int PixelValue = image(i, j, k);
                if (k == 0) {
                    // Calculate new Red value
                    newR = min(255, (int)(0.393 * PixelValue + 0.769 * image(i, j, 1) + 0.189 * image(i, j, 2)));
                }
                else if (k == 1) {
                    // Calculate new Green value
                    newG = min(255, (int)(0.349 * image(i, j, 0) + 0.686 * PixelValue + 0.168 * image(i, j, 2)));
                }
                else {
                    // Calculate new Blue value
                    newB = min(255, (int)(0.272 * image(i, j, 0) + 0.534 * image(i, j, 1) + 0.131 * PixelValue));
                }
            }

            // Update the pixel with the new RGB values
            image(i, j, 0) = newR;
            image(i, j, 1) = newG;
            image(i, j, 2) = newB;
        }
    }
    return image;
}\
// Function to apply the Night Mood filter to the image
Image NightMood(Image& ogImage) {
    Image image = ogImage;
    int width = image.width,height = image.height;
    // Iterate over each pixel in the image
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++){
            // Iterate over each color channel (R, G, B) of the pixel
            for (int k = 0; k < 3; k++){

                // Retrieve the pixel value for the current channel
                int PixelValue = image(i,j,k);

                // Apply different multipliers to each channel to achieve the night mood effect
                if(k == 0) { // Red channel
                    PixelValue *= 0.5; // Reduce intensity by 50%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    image(i,j,0) = PixelValue; // Update the pixel value for the Red channel
                }
                else if (k == 1) { // Green channel
                    PixelValue *= 0.5; // Reduce intensity by 50%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    image(i,j,1) = PixelValue; // Update the pixel value for the Green channel
                }
                else {
                    // Blue channel
                    PixelValue *= 0.7; // Reduce intensity by 30%
                    PixelValue = max(0, min(PixelValue, 255)); // Ensure the value stays within valid range
                    image(i,j,2) = PixelValue; // Update the pixel value for the Blue channel
                }
            }
        }
    }
    return image;
}
// Function to rotate the image clockwise by 90 degrees
Image rotateImage90(Image& image) {
    int r = image.width;
    int c = image.height;
    Image rotated(c, r); // Create a new image with dimensions swapped

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotated(c - 1 - j, i, k) = image(i, j, k); // Correct indices for clockwise rotation
            }
        }
    }

    return rotated;
}

// Function to rotate the image clockwise by 180 degrees
Image rotateImage180(Image& image) {
    int r = image.width;
    int c = image.height;
    Image rotated(r, c); // Create a new image with the same dimensions

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotated(i, j, k) = image(r - 1 - i, c - 1 - j, k); // Correct indices for 180-degree rotation
            }
        }
    }

    return rotated;
}

// Function to rotate the image clockwise by 270 degrees
Image rotateImage270(Image& image) {
    int r = image.width;
    int c = image.height;
    Image rotated(c, r);

    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            for (int k = 0; k < 3; ++k) {
                rotated(j, r - 1 - i, k) = image(i, j, k); // Correct indices for clockwise rotation
            }
        }
    }

    return rotated;
}

Image Rotate(Image image){

    int choice;
    do {
        cout << "Choose rotation angle:" << endl;
        cout << "1. 90 degrees" << endl;
        cout << "2. 180 degrees" << endl;
        cout << "3. 270 degrees" << endl;
        cout << "Enter your choice(1-3): ";
        cin >> choice;

        switch (choice) {
            case 1:
                image = rotateImage90(image);
                break;
            case 2:
                image = rotateImage180(image);
                break;
            case 3:
                image = rotateImage270(image);
                break;
            default:
                cout << "Invalid choice. Please enter a valid option." << endl;
                break;
        }
    } while (choice != 4 && choice != 1&& choice != 2 && choice != 3);
    return image;
}
void BlackAndWhite(Image& image)
{
    for(int i = 0; i < image.width; i++){
        for(int j = 0; j < image.height; j++){
            // Calculate average intensity value across RGB channels
            int avg = 0;
            for(int k = 0; k < 3; k++){
                avg += image(i, j, k);
            }
            avg /= 3;
            // Threshold to binary (black and white)
            avg = (avg > 127 ? 255 : 0);
            // Set RGB values to the same value to convert to grayscale
            image(i, j, 0) = avg;
            image(i, j, 1) = avg;
            image(i, j, 2) = avg;
        }
    }
}

// Function for edge detection
Image EdgeDetection(Image image)
{
    // Convert image to black and white
    BlackAndWhite(image);
    int width = image.width,height = image.height;
    // Perform edge detection
    for(int i = 0; i < width - 1; i++){
        for(int j = 0; j < height - 1; j++){
            for(int k = 0; k < 3; k++){
                // Compute differences in vertical and horizontal directions
                int diffV = abs(image(i, j, k) - image(i + 1, j, k)); // Vertical difference
                int diffH = abs(image(i, j, k) - image(i, j + 1, k)); // Horizontal difference
                // Compute gradient magnitude using Euclidean distance
                int res = sqrt(diffV * diffV + diffH * diffH);
                // Apply thresholding
                int constant = 100; // Threshold constant (adjust as needed)
                image(i, j, k) = res > constant ? 0 : 255; // Set pixel to black or white based on threshold
            }
        }
    }
    return image;
}

Image sunLight(Image image){

    Image sunlightImage(image.width, image.height);

    // Apply sunlight effect to the image
    for (int i = 0; i < image.width; i++) {
        for (int j = 0; j < image.height; j++) {
            // Adjust pixel values for sunlightImage effect
            sunlightImage(i,j,0) = min(image(i,j,0) + 30, 255);
            sunlightImage(i,j,1) = min(image(i,j,1) + 30, 255);
            sunlightImage(i,j,2) = max(0, image(i,j,2) - 50);
        }
    }
    return sunlightImage;
}

// Function to apply vertical skew effects to an image
Image applyVerticalSkew(Image& image) {
    double angleOfSkew;
    cout << "Enter the angle of skewness along the vertical axis (in degrees): ";
    cin >> angleOfSkew;
    // Convert the angle from degrees to radians
    double angleRad = angleOfSkew * M_PI / 180.0;

    // Calculate the new width and height after skewing
    int newWidth = round(image.width + tan(angleRad) * image.height);
    int newHeight = image.height;

    // Create a new image with the skewed dimensions
    Image skewedImage(newWidth, newHeight);

    // Apply skew transformation to each pixel
    for (int y = 0; y < newHeight; ++y) {
        for (int x = 0; x < newWidth; ++x) {
            // Calculate the corresponding position in the original image after skewing
            int origX = round(x - tan(angleRad) * (newHeight - y));

            // Check if the original position is within bounds
            if (origX >= 0 && origX < image.width && y >= 0 && y < image.height) {
                // Get the color values from the original position and set them in the skewed image
                for (int c = 0; c < image.channels; ++c) {
                    skewedImage(x, y, c) = image(origX, y, c);
                }
            }
        }
    }
    // Update the original image with the skewed version
    return skewedImage;
}

// Function to apply box blur to an image using a specified kernel size
Image applyBoxBlur(Image& image) {
    int kernelSize;
    cout << "Enter the kernel size for box blur: ";
    cin >> kernelSize;
    int width = image.width;
    int height = image.height;
    int channels = image.channels;

    // Create a temporary image to store the blurred result
    Image blurredImage(width, height);

    // Apply box blur using the specified kernel size
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int c = 0; c < channels; ++c) {
                int sum = 0;
                int count = 0;
                for (int k = -kernelSize; k <= kernelSize; ++k) {
                    for (int l = -kernelSize; l <= kernelSize; ++l) {
                        int x = max(0, min(width - 1, i + k));
                        int y = max(0, min(height - 1, j + l));
                        sum += image(x, y, c);
                        count++;
                    }
                }
                blurredImage(i, j, c) = sum / count; // Average of the pixel values in the kernel
            }
        }
    }
    return blurredImage;
}

Image tvEffect(Image image){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dis(0, 30);
    int width = image.width;
    int height = image.height;

    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            int random = dis(gen); // Random value for each pixel

            for (int k = 0; k < image.channels; ++k) {
                if (i % 2 == 0) { // Even row
                    int newValue = image(i, j, k) - random;
                    image(i, j, k) = (newValue < 0) ? 0 : newValue;
                } else { // Odd row
                    int newValue = image(i, j, k) + random;
                    image(i, j, k) = (newValue > 255) ? 255 : newValue;
                }
            }
        }
    }
    return image;
}

void setColorForFrame(Image& image, int startX, int startY, int endX, int endY, int r, int g, int b) {
    for (int i = startX; i < endX; ++i) {
        for (int j = startY; j < endY; ++j) {
            image(i, j, 0) = r;
            image(i, j, 1) = g;
            image(i, j, 2) = b;
        }
    }
}

// Function to create a simple frame with a specified color
void createSimpleFrame(Image& image) {
    string color;
    cout << "Enter the color for the frame (red, green, blue, etc.): ";
    cin >> color;

    int rValue, gValue, bValue;
    if (color == "red") {
        rValue = 255;
        gValue = 0;
        bValue = 0;
    } else if (color == "green") {
        rValue = 0;
        gValue = 255;
        bValue = 0;
    } else if (color == "blue") {
        rValue = 0;
        gValue = 0;
        bValue = 255;
    }
    // Add more else-if conditions for other colors...

    setColorForFrame(image, 0, 0, 5, image.height, rValue, gValue, bValue);
    setColorForFrame(image, image.width - 5, 0, image.width, image.height, rValue, gValue, bValue);
    setColorForFrame(image, 0, 0, image.width, 5, rValue, gValue, bValue);
    setColorForFrame(image, 0, image.height - 5, image.width, image.height, rValue, gValue, bValue);
}

// Function to create a fancy frame with gradient colors
void createFancyFrame(Image &image) {
    int startColorR = 255;  // Red
    int startColorG = 0;
    int startColorB = 0;
    int endColorR = 0;      // Blue
    int endColorG = 0;
    int endColorB = 255;

    int frameSize = 10;

    setColorForFrame(image, 0, 0, frameSize, image.height, startColorR, startColorG, startColorB);
    setColorForFrame(image, image.width - frameSize, 0, image.width, image.height, endColorR, endColorG, endColorB);
    setColorForFrame(image, 0, 0, image.width, frameSize, startColorR, startColorG, startColorB);
    setColorForFrame(image, 0, image.height - frameSize, image.width, image.height, endColorR, endColorG, endColorB);
}

Image frame(Image image){
    int choice;
    cout << "Choose the type of frame to add:" << endl;
    cout << "1. Simple Frame" << endl;
    cout << "2. Fancy Frame" << endl;
    cout << "Enter your choice (1 or 2): ";
    choice = taking_choice(2);

    switch (choice) {
        case 1:
            createSimpleFrame(image);
            break;
        case 2:
            createFancyFrame(image);
            break;
        default:
            cout << "Invalid choice. No frame added." << endl;
            break;
    }
    return image;
}

int main(){
    cout << "Welcome to image filters app\nChose a filter to start: \n";
    int choice;
    Image image;
    string filename;
    load_image(image,filename);
    bool saved = false;
    while(true){
        cout << "1) Load a new image\n2) Grayscale Conversion\n3) Black and White\n4) Invert\n5) Merge Images\n6) Flip \n7) Rotate Image \n8) Brightness\n9) Crop \n10) Adding Frame\n11) Detect edges \n12) Resize \n13) Blur \n14) SunLight \n15) Oil paint image \n16) TV effect \n17) Purple\n18) Infrared\n19) Skew \n20) Sepia Tone \n21) Night Mood\n22) Save the image\n23) Exit" << endl;
        choice = taking_choice(23);
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
            image = Rotate(image);
        }else if(choice == 8){
            saved = false;
            image = brightness(image);
        }else if(choice == 9){
            saved = false;
            image = crop(image);
        }else if(choice == 10){
            saved = false;
            // image = frame(image);
        }else if(choice == 11){
            saved = false;
            image = EdgeDetection(image);
        }else if(choice == 12){
            saved = false;
            image = resize(image);
        }else if(choice == 13){
            saved = false;
            image = applyBoxBlur(image);
        }else if(choice == 14){
            saved = false;
            image = sunLight(image);
        }else if(choice == 15){
            saved = false;
            image = applyOilPaintFilter(image);
        }else if(choice == 16){
            saved = false;
            image = tvEffect(image);
        }else if(choice == 17){
            saved = false;
            image = Purple(image);
        }else if(choice == 18){
            saved = false;
            image = infrared(image);
        }else if(choice == 19){
            saved = false;
            image = applyVerticalSkew(image);
        }else if(choice == 20){
            saved = false;
            image = SepiaTone(image);
        }else if(choice == 21){
            saved = false;
            image = NightMood(image);
        }else if(choice == 22){
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