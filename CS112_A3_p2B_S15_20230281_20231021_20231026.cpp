//Name: Asmaa Hussein Omar
//ID: 20231021
//Section num: S15
//filters : 2 , 5 ,8 ,11 , 14
//email : asmaahlal123456789@gmail.com

//Name: Amany Hussein Mousa
//ID: 20231026
//Section num: S15
//filters : 3 - 6 - 9 -12 - 13
//email : amanyhussein2467@gmail.com

//Name: Fatma Abd Elnaser Abd Elasis Marei
//ID: 20230281
//Section num: S15
//filters :  1 - 4 - 7 - 10 -15
//email : fatmaabdelnaser95@gmail.com

//https://github.com/AsmaaHussein05/assignment3

/*program description: Grayscale Conversion: Converts a colored image to grayscale by averaging the RGB channels.
Black and White Conversion: Converts a colored image to black and white by setting pixel values to either black or
white based on the average grayscale value.
Invert Colors: Inverts the colors of a colored image by subtracting each color value from 255.
Rotate Image: Allows users to rotate an image by 90, 180, or 270 degrees clockwise.
Brighten and Darken: Provides options to either brighten or darken a colored image by adjusting pixel values accordingly.*/


#include <iostream>
#include <string>
#include "Image_Class.h"
using namespace std;

Image Resize_Img(Image& image) {
    float wdth, hgt;

    bool validWidth = false;
    while (!validWidth) {
        cout << "Enter the new width: ";
        cin >> wdth;
        if (wdth > 0) {
            validWidth = true;
        } else {
            cerr << "Error: Width must be a positive number." << endl;
        }
    }

    bool validHeight = false;
    while (!validHeight) {
        cout << "Enter the new height: ";
        cin >> hgt;
        if (hgt > 0) {
            validHeight = true;
        } else {
            cerr << "Error: Height must be a positive number." << endl;
        }
    }

    Image new_img(wdth, hgt);

    float scl_w = (float) image.width / wdth;
    float scl_h = (float) image.height / hgt;

    for (int y = 0; y < wdth; ++y) {
        for (int a = 0; a < hgt; ++a) {
            int pos_x = round(scl_w * y);
            int pos_y =  round(scl_h * a);

            for (int k = 0; k < 3; ++k) {
                new_img(y, a, k) = image(pos_x, pos_y, k);
            }
        }
    }

    return new_img;
}



void blackandwhite(Image&image) {

    // Get the width and height of the image
    int width = image.width;
    int height = image.height;

    // Convert the image to black and white
    for (int i = 0; i < width; ++i) {
        for (int j = 0; j < height; ++j) {
            unsigned int sum = 0;

            // Calculate the sum of grayscale values in all channels
            for (int k = 0; k < 3; ++k) { // Loop over 3 channels only (0, 1, 2)
                sum += image(i, j, k);
            }

            // Calculate the average grayscale value
            unsigned int average = sum / 3;

            // Set the pixel values to black or white based on the average grayscale value
            for (int k = 0; k < 3; ++k) { // Loop over 3 channels only (0, 1, 2)
                if (average < 128) {
                    // Set pixel to black
                    image(i, j, k) = 0;
                } else {
                    // Set pixel to white
                    image(i, j, k) = 255;
                }
            }
        }
    }
}



// Invert image filter
void inverted(Image&image) {

    // Loop through each pixel of the image
    for (int a = 0; a < image.width; ++a) {
        for (int z = 0; z < image.height; ++z) {
            // Loop through each color channel (RGB)
            for (int k = 0; k < 3; ++k) {
                // Invert the color of each pixel by subtracting the current color value from 255
                image(a, z, k) = 255 - image(a, z, k);
            }
        }
    }

}



// Function to rotate the image 90 degrees clockwise
Image rotateImage90(Image&image) {

    Image rotatedImage(image.height, image.width);

    // Loop through each pixel in the original image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                // Rotate the pixel and assign it to the rotated image
                rotatedImage(image.height - j, i , k) = image(i, j, k);
            }
        }
    }
    // Return the rotated image
    return rotatedImage;
}

// Function to rotate the image 180 degrees clockwise
Image rotateImage180(Image&image) {

    Image rotatedImage(image.width, image.height);

    // Loop through each pixel in the original image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                // Rotate the pixel and assign it to the rotated image
                rotatedImage(image.width - 1 - i, image.height - 1 - j, k) = image(i, j, k);
            }
        }
    }
    // Return the rotated image
    return rotatedImage;
}

