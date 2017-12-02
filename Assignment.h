#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "test.h"

using namespace std;

class Assignment {
	private:
		string assignmentName;
		Test temp;
		vector<Test> classTests;
		vector<float> grades;

		float high;
		float low;
		float mean;
		float curve;

	public://Pass in vector containing grades to calculate stats
		Assignment(string temp_name);

		void add_test(Test temp);
		float calculateHigh(vector<float> grades);
		float calculateLow(vector<float> grades);
		float calculateMean(vector<float> grades);
		float calculateMode(vector<float> grades);
		float calculateMedian(vector<float> grades);
		//void organizeGrades(vector<float> &grades);
		float calculateCurve();
  
		//Accessor methods
		float getHigh();
		float getLow();
		float getMean();
};

Assignment::Assignment(string temp_name) {
	assignmentName = temp_name;
	new vector<Test> assignmentName = classTests;
}

void Assignment::add_test(Test temp) {
	classTests.push_back(temp);
}

float Assignment::calculateHigh(vector<float> grades) {
	float high = 0;
	
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i] > high) {
			high = grades[i];
		}
	}
	return high;
}

float Assignment::calculateLow(vector<float> grades) {
	float low = 100;
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i] < low) {
			low = grades[i];
		}
	}
	return low;
}

float Assignment::calculateMean(vector<float> grades) {
	float sum = 0;
	for (int i = 0; i < grades.size(); i++) {
		sum += grades[i];
	}
	return sum / grades.size();
}

float Assignment::calculateCurve(vector<float> grades) {
//not finished yet, trying to figure out how to return the "curved" grades vector
	float inputAverage;

	cout << "Please enter the desired average for this exam." << endl;
	cin >> inputAverage;
	
	float realAverage = grades.calculateMean(); //**calculateMean(grades)
	
	if (realAverage < inputAverage) {
		curve = inputAverage - realAverage;
	} else {
		curve = 0;
	}
	for (int i = 0; i<grades.size(); i++) {
		grades[i]=grades[i]+curve;
	}
}

//I think .size will give us a bit value of the actual size of the array, not
//the amt of elements, we may need to use *sizeof(grades)/sizeof(grades[0])*
//maybe .capacity() is what we are looking for? need to test -mike
float Assignment::calculateMedian(vector<float> grades) {
	//Odd student size case
	if (grades.size()%2 == 1){
		return grades[(1+grades.size())/2-1];
	} else {
		return (grades[grades.size()/2-1] + grades[grades.size()/2])/2;
	}
}

//assuming grade array will be in order for mode calculation
float Assignment::calculateMode(vector<float> grades) {
	int mode = 1;
	int currentMode = 0;
	float possibleMode = grades[0];
	
	for (int i = 1; i < grades.size(); ++i) {
		if (grades[i] == grades[i-1]){
			currentMode++;
		} else if (currentMode > mode) {
			possibleMode = grades[i-1];
			mode = currentMode;
			currentMode = 0;
		}
	}
	return possibleMode;
}

float Assignment::getHigh() {
	return high;
}

float Assignment::getLow() {
	return low;
}

float Assignment::getMean() {
	return mean;
}

#endif
