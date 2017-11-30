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
//I think .size will give us a bit value of the actual size of the array, not
//the amt of elements, we may need to use *sizeof(grades)/sizeof(grades[0])*
float Assignment::calculateMedian(vector<float > grades) {
    //Odd student size case
    if (grades.size()%2 == 1){
      return grades[(1+grades.size())/2-1];
    }
    //Even student size case
    else{
      return (grades[grades.size()/2-1] + grades[grades.size()/2])/2;
    }
}

//assuming grade array will be in order for mode calculation
float Assignment::calculateMode(vector<float > grades) {
    int mode = 1;
    int currentMode = 0;
    float possibleMode = grades[0];
    for (int i = 1; i < grades.size(); ++i){
      if grades[i] == grades[i-1]){
        currentMode++;
      }
      else{
        if (currentMode > mode){
          possibleMode = grades[i-1];
          mode = currentMode;
          currentMode = 0;
        }
      }
    }
    return possibleMode;
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
