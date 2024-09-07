#include "learning.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>
#include <cv.h>
#include "stdafx.h"
#include <highgui.h>
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/highgui/highgui.hpp"
// /home/bruno/Videos/855213-hd_1920_1080_24fps.mp4
// /home/bruno/Pictures/60e5dc69f199e.jpg


using namespace std;
using namespace cv;

static void CallBackFunc(int event, int x, int y, int flags, void* userdata) {
	if  ( event == EVENT_LBUTTONDOWN )
	{
		cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if  ( event == EVENT_RBUTTONDOWN )
	{
		cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if  ( event == EVENT_MBUTTONDOWN )
	{
		cout << "Middle button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
	}
	else if ( event == EVENT_MOUSEMOVE )
	{
		cout << "Mouse move over the window - position (" << x << ", " << y << ")" << endl;
	}
}

void mouseDetection(void) {
	// Read image from file 
	Mat img = imread("MyPic.JPG");

	//if fail to read the image
	if ( img.empty() ) 
	{ 
		cout << "Error loading the image" << endl;
		return; 
	}

	//Create a window
	namedWindow("My Window", 1);

	//set the callback function for any mouse event
	setMouseCallback("My Window", CallBackFunc, NULL);

	//show the image
	imshow("My Window", img);

	// Wait until user press some key
	waitKey(0);
}

static void MyCallbackForBrightness(int iValueForBrightness, void *userData) {
	Mat dst;
	int iValueForContrast = *( static_cast<int*>(userData) );

	//Calculating brightness and contrast value
	int iBrightness = iValueForBrightness - 50;
	double dContrast = iValueForContrast / 50.0;

	//Calculated contrast and brightness value
	cout << "MyCallbackForBrightness : Contrast=" << dContrast << ", Brightness=" << iBrightness << endl;

	//adjust the brightness and contrast
	src.convertTo(dst, -1, dContrast, iBrightness); 

	//show the brightness and contrast adjusted image
	imshow("My Window", dst);
}

static void MyCallbackForContrast(int iValueForContrast, void *userData) {
	Mat dst;
	int iValueForBrightness = *( static_cast<int*>(userData) );

	//Calculating brightness and contrast value
	int iBrightness = iValueForBrightness - 50;
	double dContrast = iValueForContrast / 50.0;

	//Calculated contrast and brightness value
	cout << "MyCallbackForContrast : Contrast=" << dContrast << ", Brightness=" << iBrightness << endl;

	//adjust the brightness and contrast
	src.convertTo(dst, -1, dContrast, iBrightness); 

	//show the brightness and contrast adjusted image
	imshow("My Window", dst);
}

void trackbarWithCallback(void) {
	// Read original image 
	src = imread("MyPic.JPG");

	//if fail to read the image
	if (src.data == false) 
	{ 
		cout << "Error loading the image" << endl;
		return; 
	}

	// Create a window
	namedWindow("My Window", 1);

	int iValueForBrightness = 50;
	int iValueForContrast = 50;

	//Create track bar to change brightness
	createTrackbar("Brightness", "My Window", &iValueForBrightness, 100, MyCallbackForBrightness, &iValueForContrast);

	//Create track bar to change contrast
	createTrackbar("Contrast", "My Window", &iValueForContrast, 100, MyCallbackForContrast, &iValueForBrightness);
  
	imshow("My Window", src);

	// Wait until user press some key
	waitKey(0);
}

void trackbar(void) {
	// Read original image 
	Mat src = imread("MyPic.JPG");
	
	//if fail to read the image
	if (!src.data) 
	{ 
		cout << "Error loading the image" << endl;
		return; 
	}
	
	// Create a window
	namedWindow("My Window", 1);
	
	//Create trackbar to change brightness
	int iSliderValue1 = 50;
	createTrackbar("Brightness", "My Window", &iSliderValue1, 100);
	
	//Create trackbar to change contrast
	int iSliderValue2 = 50;
	createTrackbar("Contrast", "My Window", &iSliderValue2, 100);

	while (true)
	{
		//Change the brightness and contrast of the image (For more infomation http://opencv-srf.blogspot.com/2013/07/change-contrast-of-image-or-video.html)
		Mat dst;
		
		int iBrightness  = iSliderValue1 - 50;
		double dContrast = iSliderValue2 / 50.0;
		src.convertTo(dst, -1, dContrast, iBrightness); 
		
		//show the brightness and contrast adjusted image
		imshow("My Window", dst);
		
		// Wait until user press some key for 50ms
		int iKey = waitKey(50);
		
		//if user press 'ESC' key
		if (iKey == 27)
		{
			break;
		}
	}
}

void imageDilation(void) {
	//display the original image
	IplImage* img = cvLoadImage("/home/bruno/Pictures/60e5dc69f199e.jpg");
	cvNamedWindow("MyWindow");
	cvShowImage("MyWindow", img);
	
	//dilate and display the dilated image
	cvDilate(img, img, 0, 2);
	cvNamedWindow("Dilated");
	cvShowImage("Dilated", img);
	cvWaitKey(0);
	
	//cleaning up
	cvDestroyWindow("MyWindow");
	cvDestroyWindow("Dilated");
	cvReleaseImage(&img);
}

void videoErosion(void) {
	//open the video file for reading
    VideoCapture cap("/home/bruno/Videos/855213-hd_1920_1080_24fps.mp4");

    // if not success, exit program
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return;
    }



    //Define names of the window
    String window_name_of_original_video = "Original Video";
    String window_name_of_video_eroded_with_5x5_kernel = "Video eroded with 5 x 5 kernel";

    // Create a window with above names
    namedWindow(window_name_of_original_video, WINDOW_NORMAL);
    namedWindow(window_name_of_video_eroded_with_5x5_kernel, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video 
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        //erode the frame with 5x5 kernel
        Mat frame_eroded_with_5x5_kernel;
        erode(frame, frame_eroded_with_5x5_kernel, getStructuringElement(MORPH_RECT, Size(5, 5)));

        //show the frames in the created windows
        imshow(window_name_of_original_video, frame);
        imshow(window_name_of_video_eroded_with_5x5_kernel, frame_eroded_with_5x5_kernel);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }
}

void imageErosion(void) {
	// Read the image file
    Mat image = imread("/home/bruno/Pictures/60e5dc69f199e.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return;
    }

    //Erode the image with 3x3 kernel
    Mat image_eroded_with_3x3_kernel;
    erode(image, image_eroded_with_3x3_kernel, getStructuringElement(MORPH_RECT, Size(3, 3)));

    //Erode the image with 5x5 kernel
    Mat image_eroded_with_5x5_kernel;
    erode(image, image_eroded_with_5x5_kernel, getStructuringElement(MORPH_RECT, Size(5, 5)));

    //Define names of the windows
    String window_name = "Lotus";
    String window_name_eroded_with_3x3_kernel = "Lotus eroded with 3 x 3 kernel";
    String window_name_eroded_with_5x5_kernel = "Lotus eroded with 5 x 5 kernel";

    // Create windows with above names
    namedWindow(window_name);
    namedWindow(window_name_eroded_with_3x3_kernel);
    namedWindow(window_name_eroded_with_5x5_kernel);

    // Show our images inside the created windows.
    imshow(window_name, image);
    imshow(window_name_eroded_with_3x3_kernel, image_eroded_with_3x3_kernel);
    imshow(window_name_eroded_with_5x5_kernel, image_eroded_with_5x5_kernel);

    waitKey(0); // Wait for any keystroke in the window

    destroyAllWindows(); //destroy all opened windows
}

void imageInvert(void) {
	//display the original image
	IplImage* img = cvLoadImage("/home/bruno/Pictures/60e5dc69f199e.jpg");
	cvNamedWindow("MyWindow");
	cvShowImage("MyWindow", img);

	//invert and display the inverted image
	cvNot(img, img);
	cvNamedWindow("Inverted");
	cvShowImage("Inverted", img);

	cvWaitKey(0);
      
	//cleaning up
	cvDestroyWindow("MyWindow");
	cvDestroyWindow("Inverted");
	cvReleaseImage(&img);
}

void imageGaussianBlur(void) {
	// Read the image file
    Mat image = imread("/home/bruno/Pictures/60e5dc69f199e.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return;
    }

    //Blur the image with 3x3 Gaussian kernel
    Mat image_blurred_with_3x3_kernel;
    GaussianBlur(image, image_blurred_with_3x3_kernel, Size(3, 3), 0);

    //Blur the image with 5x5 Gaussian kernel
    Mat image_blurred_with_5x5_kernel;
    GaussianBlur(image, image_blurred_with_5x5_kernel, Size(5, 5), 0);

    //Define names of the windows
    String window_name = "Lotus";
    String window_name_blurred_with_3x3_kernel = "Lotus Blurred with 3 x 3 Gaussian Kernel";
    String window_name_blurred_with_5x5_kernel = "Lotus Blurred with 5 x 5 Gaussian Kernel";

    // Create windows with above names
    namedWindow(window_name);
    namedWindow(window_name_blurred_with_3x3_kernel);
    namedWindow(window_name_blurred_with_5x5_kernel);

    // Show our images inside the created windows.
    imshow(window_name, image);
    imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
    imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

    waitKey(0); // Wait for any keystroke in the window

    destroyAllWindows(); //destroy all opened windows
}

void videoGaussianBlur(void) {
	//open the video file for reading
    VideoCapture cap("/home/bruno/Videos/855213-hd_1920_1080_24fps.mp4");

    // if not success, exit program
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return;
    }



    //Define names of the window
    String window_name_of_original_video = "Original Video";
    String window_name_of_video_blurred_with_5x5_kernel = "Video Blurred with 5 x 5 Gaussian Kernel";

    // Create a window with above names
    namedWindow(window_name_of_original_video, WINDOW_NORMAL);
    namedWindow(window_name_of_video_blurred_with_5x5_kernel, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video 
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        //Blur the frame with 5x5 Gaussian kernel
        Mat frame_blurred_with_5x5_kernel;
        GaussianBlur(frame, frame_blurred_with_5x5_kernel, Size(5, 5), 0);

        //show the frames in the created windows
        imshow(window_name_of_original_video, frame);
        imshow(window_name_of_video_blurred_with_5x5_kernel, frame_blurred_with_5x5_kernel);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }
}

