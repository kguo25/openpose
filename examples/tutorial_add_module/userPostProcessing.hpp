#ifndef OPENPOSE_EXAMPLES_TUTORIAL_USER_POST_PROCESSING_HPP
#define OPENPOSE_EXAMPLES_TUTORIAL_USER_POST_PROCESSING_HPP

#include <openpose/core/common.hpp>
#include <openpose/core/cvMatToOpInput.hpp>

using namespace cv;

namespace op
{
    /**
     * Add your class description here.
     */
    class UserPostProcessing
    {
    public:
        /**
         * Add your constructor description here.
         */
        UserPostProcessing();

        /**
         * Add your initializationOnThread description here.
         * This is equivalent to the constructor, but it is run in the thread where this function will operate
         */
        void initializationOnThread();

        /**
         * Add your information about what your class does and their inputs/outputs.
         * @param output is the modified cv::Mat.
         * @param input is the input cv::Mat.
         * @return If it is not void, add returning information here.
         */
		void doSomething(cv::Mat& output, const cv::Mat& input);

    private:
        /**
         * Description of your variable here.
         */
        // bool mSomeVariableHere;
    };
}





// Implementation
namespace op
{
    UserPostProcessing::UserPostProcessing()
    {
        try
        {
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    void UserPostProcessing::initializationOnThread()
    {
        try
        {
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    void UserPostProcessing::doSomething(cv::Mat& output, const cv::Mat& input)
    {
        try
        {
			cv::Mat imgHSV;
			cvtColor(input, imgHSV, COLOR_BGR2HSV);
			cv::Mat imgThresholded;
			//change according to racket
			inRange(imgHSV, Scalar(162, 147, 0), Scalar(179, 255, 255), imgThresholded);
			erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
			dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));

			dilate(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
			erode(imgThresholded, imgThresholded, getStructuringElement(MORPH_ELLIPSE, Size(5,5)));
			
            // Random operation on data
            cv::bitwise_not(imgThresholded, output);
        }
        catch (const std::exception& e)
        {
            error(e.what(), __LINE__, __FUNCTION__, __FILE__);
        }
    }

    // COMPILE_TEMPLATE_DATUM(UserPostProcessing);
}

#endif // OPENPOSE_EXAMPLES_TUTORIAL_USER_POST_PROCESSING_HPP
