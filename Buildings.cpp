// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __BUILDINGS_CPP__
#define __BUILDINGS_CPP__

#include "Buildings.hpp"
#include <algorithm>
using namespace std;

int buildings(TwoD_Array<int> survey) {
	int before = 0;
	int numBuildings = 0;
	int first=0;
	int second=0;
	for (int i = 0; i < survey.getNumRows(); i++) {
		for (int j = 0; j < survey.getNumCols(); j++) {
			if (i == 0 && j == 0 && survey.at(i,j) == 1) {
				first++;
			}
			else if (survey.at(i,j) == 1 && i == 0 && survey.at(i,j-1)==0) {
				first++;
			}
			else if (i!=0 && survey.at(i,j)==1 ) {
				if (j!=0 && survey.at(i-1,j)==0 && survey.at(i,j-1)==0){
					first++;
				}
				else if (j==0 && survey.at(i-1,j)==0){
					first++;
				}
			}
		}
		//in this one, second is incremented
		for (int k = survey.getNumCols()-1; k>=0; k--){
			if (i==0 && k==survey.getNumCols()-1 && survey.at(i,k)==1){
				second++;
			}
			else if (survey.at(i,k) == 1 && i == 0 && survey.at(i,k+1) == 0) {
				second++;
			}
			else if (i!=0 && survey.at(i,k)==1){
				if (k!=survey.getNumCols()-1 && survey.at(i-1,k)==0 && survey.at(i,k+1)==0){
					second++;
				}
				else if (k==survey.getNumCols()-1 && survey.at(i-1,k)==0){
					second++;
				}
			}
		}
		numBuildings = numBuildings + min(first, second);
		first=0;
		second=0;
	}
  return numBuildings;
}
#endif