void homogenousBlurImage(void) {
	// Read the image file
    Mat image = imread("/home/bruno/Pictures/60e5dc69f199e.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return;
    }

    //Blur the image with 3x3 kernel
    Mat image_blurred_with_3x3_kernel;
    blur(image, image_blurred_with_3x3_kernel, Size(3, 3));

    //Blur the image with 5x5 kernel
    Mat image_blurred_with_5x5_kernel;
    blur(image, image_blurred_with_5x5_kernel, Size(5, 5));

    //Define names of the windows
    String window_name = "The Guitar"; 
    String window_name_blurred_with_3x3_kernel = "The Guitar Blurred with 3 x 3 Kernel";
    String window_name_blurred_with_5x5_kernel = "The Guitar Blurred with 5 x 5 Kernel";

    // Create windows with above names
    namedWindow(window_name);
    namedWindow(window_name_blurred_with_3x3_kernel);
    namedWindow(window_name_blurred_with_5x5_kernel);

    // Show our images inside the created windows.
    imshow(window_name, image); 
    imshow(window_name_blurred_with_3x3_kernel, image_blurred_with_3x3_kernel);
    imshow(window_name_blurred_with_5x5_kernel, image_blurred_with_5x5_kernel);

    waitKey(0); // Wait for any keystroke in the window

    destroyAllWindows(); //destroy all opened windows
}

