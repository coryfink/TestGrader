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
	Private:
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

	Public:
	//pass in vector containing grades to calculate stats
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
	
		//mutator methods
		void set_vector_index(float numerical_grade);
		void set_name(string name);
};

Assignment::Assignment(string temp_name) {
	assignmentName = temp_name;
	new vector<Test> assignmentName = classTests;
}
void Assignment::set_vector_index(float numerical_grade){
	
}
void Assignment::set_name(string name){
	
}
void Assignment::add_test(Test temp) {
	classTests.push_back(temp);
}

//method that calculates the highest value in the vector of grades
float Assignment::calculateHigh(vector<float> grades) {
	float high = 0;
	
	//for loop that accesses each grade in the vector
	//compares first element to the one preceding it 
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i] > high) {
			high = grades[i];
		}
	}
	return high;
}

//method that calculates the lowest value in the vector of grades
float Assignment::calculateLow(vector<float> grades) {
	float low = 100;

	//for loop that accesses each grade in the vector
	//compares first element to the one preceding it
	for (int i = 0; i < grades.size(); i++) {
		if (grades[i] < low) {
			low = grades[i];
		}
	}
	return low;
}

//method that calculates the mean (average) value of the grades 
float Assignment::calculateMean(vector<float> grades) {
	float sum = 0;
	//for loop that accesses each grade in the vector
	//sums the values of every grade in the vector and divides by total # of grades
for (int i = 0; i < grades.size(); i++) {
		sum += grades[i];
	}
	return sum / grades.size();
}

//printing method that displays the grade statistics 
void Assignment::printStatistics(){
    cout<<"| Mean: "<< getMean() <<" | High: "<< getHigh() << " | Low: "<< getLow() <<endl;
}   

//method that adds a curve to each grade in the vector
//takes in the original vector of grades
float Assignment::calculateCurve(vector<float> grades) {
//
	float inputAverage;

	cout << "Please enter the desired average for this exam." << endl;
	cin >> inputAverage;
	
	float realAverage = calculateMean(grades);
	
	if (realAverage < inputAverage) {
		curve = inputAverage - realAverage;
	}
 else {
		curve = 0;
	}
	for (int i = 0; i<grades.size(); i++) {
		grades[i]=grades[i]+curve;
	}
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
	
	//Even student size case: returning the average value between the two middle grades
} else {
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

