//assignment.h
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
		//vector assignments
		string assignmentName;
		Test temp;
		vector<Test> classTests;
		vector<float> grades;

		//float variable assignments
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
		float calculateCurve(vector<float> grades);
		void printStatistics();
  
		//Accessor methods
		float getHigh();
		float getLow();
		float getMean();

		//mutator methods
		void set_vector_index(float numerical_grade);
		void set_name(string name);
};

Assignment::Assignment(string temp_name) {
	assignmentName = temp_name;
	vector<Test> classTests(0);
}

void Assignment::set_vector_index(float numerical_grade) {

}

void Assignment::set_name(string name) {

}

void Assignment::add_test(Test temp) {
	classTests.push_back(temp);
}

//method that calculates the highest value in the vector of grades
float Assignment::calculateHigh(vector<float> grades) {
	float high = 0;
	int size = grades.size();
	//for loops that accesses each grade in the vector and compares it to the current high
	for (int i = 0; i < size; i++) {
		if (grades[i] > high) {
			high = grades[i];
		}
	}
	return high;
}

//calculates the lowest value in the vector of grades
float Assignment::calculateLow(vector<float> grades) {
	float low = 100;
	int size = grades.size();
	//for loops that accesses every grade in the vector and compares it to the current low
	for (int i = 0; i < size; i++) {
		if (grades[i] < low) {
			low = grades[i];
		}
	}
	return low;
}

//calculates te average
float Assignment::calculateMean(vector<float> grades) {
	float sum = 0;
	int size = grades.size();
	for (int i = 0; i < size; i++) {
		sum += grades[i];
	}
	return sum / size;
}

//adds a curve to the tests
float Assignment::calculateCurve(vector<float> grades) {
//not finished yet, trying to figure out how to return the "curved" grades vector
	float inputAverage;

	cout << "Please enter the desired average for this exam." << endl;
	cin >> inputAverage;
	
	float realAverage = calculateMean(grades); //**calculateMean(grades)
	
	if (realAverage < inputAverage) {
		curve = inputAverage - realAverage;
	} else {
		curve = 0;
	}

	int size = grades.size();

	for (int i = 0; i < size; i++) {
		grades[i] = grades[i] + curve;
	}

	return curve;
}

//Method to organize the vector that holds all the grades
void Assignment::organizeGrades(vector<float> grades){
	sort(grades.begin(), grades.end());//using sort function for vectors (algorithm header)
}

//I think .size will give us a bit value of the actual size of the array, not
//the amt of elements, we may need to use *sizeof(grades)/sizeof(grades[0])*
//maybe .capacity() is what we are looking for? need to test -mike
float Assignment::calculateMedian(vector<float> grades) {
	//Odd student size case
	int size = grades.size();
	if (size % 2 == 1) {
		return grades[( 1 + size) / 2 - 1];
	} else {
		return (grades[size / 2 - 1] + grades[size / 2 ]) / 2;
	}
}

//assuming grade array will be in order for mode calculation
float Assignment::calculateMode(vector<float> grades) {
	int mode = 1;
	int currentMode = 0;
	float possibleMode = grades[0];
	int size = grades.size();	
	for (int i = 1; i < size; i++) {//loops through grades and counts recurring grades
		if (grades[i] == grades[i - 1]){
			currentMode++;
		} else if (currentMode > mode) {//sets the possible mode once it is greater than the current
			possibleMode = grades[i - 1];
			mode = currentMode;
			currentMode = 0;
		}
	}
	return possibleMode;
}

//accessor methods for grade statistics
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