void homogenousBlurVideo(void) {
	//open the video file for reading
    VideoCapture cap("/home/bruno/Videos/855213-hd_1920_1080_24fps.mp4");

    // if not success, exit program
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return;
    }



    //Define names of the window
    String window_name_of_original_video = "Original Video";
    String window_name_of_video_blurred_with_5x5_kernel = "Video Blurred with 5 x 5 Kernel";

    // Create a window with above names
    namedWindow(window_name_of_original_video, WINDOW_NORMAL);
    namedWindow(window_name_of_video_blurred_with_5x5_kernel, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video 
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        //Blur the frame with 5x5 kernel
        Mat frame_blurred_with_5x5_kernel;
        blur(frame, frame_blurred_with_5x5_kernel, Size(5, 5));

        //show the frames in the created windows
        imshow(window_name_of_original_video, frame);
        imshow(window_name_of_video_blurred_with_5x5_kernel, frame_blurred_with_5x5_kernel);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }
}

void changeContrastImage(void) {
	// Read the image file
    Mat image = imread("D:/My OpenCV Website/Christmas.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return;
    }

    Mat imageContrastHigh2;
    image.convertTo(imageContrastHigh2, -1, 2, 0); //increase the contrast by 2

    Mat imageContrastHigh4;
    image.convertTo(imageContrastHigh4, -1, 4, 0); //increase the contrast by 4

    Mat imageContrastLow0_5;
    image.convertTo(imageContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

    Mat imageContrastLow0_25;
    image.convertTo(imageContrastLow0_25, -1, 0.25, 0); //decrease the contrast by 0.25


    //Defining window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNameContrastHigh2 = "Contrast Increased by 2";
    String windowNameContrastHigh4 = "Contrast Increased by 4";
    String windowNameContrastLow0_5 = "Contrast Decreased by 0.5";
    String windowNameContrastLow0_25 = "Contrast Decreased by 0.25";

    //Create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh4, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

    //Show above images inside the created windows.
    imshow(windowNameOriginalImage, image);
    imshow(windowNameContrastHigh2, imageContrastHigh2);
    imshow(windowNameContrastHigh4, imageContrastHigh4);
    imshow(windowNameContrastLow0_5, imageContrastLow0_5);
    imshow(windowNameContrastLow0_25, imageContrastLow0_25);

    waitKey(0); // Wait for any key stroke

    destroyAllWindows(); //destroy all open windows
}

void changeContrastVideo(void) {
	//open the video file for reading
    VideoCapture cap("D:/My OpenCV Website/A Herd of Deer Running.mp4");

    // if not success, exit program
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return;
    }

    //Defining window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNameContrastHigh2 = "Contrast Increased by 2";
    String windowNameContrastHigh4 = "Contrast Increased by 4";
    String windowNameContrastLow0_5 = "Contrast Decreased by 0.5";
    String windowNameContrastLow0_25 = "Contrast Decreased by 0.25";

    //Create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh2, WINDOW_NORMAL);
    namedWindow(windowNameContrastHigh4, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_5, WINDOW_NORMAL);
    namedWindow(windowNameContrastLow0_25, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video 

         //Breaking the while loop at the end of the video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameContrastHigh2;
        frame.convertTo(frameContrastHigh2, -1, 2, 0); //increase the contrast by 2

        Mat frameContrastHigh4;
        frame.convertTo(frameContrastHigh4, -1, 4, 0); //increase the contrast by 4

        Mat frameContrastLow0_5;
        frame.convertTo(frameContrastLow0_5, -1, 0.5, 0); //decrease the contrast by 0.5

        Mat frameContrastLow0_25;
        frame.convertTo(frameContrastLow0_25, -1, 0.25, 0); //decrease the contrast by 0.25

        //Show above images inside the created windows.
        imshow(windowNameOriginalImage, frame);
        imshow(windowNameContrastHigh2, frameContrastHigh2);
        imshow(windowNameContrastHigh4, frameContrastHigh4);
        imshow(windowNameContrastLow0_5, frameContrastLow0_5);
        imshow(windowNameContrastLow0_25, frameContrastLow0_25);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }
}

