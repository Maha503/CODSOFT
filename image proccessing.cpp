#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

// Function to display the menu
void displayMenu() {
    cout << "\nImage Processing Tool Menu:\n";
    cout << "1. Load Image\n";
    cout << "2. Display Image\n";
    cout << "3. Convert to Grayscale\n";
    cout << "4. Apply Blur\n";
    cout << "5. Apply Sharpening\n";
    cout << "6. Adjust Brightness and Contrast\n";
    cout << "7. Crop Image\n";
    cout << "8. Resize Image\n";
    cout << "9. Save Image\n";
    cout << "10. Exit\n";
    cout << "Enter your choice: ";
}

// Function to load an image
Mat loadImage() {
    string imagePath;
    cout << "Enter image file path: ";
    cin >> imagePath;
    Mat img = imread(imagePath);
    if (img.empty()) {
        cout << "Could not open or find the image!" << endl;
    } else {
        cout << "Image loaded successfully!" << endl;
    }
    return img;
}

// Function to display the image
void displayImage(const Mat& img) {
    if (!img.empty()) {
        imshow("Image", img);
        waitKey(0);  // Wait until a key is pressed
    } else {
        cout << "No image to display." << endl;
    }
}

// Function to convert image to grayscale
Mat convertToGrayscale(const Mat& img) {
    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    return gray;
}

// Function to apply blur filter
Mat applyBlur(const Mat& img) {
    Mat blurred;
    GaussianBlur(img, blurred, Size(5, 5), 0);
    return blurred;
}

// Function to apply sharpening filter
Mat applySharpening(const Mat& img) {
    Mat sharpened;
    Mat kernel = (Mat_<float>(3, 3) << 0, -1, 0, -1, 5, -1, 0, -1, 0);
    filter2D(img, sharpened, img.depth(), kernel);
    return sharpened;
}

// Function to adjust brightness and contrast
Mat adjustBrightnessContrast(const Mat& img, double alpha, int beta) {
    Mat adjusted;
    img.convertTo(adjusted, -1, alpha, beta); // alpha=contrast, beta=brightness
    return adjusted;
}

// Function to crop the image
Mat cropImage(const Mat& img) {
    int x, y, width, height;
    cout << "Enter x, y, width, height for cropping: ";
    cin >> x >> y >> width >> height;
    Rect roi(x, y, width, height);
    return img(roi);
}

// Function to resize the image
Mat resizeImage(const Mat& img) {
    int newWidth, newHeight;
    cout << "Enter new width and height for resizing: ";
    cin >> newWidth >> newHeight;
    Mat resized;
    resize(img, resized, Size(newWidth, newHeight));
    return resized;
}

// Function to save the image
void saveImage(const Mat& img) {
    string savePath;
    cout << "Enter file name to save the image: ";
    cin >> savePath;
    imwrite(savePath, img);
    cout << "Image saved successfully!" << endl;
}

int main() {
    Mat img;
    int choice;
    bool imageLoaded = false;

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                img = loadImage();  // Load image
                imageLoaded = !img.empty();
                break;
            case 2:
                if (imageLoaded) {
                    displayImage(img);  // Display image
                } else {
                    cout << "No image loaded!" << endl;
                }
                break;
            case 3:
                if (imageLoaded) {
                    img = convertToGrayscale(img);  // Grayscale conversion
                    displayImage(img);
                } else {
                    cout << "No image loaded!" << endl;
                }
                break;
            case 4:
                if (imageLoaded) {
                    img = applyBlur(img);  // Apply blur filter
                    displayImage(img);
                } else {
                    cout << "No image loaded!" << endl;
                }
                break;
            case 5:
                if (imageLoaded) {
                    img = applySharpening(img);  // Apply sharpening filter
                    displayImage(img);
                } else {
                    cout << "No image loaded!" << endl;
                }
                break;
            case 6:
                if (imageLoaded) {
                    double alpha;
                    int beta;
                    cout << "Enter contrast (alpha): ";
                    cin >> alpha;
                    cout << "Enter brightness (beta): ";
                    cin >> beta;
                    img = adjustBrightnessContrast(img, alpha, beta);  // Adjust brightness/contrast
                    displayImage(img);
                } else {
                    cout << "No image loaded!" << endl;
                }
                break;
            case 7:
                if (imageLoaded) {
                    img = cropImage(img);  // Crop image
                    displayImage(img);
                } else {
                    cout << "No image loaded!" << endl;
                }
                break;
            case 8:
                if (imageLoaded) {
                    img = resizeImage(img);  // Resize image
                    displayImage(img);
                } else {
                    cout << "No image loaded!" << endl;
                }
                break;
            case 9:
                if (imageLoaded) {
                    saveImage(img);  // Save the image
                } else {
                    cout << "No image loaded!" << endl;
                }
                break;
            case 10:
                cout << "Exiting the program." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 10);  // Keep running until the user chooses to exit

    return 0;
}