// Function to rotate the image 270 degrees clockwise
Image rotateImage270(Image& image) {
    Image rotatedImage(image.height, image.width);

    // Loop through each pixel in the original image
    for (int i = 0; i < image.width; ++i) {
        for (int j = 0; j < image.height; ++j) {
            for (int k = 0; k < image.channels; ++k) {
                // Rotate the pixel and assign it to the rotated image
                rotatedImage(j, image.width - 1 - i, k) = image(i, j, k);
            }
        }
    }

    // Return the rotated image
    return rotatedImage;
}


void rotateImage(Image& image) {
    // Loop to allow multiple rotations or exit
    while (true) {
        int choice;
        cout << "Choose an option:" << endl;
        cout << "1. Rotate 90 degrees" << endl;
        cout << "2. Rotate 180 degrees" << endl;
        cout << "3. Rotate 270 degrees" << endl;
        cout << "4. End the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            // Clear error state
            cin.clear();
            // Ignore invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Display error message
            cout << "Invalid input. Please enter a number between 1 and 4.\n";
            continue; // Skip to the next iteration of the loop
        }

        // Clear input buffer
        while (cin.get() != '\n')
            continue;

        // Perform rotation based on user's choice
        switch (choice) {
            case 1:
                image =  rotateImage90(image);
                break;
            case 2:
                image = rotateImage180(image);
                break;
            case 3:
                image =  rotateImage270(image);
                break;
            case 4:
                cout << "Exiting program. Goodbye!\n";
                return; // Exit the program
            default:
                cout << "Invalid choice" << endl;
                continue; // Go to the next iteration of the loop
        }
    }
}

#include <cmath>

Image detect_image(Image& image){

    for(int i = 0; i < image.width; ++i) {
        for (int g = 0; g < image.height; ++g) {

            unsigned int avg = 0;

            for (int k = 0; k < 3; ++k) { // Loop over 3 channels only (0, 1, 2)
                avg += image(i, g, k);
            }
            avg /= 3;

            for(int k = 0; k < 3;++k){
                image(i,g,k) = avg;
            }
        }
    }

    Image edges (image.width, image.height);

    for(int i = 1; i < image.width - 1; ++i) {
        for (int g = 1; g < image.height - 1; ++g) {

            int horizontalGradient =
                    (-1 * image(i - 1, g - 1, 0)) + (0 * image(i - 1, g, 0)) +
                    (1 * image(i - 1, g + 1, 0)) +(-2 * image(i, g - 1, 0)) +
                    (0 * image(i, g, 0)) + (2 * image(i, g + 1, 0)) +
                    (-1 * image(i + 1, g - 1, 0)) + (0 * image(i + 1, g, 0)) +
                    (1 * image(i + 1, g + 1, 0));

            int verticalGradient =
                    (-1 * image(i - 1, g - 1, 0)) + (-2 * image(i - 1, g, 0)) +
                    (-1 * image(i - 1, g + 1, 0)) + (0 * image(i, g - 1, 0)) +
                    (0 * image(i, g, 0)) + (0 * image(i, g + 1, 0)) +
                    (1 * image(i + 1, g - 1, 0)) + (2 * image(i + 1, g, 0)) +
                    (1 * image(i + 1, g + 1, 0));

            int gradient = sqrt((horizontalGradient * horizontalGradient) + (verticalGradient * verticalGradient));
            if (gradient > 128){
                for(int k = 0; k < 3; ++k){
                    edges(i,g,k) = 0;
                }
            }else{
                for(int k = 0; k < 3; ++k){
                    edges(i,g,k) = 255;
                }
            }

        }
    }

    return edges;

}

// Function to convert an image to grayscale
void grayscale(Image&image) {

    // Convert the image to grayscale
    for (int i = 0; i < image.width; ++i) {
        for (int g = 0; g < image.height; ++g) {
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k) {
                avg += image(i, g, k);
            }
            avg /= 3;
            image(i, g, 0) = avg;
            image(i, g, 1) = avg;
            image(i, g, 2) = avg;
        }
    }

}