void changeBrightnessVideo(void) {
	//open the video file for reading
    VideoCapture cap("D:/My OpenCV Website/A Herd of Deer Running.mp4");

    // if not success, exit program
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video file" << endl;
        cin.get(); //wait for any key press
        return;
    }

    //Defining window names
    String windowNameOriginalVideo = "Original Video";
    String windowNameBrightnessHigh50 = "Brightness Increased by 50";
    String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
    String windowNameBrightnessLow50 = "Brightness Decreased by 50";
    String windowNameBrightnessLow100 = "Brightness Decreased by 100";

    //Create and open windows for above window names
    namedWindow(windowNameOriginalVideo, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
    namedWindow(windowNameWithBrightnessHigh100, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

    while (true)
    {
        Mat frame;
        bool bSuccess = cap.read(frame); // read a new frame from video 

         //Breaking the while loop at the end of the video
        if (bSuccess == false)
        {
            cout << "Found the end of the video" << endl;
            break;
        }

        Mat frameBrighnessHigh50;
        frame.convertTo(frameBrighnessHigh50, -1, 1, 50); //increase the brightness by 50

        Mat frameBrighnessHigh100;
        frame.convertTo(frameBrighnessHigh100, -1, 1, 100); //increase the brightness by 100

        Mat frameBrighnessLow50;
        frame.convertTo(frameBrighnessLow50, -1, 1, -50); //decrease the brightness by 50

        Mat frameBrighnessLow100;
        frame.convertTo(frameBrighnessLow100, -1, 1, -100); //decrease the brightness by 100

        //Show above frames inside the created windows.
        imshow(windowNameOriginalVideo, frame);
        imshow(windowNameBrightnessHigh50, frameBrighnessHigh50);
        imshow(windowNameWithBrightnessHigh100, frameBrighnessHigh100);
        imshow(windowNameBrightnessLow50, frameBrighnessLow50);
        imshow(windowNameBrightnessLow100, frameBrighnessLow100);

        //wait for for 10 ms until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If the any other key is pressed, continue the loop 
        //If any key is not pressed withing 10 ms, continue the loop
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by user. Stoppig the video" << endl;
            break;
        }
    }
}

