// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __SERIAL_CPP__
#define __SERIAL_CPP__

#include "Serial.hpp"
#include <iostream>
using namespace std;
int serial(std::vector<int> nums) {
	/*	for (int i=0; i<nums.size(); i++){
			cout << nums[i] << " HELLO ??? " << endl;
		}
		if (end-start+1 <= 3){
			cout << mid << " ????????" << endl;
			return nums[(start+end)/2];
		}
		if (nums[mid] == nums[mid+1] || nums[mid] == nums[mid-1]) {
			return nums[mid];
		}
		else if (avg > nums[mid]) {
			end = mid;
		}
		else {
			start = mid;
		}
		avg = (nums[start]+nums[end])/2;
	} */


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
			cout << "half1: " << half << endl;
			end=half;
			arrayL = end-start +1;
			half = arrayL/2 + start;
		}
		else if (arrayL%2==0 && nums[end]-arrayL/2 +1 != nums[half] ){
			cout << "start: " << start << "end: " << end << " half2: " << half << endl;
			cout << "arrayL :" << arrayL <<endl;
			start=half;
			arrayL = end-start+1;
			half=arrayL/2 + start;
		}
		else if (nums[end]-arrayL/2 !=nums[half]){
			cout << "half3: " << half << end;
			start=half;
			arrayL=end-start+1;
			half=arrayL/2 + start;
		}
		cout << "infinite loops here we come" << endl; 
	}

			
		
	//get length of vector
	//get middle. 
	//binary search type
  
}
#endif
