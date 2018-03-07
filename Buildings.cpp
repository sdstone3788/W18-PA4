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
    int count = 0;
    for (int i = 0; i < survey.getNumRows(); i++) {
        for (int j = 0; j < survey.getNumCols(); j++) {
            if(survey.at(i,j) == 1) {
                // checking cells above and to the left
                if (i != 0 && j != 0) {
                    if(survey.at(i-1,j) == 0 && survey.at(i,j-1) == 0) {
                        count++;
                        survey.at(i,j) = count; 
                    }
                    else if (survey.at(i-1,j) != 0 && survey.at(i,j-1) != 0) {
                        survey.at(i,j) = min(survey.at(i-1,j),survey.at(i,j-1));
                        if (survey.at(i-1,j) != survey.at(i,j-1)) {
                            count--;
                        }
                    }
                    else if (survey.at(i-1,j) != 0) {
                        survey.at(i,j) = survey.at(i-1,j);
                    }
                    else {
                        survey.at(i,j) = survey.at(i,j-1); 
                    }
                }
                // first row
                else if (i != 0) {
                    if (survey.at(i,j-1) != 0) {
                        survey.at(i,j) = survey.at(i,j-1);
                    }
                    else {
                        count++;
                        survey.at(i,j) = count;
                    }
                }
                // first column
                else {
                    if (survey.at(i-1,j) != 0) {
                        survey.at(i,j) = survey.at(i-1,j);
                    }
                    else {
                        count++;
                        survey.at(i,j) = count;
                    }
                }
            }
        }
    }
    return count;
}
#endif