void changeBrightnessImage(void) {
	// Read the image file
    Mat image = imread("/home/bruno/Pictures/IMG-20240110-WA0023.jpg");

    // Check for failure
    if (image.empty())
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return;
    }

    Mat imageBrighnessHigh50;
    image.convertTo(imageBrighnessHigh50, -1, 1, 50); //increase the brightness by 50

    Mat imageBrighnessHigh100;
    image.convertTo(imageBrighnessHigh100, -1, 1, 100); //increase the brightness by 100

    Mat imageBrighnessLow50;
    image.convertTo(imageBrighnessLow50, -1, 1, -50); //decrease the brightness by 50

    Mat imageBrighnessLow100;
    image.convertTo(imageBrighnessLow100, -1, 1, -100); //decrease the brightness by 100

    //Defining window names for above images
    String windowNameOriginalImage = "Original Image";
    String windowNameBrightnessHigh50 = "Brightness Increased by 50";
    String windowNameWithBrightnessHigh100 = "Brightness Increased by 100";
    String windowNameBrightnessLow50 = "Brightness Decreased by 50";
    String windowNameBrightnessLow100 = "Brightness Decreased by 100";

    //Create and open windows for above images
    namedWindow(windowNameOriginalImage, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessHigh50, WINDOW_NORMAL);
    namedWindow(windowNameWithBrightnessHigh100, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow50, WINDOW_NORMAL);
    namedWindow(windowNameBrightnessLow100, WINDOW_NORMAL);

    //Show above images inside the created windows.
    imshow(windowNameOriginalImage, image);
    imshow(windowNameBrightnessHigh50, imageBrighnessHigh50);
    imshow(windowNameWithBrightnessHigh100, imageBrighnessHigh100);
    imshow(windowNameBrightnessLow50, imageBrighnessLow50);
    imshow(windowNameBrightnessLow100, imageBrighnessLow100);

    waitKey(0); // Wait for any key stroke

    destroyAllWindows(); //destroy all open windows
}