void brighten(Image&image) {

    for(int i = 0; i < image.width; ++i) {
        for(int g = 0; g < image.height; ++g) {
            for(int k = 0; k < 3; ++k) {
                int new_value = (3 * image(i, g, k)) / 2;
                if (new_value > 255) {
                    image(i, g, k) = 255;
                } else {
                    image(i, g, k) = new_value;
                }
            }
        }
    }
}


void darken(Image&image) {

    // Reduce the brightness of the image
    for(int i = 0; i < image.width; ++i) {
        for(int g = 0; g < image.height; ++g) {
            image(i, g, 0) -= image(i, g, 0) / 2;
            image(i, g, 1) -= image(i, g, 1) / 2;
            image(i, g, 2) -= image(i, g, 2) / 2;
        }
    }
}


void brithenanddarken(Image& image) {
    // Loop to allow multiple rotations or exit
    while (true) {
        int choice;
        cout << "Choose an option:" << endl;
        cout << "1. for brighten" << endl;
        cout << "2. for darken" << endl;

        cout << "3. End the program" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();


        if (cin.fail()) {
            // Clear error state
            cin.clear();
            // Ignore invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Display error message
            cout << "Invalid input. Please enter a number between 1 and 7.\n";
            continue; // Skip to the next iteration of the loop
        }


        // Perform rotation based on user's choice
        switch (choice) {
            case 1:
                brighten(image);
                break;
            case 2:
                darken(image);
                break;
            case 3:
                cout << "Exiting program. Goodbye!\n";
                return; // Exit the program
            default:
                cout << "Invalid choice" << endl;
                continue; // Go to the next iteration of the loop
        }

    }

}

// Function to show integer input
int getValidIntegerInput(const string& prompt, int lowerBound, int upperBound) {
    int input;
    while (true) {
        cout << prompt;
        if (!(cin >> input)) { // Check if input is not an integer
            cout << "Invalid input. Please enter a valid integer." << endl;
            cin.clear(); // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input


        } else if (input < lowerBound || input > upperBound) { // Check if input is within bounds


            cout << "Input out of bounds. Please enter a number between " << lowerBound << " and " << upperBound << "." << endl;
        } else {
            break; // Input is valid
        }
    }
    return input;
}
// function to drive cropping an image
void Crop_Img(Image& image) {
    // Get image dimensions
    int original_width = image.width;
    int original_height = image.height;

    // Variables to store cropping dimensions
    int x, y, width, height;

    // Ask the user for cropping dimensions until true dimensions are provided
    x = getValidIntegerInput("Enter the point (x) of the upper-left corner : ", 0, original_width);
    y = getValidIntegerInput("Enter the point (y) of the upper-left corner : ", 0, original_height);
    width = getValidIntegerInput("Enter the width to crop: ", 1, original_width - x);
    height = getValidIntegerInput("Enter the height to crop: ", 1, original_height - y);

    // Create a new image to store the cropped area
    Image cropped_image(width, height);

    // Copy pixels from the original image to the cropped image
    for (int g = 0; g < width; ++g) {
        for (int h = 0; h < height; ++h) {
            // Check bounds to avoid segmentation fault
            if (x + g < original_width && y + g < original_height) {
                cropped_image(g, h, 0) = image.getPixel(x + g, y + h, 0);
                cropped_image(g, h, 1) = image.getPixel(x + g, y + h, 1);
                cropped_image(g, h, 2) = image.getPixel(x + g, y + h, 2);
            }
        }
    }
    image = cropped_image; // Assign the cropped image back to the original image
}


void Flip(Image & image){
    while(true) {
        cout << "To flip the image:\n1) Horizontally\n2) Vertically\n";
        cout << "Enter your choice (1 or 2): ";
        string choice;
        cin >> choice;

        if (choice == "1") {
            unsigned int temp;
            for (int h = 0; h < image.height; ++h) {
                for (int l = 0; l < image.width / 2; ++l) { // Only go up to half the width
                    for (int p = 0; p < 3; ++p) {
                        // Swap pixels from the two sides of the image horizontally
                        temp = image(l, h, p);
                        image(l, h, p) = image(image.width - 1 - l, h, p);
                        image(image.width - 1 - l, h, p) = temp;
                    }
                }
            }
            break; // Exit the loop if choice is valid
        } else if (choice == "2") {
            unsigned int temp;
            for (int g = 0; g < image.width; ++g) { // Only go up to half the width
                for (int o = 0; o < image.height / 2; ++o) {
                    for (int d = 0; d < 3; ++d) {
                        // Swap pixels from the two sides of the image horizontally
                        temp = image(g, o, d);
                        image(g, o, d) = image(g, image.height - 1 - o, d);
                        image(g, image.height - 1 - o, d) = temp;
                    }
                }
            }
            break; // Exit the loop if choice is valid
        } else {
            cout << "Invalid choice. Please enter 1 or 2." << endl;
        }
    }
}


