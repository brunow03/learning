#include "learning.hpp"
#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

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