void saveVideoToFile(void) {
	//Open the default video camera
    VideoCapture cap(0);

    // if not success, exit program
    if (cap.isOpened() == false)
    {
        cout << "Cannot open the video camera" << endl;
        cin.get(); //wait for any key press
        return;
    }

    int frame_width = static_cast<int>(cap.get(CAP_PROP_FRAME_WIDTH)); //get the width of frames of the video
    int frame_height = static_cast<int>(cap.get(CAP_PROP_FRAME_HEIGHT)); //get the height of frames of the video
    
    Size frame_size(frame_width, frame_height);
    int frames_per_second = 10;

    //Create and initialize the VideoWriter object 
    VideoWriter oVideoWriter("D:/MyVideo.avi", VideoWriter::fourcc('M', 'J', 'P', 'G'), 
                                                               frames_per_second, frame_size, true); 
    
    //If the VideoWriter object is not initialized successfully, exit the program
    if (oVideoWriter.isOpened() == false) 
    {
        cout << "Cannot save the video to a file" << endl;
        cin.get(); //wait for any key press
        return;
    }

    string window_name = "My Camera Feed";
    namedWindow(window_name); //create a window called "My Camera Feed"

    while (true)
    {
        Mat frame;
        bool isSuccess = cap.read(frame); // read a new frame from the video camera

        //Breaking the while loop if frames cannot be read from the camera
        if (isSuccess == false)
        {
            cout << "Video camera is disconnected" << endl;
            cin.get(); //Wait for any key press
            break;
        }

        /*
        Make changes to the frame as necessary
        e.g.  
         1. Change brightness/contrast of the image
         2. Smooth/Blur image
         3. Crop the image
         4. Rotate the image
         5. Draw shapes on the image
        */

        //write the video frame to the file
        oVideoWriter.write(frame); 

        //show the frame in the created window
        imshow(window_name, frame);

        //Wait for for 10 milliseconds until any key is pressed.  
        //If the 'Esc' key is pressed, break the while loop.
        //If any other key is pressed, continue the loop 
        //If any key is not pressed within 10 milliseconds, continue the loop 
        if (waitKey(10) == 27)
        {
            cout << "Esc key is pressed by the user. Stopping the video" << endl;
            break;
        }
    }

    //Flush and close the video file
    oVideoWriter.release();
}

void saveImagesToFile(void) {
	// Read the image file
	Mat image = imread("/home/bruno/Pictures/IMG-20240110-WA0023.jpg");

	// Check for failure
	if (image.empty())
	{
		cout << "Could not open or find the image" << endl;
		cin.get(); //wait for any key press
		return;
	}

	/*
	Make changes to the image as necessary
	e.g.  
	1. Change brightness/contrast of the image
	2. Smooth/Blur image
	3. Crop the image
	4. Rotate the image
	5. Draw shapes on the image
	*/

	bool isSuccess = imwrite("/home/bruno/Pictures/image.jpg", image); //write the image to a file as JPEG 
	//bool isSuccess = imwrite("D:/MyImage.png", image); //write the image to a file as PNG
	if (isSuccess == false)
	{
		cout << "Failed to save the image" << endl;
		cin.get(); //wait for a key press
		return;
	}

	cout << "Image is succusfully saved to a file" << endl;

	String windowName = "The Saved Image"; //Name of the window
	namedWindow(windowName); // Create a window
	imshow(windowName, image); // Show our image inside the created window.

	waitKey(0); // Wait for any keystroke in the window

	destroyWindow(windowName); //destroy the created window
}