Image merge(Image& image1){

    string filename2;
    cout << " please enter the second image name ";
    cin >> filename2;
    Image image2 (filename2);

    float max_width, max_height, min_height, min_width, width_img, height_img, width_ratio1, height_ratio1, width_ratio2, height_ratio2;

    if (image1.width > image2.width){
        max_width = image1.width;
        min_width = image2.width;
    }else if (image1.width < image2.width) {
        max_width = image2.width;
        min_width = image1.width;
    }

    if (image1.height > image2.height){
        max_height = image1.height;
        min_height = image2.height;
    }else if (image1.height < image2.height){
        max_height = image2.height;
        min_height = image1.height;
    }

    char ch;
    cout << "choose what you want \n";
    cout << "1) crop both image 1 and image 2 to be " << min_width << " x " << min_height << " then merge \n";
    cout << "2) resize both image 1 and image 2 to be " << max_width << " x " << max_height << " then merge \n";
    cout << " please enter your choice : ";
    cin >> ch;

    if (ch == '1'){
        width_img = min_width;
        height_img = min_height;

    }
    else {
        width_img = max_width;
        height_img = max_height;
    }
    Image image (width_img, height_img);
    Image image3 (width_img, height_img);
    Image image_merge (width_img, height_img);


    if (ch == '1'){
        for (int i = 0; i < width_img; ++i) {
            for (int g = 0; g < height_img; ++g) {
                for (int k = 0; k < 3; ++k) {
                    image(i, g, k) = image1(i, g, k);
                    image3(i, g, k) = image2(i, g, k);
                }

            }
        }

    }else{
        if (((image1.width != width_img) || (image1.height != height_img)) || ((image2.width != width_img) || (image2.height != height_img))){
            width_ratio1 = image1.width / (width_img);
            height_ratio1 = image1.height / height_img;
            width_ratio2 = image2.width / width_img;
            height_ratio2 = image2.height / height_img;


            for (int i = 0; i < width_img; ++i) {
                for (int g = 0; g < height_img; ++g) {
                    float T = i * width_ratio1;
                    float S = g * height_ratio1;
                    float H = i * width_ratio2;
                    float P = g * height_ratio2;
                    for (int k = 0; k < 3; ++k) {
                        image.setPixel(i, g, k, image1.getPixel(round(T), round(S), k));
                        image3.setPixel(i, g, k, image2.getPixel(round(H), round(P), k));
                    }


                }
            }
        }else if ((image1.width == width_img) && (image1.height == height_img)){
            image = image1;
        }else{
            image3 = image2;
        }
    }

    for (int i = 0; i < width_img; ++i) {
        for (int g = 0; g < height_img; ++g){
            unsigned int avg = 0;
            for (int k = 0; k < 3; ++k){
                avg = (image3(i,g,k)+image(i,g,k))/2;
                image_merge(i,g,k) = avg;
            }
        }
    }
    return image_merge;
}


void Purple_Image(Image & image){

    for (int f = 0; f < image.width; f++) {
        for (int h = 0; h < image.height; h++) {
            unsigned int red_COL = image(f, h, 0);
            unsigned int blue_COL = image(f, h, 2);
            blue_COL += 50;
            red_COL += 60;
            // Ensure that color values don't exceed 255
            if (blue_COL > 255) blue_COL = 255;
            if (red_COL > 255) red_COL = 255;
            // Set the modified color values back to the image
            image(f, h, 0) = red_COL;
            image(f, h, 2) = blue_COL;
        }
    }
}


