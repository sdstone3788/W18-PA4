// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
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
	q.push(make_pair(0,0));
	for (int x=0; x<survey.getNumRows(); x++){
		for (int y=0; y<survey.getNumCols(); y++){
			if (survey.at(x,y)==1){
				count++;
				int i = x;
				int j = y;
				if (survey.at(i,j) == 0) {
					q.pop();
					continue;
				}
				
				q.push(make_pair(i,j));
				survey.at(x,y)=0;
				while (!(q.empty())){
					top = q.front();
					q.pop();
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
				}
			}
			
		}
	}
	return count;
}
/*
	 int count = 0;
	 int scount=0;
	 for (int i = 0; i < survey.getNumRows(); i++) {
	 for (int j = 0; j < survey.getNumCols(); j++) {
	 if(survey.at(i,j) == 1) {
// checking cells above and to the left
if (i != 0 && j != 0) {
if(survey.at(i-1,j) == 0 && survey.at(i,j-1) == 0) {
count++;
scount++;
survey.at(i,j) = scount; 
}
else if (survey.at(i-1,j) != 0 && survey.at(i,j-1) != 0) {
survey.at(i,j) = min(survey.at(i-1,j),survey.at(i,j-1));

if (survey.at(i-1, j-1)==0 &&survey.at(i-1,j) != survey.at(i,j-1)) {

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
// used to say i!=0
else if (i == 0 && j!=0) {
if (survey.at(i,j-1) != 0) {
survey.at(i,j) = survey.at(i,j-1);
}
else {
scount++;
count++;
survey.at(i,j) = scount;
}
}
// first column
else if(j==0){
if (i!=0 && survey.at(i-1,j) != 0) {
survey.at(i,j) = survey.at(i-1,j);
}
else {
scount++;
count++;
survey.at(i,j) = scount;
}
}
}
}
}
//		survey.printOut();
return count;
} */
//survey.at(i-1,j) != survey.at(i,j-1) && 
//|| survey.at(i-1, j)<count))
//												survey.at(i-1,j)=survey.at(i,j);
//													survey.at(i, j-1)=survey.at(i,j);
//
#endif
