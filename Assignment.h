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
		Assignment(string temp_assignment_name);

		void add_test(Test temp);
		void calculateHigh();
 		void calculateLow();
 		void calculateMean();
 		void calculateMode();
 		void calculateMedian();
		void organizeGrades();
	 	void calculateCurve();
		void printStatistics();
  
		//Accessor methods
		float getHigh();
		float getLow();
		float getMean();

		//mutator methods
		void set_vector_index(float numerical_grade);
		void set_name(string name);
};

Assignment::Assignment(string temp_assignment_name) {
	assignmentName = temp_assignment_name;
	vector<Test> assignmentName (0);
}

void Assignment::set_vector_index(float numerical_grade) {
	grades.push_back(numerical grade);
}

void Assignment::set_name(string name) {
	assignmentName = name;
}

void Assignment::add_test(Test temp) {
	classTests.push_back(temp);
}

//method that calculates the highest value in the vector of grades
void Assignment::calculateHigh() {
	float high = 0;
	int size = grades.size();
	//for loops that accesses each grade in the vector and compares it to the current high
	for (int i = 0; i < size; i++) {
		if (grades[i] > high) {
			high = grades[i];
		}
	}
}

//calculates the lowest value in the vector of grades
Assignment::calculateLow() {
	float low = 100;
	int size = grades.size();
	//for loops that accesses every grade in the vector and compares it to the current low
	for (int i = 0; i < size; i++) {
		if (grades[i] < low) {
			low = grades[i];
		}
	}
}

//calculates te average
void Assignment::calculateMean() {
	float sum = 0;
	int size = grades.size();
	for (int i = 0; i < size; i++) {
		sum += grades[i];
	}
	mean = sum / size;
}

//adds a curve to the tests
Assignment::calculateCurve() {
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
}

//Method to organize the vector that holds all the grades
void Assignment::organizeGrades(vector<float> grades){
	sort(grades.begin(), grades.end());//using sort function for vectors (algorithm header)
}

//I think .size will give us a bit value of the actual size of the array, not
//the amt of elements, we may need to use *sizeof(grades)/sizeof(grades[0])*
//maybe .capacity() is what we are looking for? need to test -mike
void Assignment::calculateMedian() {
	//Odd student size case
	int size = grades.size();
	if (size % 2 == 1) {
		median = grades[( 1 + size) / 2 - 1];
	} else {
		median = (grades[size / 2 - 1] + grades[size / 2 ]) / 2;
	}
}

//assuming grade array will be in order for mode calculation
void Assignment::calculateMode() {
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
	mode = possibleMode;
}

//printing method that displays the grade statistics 
void Assignment::printStatistics(){
    cout<<"| Mean: "<< getMean() <<" | High: "<< getHigh() << " | Low: "<< getLow() <<endl;
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