// Function to apply a blur filter to the image
void blur_filter(Image& image){
    // Iterate over each pixel in the image
    for(int a = 0;a < image.width; a++ ){
        for(int b = 0; b < image.height; b++){
            // Iterate over each color channel (R, G, B)
            for(int k = 0;k < 3; k++){
                int sum = 0; // Initialize sum of pixel values
                int count = 0; // Initialize count of pixels included in the calculation
                // Iterate over the neighboring pixels within a 31x31 window
                for(int i = a-15;i<=a + 15;i++){
                    for(int j = b-15; j <= b + 15 ;j++){
                        // Check if the neighboring pixel is within the image boundaries
                        if(i >= 0 && i < image.width && j >= 0 && j < image.height){
                            sum += image(i,j,k); // Add pixel value to the sum
                            count++;
                        }
                    }
                }
                // Compute the average pixel value and assign it to the current pixel
                image(a,b,k) = sum / count;
            }
        }
    }
}

// Function to apply a sunny filter to the image
void sunny_filter(Image& image){
    // Iterate over each pixel in the image
    for(int a = 0 ; a < image.width; a++){
        for(int b = 0 ; b < image.height; b++) {
            // Get the current pixel's RGB values
            unsigned int red_col = image(a, b, 0);
            unsigned int green_col = image(a, b, 1);
            unsigned int blue_col = image(a, b, 2);

            // Apply adjustments to the RGB values to create a sunny effect
            red_col += 50;
            green_col += 50;
            blue_col -= 30;

            // Ensure RGB values are within the valid range [0, 255]
            if (red_col > 255)
                red_col = 255;
            if (green_col > 255)
                green_col = 255;

            // Update the image with the adjusted RGB values
            image(a,b,0) = red_col;
            image(a,b,1) = green_col;
            image(a,b,2) = blue_col;
        }
    }
}

// Function to add a simple frame around the image
void simple_frame(Image & image) {

    int frame = 0;
    if (image.height <= 750 || image.width <= 750) {
        frame = 10;
    } else if ((image.height > 750 && image.height <= 1500) ||
               (image.width > 750 && image.width <= 1500)) {
        frame = 18;
    } else {
        frame = 30;
    }

    // Add frame around the image
    for (int i = 0; i < image.width; ++i) {
        for (int g = 0; g < frame; ++g) {
            image(i, g, 0) = 0;   // Set red channel to 0
            image(i, g, 1) = 255; // Set green channel to 255
            image(i, g, 2) = 255; // Set blue channel to 255
        }
        for (int g = image.height - frame; g < image.height; ++g) {
            image(i, g, 0) = 0;   // Set red channel to 0
            image(i, g, 1) = 255; // Set green channel to 0
            image(i, g, 2) = 255; // Set blue channel to 255
        }
    }

    for (int i = 0; i < image.height; ++i) {
        for (int g = 0; g < frame; ++g) {
            image(g, i, 0) = 0;   // Set red channel to 0
            image(g, i, 1) = 255; // Set green channel to 0
            image(g, i, 2) = 255; // Set blue channel to 255
        }
        for (int g = image.width - frame; g < image.width; ++g) {
            image(g, i, 0) = 0;   // Set red channel to 0
            image(g, i, 1) = 255; // Set green channel to 0
            image(g, i, 2) = 255; // Set blue channel to 255
        }
    }

}


// Function to add a fancy frame around the image
void fancy_frame(Image & image) {

    int frame = 0;
    if (image.height <= 750 || image.width <= 750) {
        frame = 10;
    } else if ((image.height > 750 && image.height <= 1500) ||
               (image.width > 750 && image.width <= 1500)) {
        frame = 18;
    } else {
        frame = 30;
    }

    // Add frame around the image
    // Add white lines from the top and left
    for(int i = frame +5; i < image.width ; i++){
        for(int g =frame + 5 ;g < frame + 13 ; g++){
            image(i,g,0) = 255;
            image(i,g,1) = 255;
            image(i,g,2) = 255;
        }
    }
    for(int i = frame+ 5 ; i < frame + 13 ; i++){
        for(int g = frame + 5 ;g < image.height ; g++ ){
            image(i,g,0) = 255;
            image(i,g,1) = 255;
            image(i,g,2) = 255;
        }
    }
    // Add white lines from the bottom
    for(int i = frame + 5; i < image.width ; i++){
        for(int g = image.height - frame - 13 ; g < image.height - frame - 5; g++){
            image(i,g,0) = 255;
            image(i,g,1) = 255;
            image(i,g,2) = 255;
        }
    }

    // Add white lines from the right
    for(int i = image.width - frame - 13; i < image.width - frame - 5 ; i++){
        for(int g = frame + 5 ; g < image.height ; g++){
            image(i,g,0) = 255;
            image(i,g,1) = 255;
            image(i,g,2) = 255;
        }
    }

}

