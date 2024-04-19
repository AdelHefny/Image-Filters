#include <iostream>
#include <vector>
#include "Image_Class.h"

using namespace std;

// Function to apply box blur to an image using a specified kernel size
void calculatePrefixSum(const Image& image, vector<vector<vector<int>>>& prefixSum) {
    int width = image.width;
    int height = image.height;
    int channels = image.channels;

    prefixSum.resize(width, vector<vector<int>>(height, vector<int>(channels)));

    // Calculate prefix sum for each channel
    for (int c = 0; c < channels; ++c) {
        // Calculate prefix sum for the first row
        for (int i = 0; i < width; ++i) {
            prefixSum[i][0][c] = image(i, 0, c);
        }

        // Calculate prefix sum for the first column
        for (int j = 0; j < height; ++j) {
            prefixSum[0][j][c] = image(0, j, c);
        }

        // Calculate prefix sum for the rest of the image
        for (int i = 1; i < width; ++i) {
            for (int j = 1; j < height; ++j) {
                prefixSum[i][j][c] = image(i, j, c) + prefixSum[i - 1][j][c] + prefixSum[i][j - 1][c] - prefixSum[i - 1][j - 1][c];
            }
        }
    }
}

// Function to apply box blur to an image using a specified kernel size
void applyBoxBlur(Image& image, int kernelSize) {
    int width = image.width;
    int height = image.height;
    int channels = image.channels;

    // Create a temporary image to store the blurred result
    Image blurredImage(width, height);

    // Calculate prefix sum of the original image
    vector<vector<vector<int>>> prefixSum;
    calculatePrefixSum(image, prefixSum);

    // Apply box blur using the prefix sum
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int c = 0; c < channels; ++c) {
                int x1 = max(0, i - kernelSize);
                int y1 = max(0, j - kernelSize);
                int x2 = min(width - 1, i + kernelSize);
                int y2 = min(height - 1, j + kernelSize);
                int count = (x2 - x1 + 1) * (y2 - y1 + 1);
                int sum = prefixSum[x2][y2][c] - (x1 > 0 ? prefixSum[x1 - 1][y2][c] : 0) - (y1 > 0 ? prefixSum[x2][y1 - 1][c] : 0) + (x1 > 0 && y1 > 0 ? prefixSum[x1 - 1][y1 - 1][c] : 0);
                blurredImage(i, j, c) = sum / count; // Average of the pixel values in the kernel
            }
        }
    }

    // Copy the blurred image back to the original image
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            for (int c = 0; c < channels; ++c) {
                image(i, j, c) = blurredImage(i, j, c);
            }
        }
    }
}

int main() {
    string filename;
    cout << "Enter the image filename: ";
    cin >> filename;

    // Load the image from file
    Image image(filename);

    // Input kernel size for box blur
    int kernelSize;
    cout << "Enter the kernel size for box blur: ";
    cin >> kernelSize;

    // Apply box blur to the loaded image
    applyBoxBlur(image, kernelSize);

    // Save the blurred image
    image.saveImage("blurred_image.jpg");

    cout << "Blurred image saved successfully." << endl;

}
