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
		float mode;

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
  		void displayAll();
		//Accessor methods
		float getHigh();
		float getLow();
		float getMean();
		vector* getGrades();
		vector* getTest();

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
void Assignment::calculateLow() {
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
void Assignment::calculateCurve() {
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
	cout<<"Please utilize the "Calculate Statistics" option in the user interface to see new assignment statistics accounting for the curve.\n";
}

//Method to organize the vector that holds all the grades
void Assignment::organizeGrades(vector<float> grades){
	sort(grades.begin(), grades.end());//using sort function for vectors (algorithm header)
}

//Method to calculate the Median of the grades
float Assignment::calculateMedian(vector<float> grades) {
	//Organizing the scores
	organizeGrades(grades);
	
	//Odd student size case: returning the middle grade in the vector
	if (grades.size()%2 == 1) {
		return grades[(1+grades.size())/2-1];
	}
	//Even student size case: returning the average value between the two middle grades
 	else {
		return (grades[grades.size()/2-1] + grades[grades.size()/2])/2;
	}
}

//Method to calculate the Mode of the grades
float Assignment::calculateMode(vector<float> grades) {
	//Organizing the scores and setting the initial mode to 1
	organizeGrades(grades);
	int overallMode = 1;
	int currentMode = 1;
	float possibleMode = grades[0];
	
	//Looping through the grades and counting recurring grades
	for (int i = 1; i < grades.size(); ++i) {
		if (grades[i] == grades[i-1]){
			currentMode++;
		}
		//Setting the possible mode once the current mode surpasses the overall mode
 		else if (currentMode > overallMode) {
			possibleMode = grades[i-1];
			overallMode = currentMode;
			currentMode = 1;
		}
	}
	return possibleMode;
}

//printing method that displays the grade statistics 
void Assignment::printStatistics(){
    cout<<"| Mean: "<< getMean() <<" | High: "<< getHigh() << " | Low: "<< getLow() <<endl;
}

//printing method that displays all student names and scores
void Assignment::displayAll(){
    vector <string> names = getTest().getName();
    for(it = getGrades.begin(); itt = names.begin();  it != getGrades.end(); itt = names.end(); it++,itt++ ){
        cout<< "\t" << *itt << "\t|\t" << *it << endl;
    }
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
vector* Assignment::getGrades() {
	return *grades;
}

vector* Assignment::getTest() {
	return *classTests;
}

#endif
