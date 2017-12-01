#ifndef _TEST_H_
#define _TEST_H_

#include <string>
#include <vector>

using namespace std;

class Test {
 private:
  vector<string> student_answers;//where we will store new test answers
  float curve;
  vector<string> fill_in_the_blank;//where we fill in the fill in the blank answers
  vector<string> key;//the correct answers to the text
  vector<string> FitB_key; //
  
  float high;
  float low;
  float mean;
  
public: 
  
    void grader(vector<string> student_answers);
    void FitB_grader(vector<string> fill_in_the_blank);
  
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

void Test::grader(vector<string> student_answers) {
   for (vector<float>::iterator key_iter = key.begin() ; key_iter != key.end() ; key_iter++) {
      for (vector<float>::iterator iter = student_answers.begin() ; iter != student_answers.end() ; iter++) {//initializes the iterator method from vector class, then starts at the beginning of the vector until it reaches the end comparing the answers of a test to the key
        if (*iter == *key_iter) {
          cout << "answer " << *iter << " is correct\n"; //waiting for other methods to see how we want to deal with correct/incorrect answers
        } else {
          cout << "answer " << *iter << " is incorrect\n";
        }
      }
  }
}

void Test::FitB_grader(vector<string> fill_in_the_blank) {
    for (vector<string>::iterator FitB_key_iter = FitB_key.begin() ; FitB_key_iter != FitB_key.end() ; FitB_key_iter++) {
        for (vector<string>::iterator FitB_iter = fill_in_the_blank.begin() ; FitB_iter != fill_in_the_blank.end() ; FitB_iter++) {
            if (*FitB_iter == *FitB_key_iter) {
                cout << "answer " << *FitB_iter << " is correct\n";
            } else {
                cout << "ansewr " << *FitB_iter << " is incorrect\n";
            }
        }
    }
}

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