void captureAndPlayFromCamera(void) {
	//Open the default video camera
	VideoCapture cap(0);

	// if not success, exit program
	if (cap.isOpened() == false)  
	{
		cout << "Cannot open the video camera" << endl;
		cin.get(); //wait for any key press
		return;
	} 

	double dWidth = cap.get(CAP_PROP_FRAME_WIDTH); //get the width of frames of the video
	double dHeight = cap.get(CAP_PROP_FRAME_HEIGHT); //get the height of frames of the video

	cout << "Resolution of the video : " << dWidth << " x " << dHeight << endl;

	string window_name = "My Camera Feed";
	namedWindow(window_name); //create a window called "My Camera Feed"
 
	while (true)
	{
 		Mat frame;
 		bool bSuccess = cap.read(frame); // read a new frame from video 	
 		
 		//Breaking the while loop if the frames cannot be captured
 		if (bSuccess == false) 
 		{
			cout << "Video camera is disconnected" << endl;
			cin.get(); //Wait for any key press
			break;
		}
	
		//show the frame in the created window
		imshow(window_name, frame);
	
		//wait for for 10 ms until any key is pressed.  
		//If the 'Esc' key is pressed, break the while loop.
		//If the any other key is pressed, continue the loop 
		//If any key is not pressed withing 10 ms, continue the loop 
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}
}

void loadImageFromFileAndDisplay(void) {
	Mat image = imread("/home/bruno/Pictures/IMG-20240110-WA0023.jpg");  
    
    // Check for failure
    if (image.empty()) 
    {
        cout << "Could not open or find the image" << endl;
        cin.get(); //wait for any key press
        return;
    }   
    
    String windowName = "The Guitar"; //Name of the window  
    
    namedWindow(windowName); // Create a window 
    
    imshow(windowName, image); // Show our image inside the created window. 
    
    waitKey(0); // Wait for any keystroke in the window 
    
    destroyWindow(windowName); //destroy the created window 
}

void createBlankImageAndDisplay(void) {
	//create a new image which consists of 
	//3 channels 
	//image depth of 8 bits 
	//800 x 600 of resolution (800 wide and 600 high)
	//each pixels initialized to the value of (100, 250, 30) for Blue, Green and Red planes respectively.
	Mat image(600, 800, CV_8UC3, Scalar(100, 250, 30)); 
	
	String windowName = "Window with Blank Image"; //Name of the window	
	
	namedWindow(windowName); // Create a window	
	
	imshow(windowName, image); // Show our image inside the created window.	
	
	waitKey(0); // Wait for any keystroke in the window	
	
	destroyWindow(windowName); //destroy the created window
}

void playVideoFromFile(void) {
	VideoCapture cap("/home/bruno/Videos/855213-hd_1920_1080_24fps.mp4"); 

	// if not success, exit program
	if (cap.isOpened() == false)  
	{
		cout << "Cannot open the video file" << endl;
		cin.get(); //wait for any key press
		return;
	}	
	
	//Uncomment the following line if you want to start the video in the middle
	//cap.set(CAP_PROP_POS_MSEC, 300); 	
	
	//get the frames rate of the video
	double fps = cap.get(CAP_PROP_FPS); 
	cout << "Frames per seconds : " << fps << endl;	
	
	String window_name = "My First Video";	
	
	namedWindow(window_name, WINDOW_NORMAL); //create a window	
	
	while (true)
	{
		Mat frame;
		
		bool bSuccess = cap.read(frame); // read a new frame from video 	
		
		//Breaking the while loop at the end of the video
		if (bSuccess == false) 
	 	{
	 		cout << "Found the end of the video" << endl;
			break;
		}	
		
		//show the frame in the created window
		imshow(window_name, frame);	
		
		//wait for for 10 ms until any key is pressed.  
		//If the 'Esc' key is pressed, break the while loop.
		//If the any other key is pressed, continue the loop 
		//If any key is not pressed withing 10 ms, continue the loop
		if (waitKey(10) == 27)
		{
			cout << "Esc key is pressed by user. Stoppig the video" << endl;
			break;
		}
	}
}