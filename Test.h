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
 
public: 
    void grader(vector<string> student_answers);
    void FitB_grader(vector<string> fill_in_the_blank);
    void omitQuestions(vector<string> student_answers);
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
void Test::omitQuestion(vector<string> student_answers, int deletedIndex){
	student_answers.erase(studentAnswers.at(deletedIndex-1);
}

#endif
