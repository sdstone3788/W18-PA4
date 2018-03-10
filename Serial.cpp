// CSE 101 Winter 2018, PA 4
//
// Name: Samantha Stone, Sarah Ji
// PID: A12861099, A12640758
// Sources of Help: 
// Due: March 10th, 2018 at 11:59 PM

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"
#include <iostream>
using namespace std;
int serial(std::vector<int> nums) {


	int start = 0;
	int end = nums.size()-1;
	int avg = (nums[end] + nums[start])/2;
	int half = nums.size()/2;
	int arrayL = nums.size();
	while (1){
		if (end-start+1 <=3){
			return nums[half];
		}
		if (nums[start] + arrayL/2 != nums[half]){
			end=half;
			arrayL = end-start +1;
			half = arrayL/2 + start;
		}
		else if (arrayL%2==0 && nums[end]-arrayL/2 +1 != nums[half] ){
			start=half;
			arrayL = end-start+1;
			half=arrayL/2 + start;
		}
		else if (nums[end]-arrayL/2 !=nums[half]){
			start=half;
			arrayL=end-start+1;
			half=arrayL/2 + start;
		}
	}

			

  
}
#endif
