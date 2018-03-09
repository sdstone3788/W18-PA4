// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __ICE_CPP__
#define __ICE_CPP__

#include "Ice.hpp"
using namespace std;
pair<int, int> findOptimal(pair<int, int> p1, pair<int, int> p2, int ice){
	pair<int, int> pair1 = p1;
	pair<int, int> pair2 = p2;
	int newIce=0;
	//if the ice we look at is negative
	if (ice < 0){
		newIce = -1*ice;
		pair1 = make_pair(p1.first, newIce + p1.second);
		pair2 = make_pair(p2.first, newIce + p2.second);
	}
	//if ice is positive
	else if (ice > 0){
		if (p2.second <= ice){
			int x = ice - p2.second +1;
			pair2 = make_pair(p2.first+x, 1);
		}		
		if (p2.second > ice){
			pair2= make_pair(p2.first, p2.second-ice);
		}
		if (p1.second <= ice){
			int x = ice -p1.second +1;
			pair1 = make_pair(p1.first+x, 1);
		}		
		if (p1.second > ice){
			pair1 = make_pair(p1.first, p1.second-ice); 
		}

	}
	//if ice is 0, we don't change the pairs
	if (pair1.first < pair2.first){
			return pair1;
	}
	if (pair1.first==pair2.first && pair1.second > pair2.second){
			return pair1;
	}
	if (pair1.first > pair2.first){
		return pair2;
	}
	return pair2;
	
}
using namespace std;
int ice(TwoD_Array<int> rooms) {
	int row = rooms.getNumRows();
	int col = rooms.getNumCols();
	// pears: first is the min blocks needed, second is curr blocks
	TwoD_Array<pair<int, int>>iceMaze(row, col);
	pair<int, int> p;
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			if (i==0 && j==0){
				if (rooms.at(i,j) < 0){
					p = make_pair(1, (-1)*rooms.at(i,j)+1);
					iceMaze.at(i,j) = p;
				}
				else if (rooms.at(i,j) > 0){
					p = make_pair(rooms.at(i,j)+1, 1);
					iceMaze.at(i,j)=p;
				}
				else {
					p = make_pair(1,1);
					iceMaze.at(i,j)=p;
				}
			}
			else if (i!=0 && j!=0){
				pair<int, int> p1 = iceMaze.at(i, j-1);
				pair<int, int> p2 = iceMaze.at(i-1, j);
				p = findOptimal(p1, p2, rooms.at(i,j));
				iceMaze.at(i,j)=p;
			}
			else if (j==0){
				pair<int, int> p1=iceMaze.at(i-1, j);
				pair<int, int> p2=iceMaze.at(i-1, j);
				p = findOptimal(p1, p2, rooms.at(i,j));
				iceMaze.at(i,j)=p;
			}
			else if (i==0){
				pair<int, int> p1=iceMaze.at(i,j-1);
				pair<int, int> p2=iceMaze.at(i, j-1);
				p = findOptimal(p1, p2, rooms.at(i,j));
				iceMaze.at(i,j)=p;
			}
		}
	}
  return iceMaze.at(row-1, col-1).first;
}




#endif
