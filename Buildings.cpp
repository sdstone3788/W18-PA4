// CSE 101 Winter 2018, PA 4
//
// Name: Samantha Stone, Sarah Ji
// PID: A12861099, A12640758
// Sources of Help: discussed ideas with Yasmine Nassar
// Due: March 10th, 2018 at 11:59 PM

#ifndef __BUILDINGS_CPP__
#define __BUILDINGS_CPP__

#include "Buildings.hpp"
#include "Interval.hpp"
#include <algorithm>
#include <queue>
using namespace std;

int buildings(TwoD_Array<int> survey) {
	int count=0;
	queue<pair<int, int>> q;
	int r = survey.getNumRows()-1; //length of row
	int c = survey.getNumCols()-1; //length of col
	pair<int,int> top;
//	q.push(make_pair(0,0));
	for (int x=0; x<survey.getNumRows(); x++){
		for (int y=0; y<survey.getNumCols(); y++){
			if (survey.at(x,y)==1){
				count++;
				int i = x;
				int j = y;
		/*		if (survey.at(i,j) == 0) {
					q.pop();
					continue;
				} */
				
				q.push(make_pair(i,j));
				survey.at(x,y)=0;
				while (!(q.empty())){
					top = q.front();
					i = top.first;
					j = top.second;
					survey.at(i,j) = 0;
					if (i!=0){
						if (survey.at(i-1,j)==1){
							survey.at(i-1, j)=0;
							q.push(make_pair(i-1, j));
						}
					}
					if (j!=0) {
						if (survey.at(i,j-1)==1){
							survey.at(i, j-1)=0;
							q.push(make_pair(i, j-1));
						}
					}
					if (i != r) {
						if (survey.at(i+1,j)==1){
							survey.at(i+1, j)=0;
							q.push(make_pair(i+1, j));
						}
					}
					if (j != c) {
						if (survey.at(i,j+1)==1){
							survey.at(i, j+1)=0;
							q.push(make_pair(i, j+1));
						}	
					}
					//q.pop();
					q.pop();
				}
			}
			
		}
	}
	return count;
}
#endif
