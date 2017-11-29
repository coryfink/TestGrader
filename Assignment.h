#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

#include <string.h>

using namespace std;

Class Assignment {
  
  vector<float > grades;
  float high;
  float low;
  float mean;
  
public: 
  
  
    //Pass in vector containing grades to calculate stats
    float calculateHigh(vector<float > grades);
    float calculateLow(vector<float > grades);
    float calculateMean(vector<float > grades);
  
    //Accessor methods
    float getHigh();
    float getLow();
    float getMean();

  
  
};



//write all methods after this


float Assignment::calculateHigh(vector<float > grades){
    
    float high = 0;
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] > high) {
            high = grades[i];
        }
    }
    
    return high;
}

float Assignment::calculateLow(vector<float > grades) {
    
    float low = 100;
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] < low) {
            low = grades[i];
        }
    }
    
    return low;
}

float Assignment::calculateMean(vector<float > grades) {
    
    float sum = 0;
    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i];
    }
    
    return sum / grades.size();
}

float Assignment::getHigh() {
    
    return this->high;
}

float Assignment::getLow() {
    
    return this->low;
}

float Assignment::getMean() {
    
    return this->mean;
}





//write all methods before this
#endif