void frame(Image& image){
    while (true) {
        int choice;
        cout << "Choose an option:" << endl;
        cout << "1. simple frame " << endl;
        cout << "2. fancy frame " << endl;
        cout << "3. Exit the program" << endl;
        cin >> choice;
        cin.ignore();


        if (cin.fail()) {
            // Clear error state
            cin.clear();
            // Ignore invalid input
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // Display error message
            cout << "Invalid input. Please enter a number between 1 and 3.\n";
            continue; // Skip to the next iteration of the loop
        }


        // Perform operation based on user's choice
        switch (choice) {
            case 1:
                simple_frame(image);
                break;
            case 2:
                simple_frame(image);
                fancy_frame(image);
                break;
            case 3 :
                cout << "Exiting program. Goodbye!\n";
                return ; // Exit the program
            default:
                cout << "Invalid choice" << endl;
                // Go to the next iteration of the loop
                continue;
        }
    }
}


void Infrared_Image(Image & image){

    for(int i = 0; i < image.width; ++i){
        for(int g = 0; g < image.height; ++g){
            image(i,g,0) = 255;
            int value = image(i,g,1);
            image(i,g,1) = 255 - image(i,g,2);
            image(i,g,2) = 255 - value;

        }

    }
}

void displayMenu() {
    cout<<"1_Grayscale Conversion\n2_Black and White\n";
    cout<<"3_Invert Image\n4_Merge_Image\n5_Flip Image\n6_Rotate_Image\n7_Darken and Lighten Image\n8_Cropped Image\n";
    cout<<"9_Frame Image\n10_Detected Image\n11_Resized_Image\n12_Blur Image\n13_land of Wano\n";
    cout << "14_Purple Image\n15_Infrared Image\n";
}


int main() {
    cout << "===== Filters Program =====\n";
    while (true) {
        cin.clear();
        cin.ignore();
        try {
            string img;
            cout << "Enter image name to apply filter: ";
            cin >> img;
            // Load the image
            Image image(img);
            while (true) {
                cout << "1_CONTINUE program.\n2_SAVE image.\n3_EXIT program.\n";
                string choice1;
                cout << "Please, Enter your choice (1, 2, 3): ";
                cin >> choice1;
                if (choice1 == "1") {
                    displayMenu();
                    string choice2;
                    cout << "=> Enter your choice: ";
                    cin >> choice2;
                    if (choice2 == "1") {
                        grayscale(image);
                    } else if (choice2 == "2") {
                        blackandwhite(image);
                    } else if (choice2 == "3") {
                        inverted(image);
                    } else if (choice2 == "4") {
                        image = merge(image);
                    } else if (choice2 == "5") {
                        Flip(image);
                    } else if (choice2 == "6") {
                        rotateImage(image);
                    } else if (choice2 == "7") {
                        brithenanddarken(image);
                    } else if (choice2 == "8") {
                        Crop_Img(image);
                    } else if (choice2 == "9") {
                        frame(image);
                    } else if (choice2 == "10") {
                        image = detect_image(image);
                    } else if (choice2 == "11") {
                        image = Resize_Img(image);
                    } else if (choice2 == "12") {
                        blur_filter(image);
                    } else if (choice2 == "13") {
                        sunny_filter(image);
                    } else if (choice2 == "14") {
                        Purple_Image(image);
                    } else if (choice2 == "15") {
                        Infrared_Image(image);
                    } else {
                        cout << ">>>Error: invalid choice!!" << endl;
                    }
                } else if (choice1 == "2") {
                    try {
                        string output_filename;
                        cout << "Enter the name to save the image: ";
                        cin >> output_filename;
                        // Save the image
                        image.saveImage(output_filename);
                        cout << "Image saved successfully." << endl;
                    } catch (const exception &e) {
                        cerr << "Error: " << e.what() << endl;
                        return 1; // Indicate error
                    }
                } else if (choice1 == "3") {
                    cout << "> Program Exit <" << endl;
                    break;
                } else {
                    cout << ">>>Error: invalid choice!!" << endl;
                }
            }
        } catch (const exception &e) {
            cerr << "Error: " << e.what() << endl;
            cout << "Please enter a valid image name." << endl;
            // Clear input buffer
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
}

