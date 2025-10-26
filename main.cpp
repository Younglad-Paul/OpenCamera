#include <opencv2/opencv.hpp>

using namespace cv;

int main(){
    VideoCapture cam(0);

    if (!cam.isOpened()){
        std::cerr << "Could not access the camera /n";
        return 1;
    }

    Mat frame;

    while(true){
        cam >> frame;

        if(frame.empty()){
            std::cerr << "Error: blank frame grabbed /n";
            break;
        }

        imshow("camera feed", frame);

        if(waitKey(1) == 'q'){
            break;
        }
    }

    cam.release();
    destroyAllWindows();
    return 0;

}
