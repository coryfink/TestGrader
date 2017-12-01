#ifndef _ASSIGNMENT_H_
#define _ASSIGNMENT_H_

#include <string>
#include <vector>

using namespace std;

class Assignment {
  private:
    string assignmentName;
    vector<Test> classTests;
    float high;
    float low;
    float mean;
    float curve;
  public:
    //Pass in vector containing grades to calculate stats
    float calculateHigh(vector<float > grades);
    float calculateLow(vector<float > grades);
    float calculateMean(vector<float > grades);
    float calculateMode(vector<float > grades);
    float calculateMedian(vector<float > grades);
    void organizeGrades(vector<float > &grades);
    float calculateCurve();
  
    //Accessor methods
    float getHigh();
    float getLow();
    float getMean();
};

float Test::calculateCurve(vector<float> grades){

    //not finished yet, trying to figure out how to return the "curved" grades vector
    float inputAverage;
    float curve;

    cout << "Please enter the desired average for this exam." << endl;
    cin >> inputAverage;
	
	float realAverage = grades.calculateMean(); //**calculateMean(grades)
	
	if(realAverage < inputAverage){
		curve = inputAverage - realAverage;
	}
	else{
		curve = 0;
	}
	for (int i = 0; i<grades.size(); i++){
		grades[i]=grades[i]+curve;
	}
	
}
void Test::omitQuestion(vector<string> studentAnswers, int deletedIndex){
	studentAnswers.erase(studentAnswers.at(deletedIndex-1);
}
float Test::calculateHigh(vector<float > grades){
    
    float high = 0;
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] > high) {
            high = grades[i];
        }
    }
    
    return high;
}
float Test::calculateLow(vector<float > grades) {
    
    float low = 100;
    for (int i = 0; i < grades.size(); i++) {
        if (grades[i] < low) {
            low = grades[i];
        }
    }
    
    return low;
}
float Test::calculateMean(vector<float > grades) {
    
    float sum = 0;
    for (int i = 0; i < grades.size(); i++) {
        sum += grades[i];
    }
    
    return sum / grades.size();
}
//I think .size will give us a bit value of the actual size of the array, not
//the amt of elements, we may need to use *sizeof(grades)/sizeof(grades[0])*
//maybe .capacity() is what we are looking for? need to test -mike
float Test::calculateMedian(vector<float > grades) {
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
float Test::calculateMode(vector<float > grades) {
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
float Test::getHigh() {//I dont think this->high works, pretty sure you have to do grades->high ? -mike
    
    return this->high;
}
float Test::getLow() {
    
    return this->low;
}
float Test::getMean() {
    
    return this->mean;
}

#endif
