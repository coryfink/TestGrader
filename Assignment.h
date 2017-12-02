#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
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
		void organizeGrades(vector<float> grades);
		float calculateCurve();
  		void printStatistics()
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

void Assignment::printStatistics(){
    cout<<"| Mean: "<< getMean() <<" | High: "<< getHigh() << " | Low: "<< getLow() <<endl;
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

void Assignment::organizeGrades(vector<float> grades){
	sort(grades.begin(), grades.end());
}
float Assignment::calculateMedian(vector<float> grades) {
	organizeGrades(grades);
	//Odd student size case
	if (grades.size()%2 == 1) {
		return grades[(1+grades.size())/2-1];
	} else {
		return (grades[grades.size()/2-1] + grades[grades.size()/2])/2;
	}
}

//Method to calculate the Mode from the grades
float Assignment::calculateMode(vector<float> grades) {
	organizeGrades(grades);
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

//Accessor methods for the Mean/High/Low grade elements of the assignment class
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
