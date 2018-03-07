// CSE 101 Winter 2018, PA 4
//
// Name: TODO put both partners' info if applicable
// PID: TODO
// Sources of Help: TODO
// Due: March 10th, 2018 at 11:59 PM

#ifndef __TENNIS_CPP__
#define __TENNIS_CPP__
#include <queue>
#include <algorithm>
#include "Tennis.hpp"
using namespace std;

class funTennisClass{
public:
bool operator ()(const int p, const int q)const{
		return (p >= q);
	}

};

class funInterval{
public:
bool operator ()(const Interval a, const Interval b) const{
	return (b.start >= a.start);
	} 
}comparator;

int tennis(std::vector<Interval> lessons) {
	funTennisClass fun;
	funInterval moreFun;
	priority_queue<int, vector<int>, funTennisClass> pq(fun);
	sort(lessons.begin(), lessons.end(), comparator);
	int count=1;
	pq.push(0);
	for (int i=0; i<lessons.size(); i++){
		int top = pq.top();
		if (lessons[i].start >= top){
			pq.pop();
			pq.push(lessons[i].end);
		}
		else {
			pq.push(lessons[i].end);
			count++;
		}
	}
	return count;
}





#endif
