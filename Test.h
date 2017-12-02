#ifndef _TEST_H_
#define _TEST_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

class Test {
	private:
		string name;
		string assignment_name;
		float test_grade;
		ifstream test_name;
		string filename

		vector<string> student_answers;//where we will store new test answers
		vector<string> fill_in_the_blank;//where we fill in the fill in the blank answers
		vector<string> key;//the correct answers to the text
		vector<string> FitB_key; //correct answers to fill in the blank

	public: 
		Test();

		void set_name(string student_name);

		void answer_input(string filename);

		void grader(vector<string> student_answers);
		void FitB_grader(vector<string> fill_in_the_blank);

		void omitQuestions(vector<string> student_answers);
};

Test::Test() {
	name = "";
	test_grade = NULL;
}

void set_name(string student_name) {
	name = student_name;
}

void answer_input(string filename) {
	cout<<"Please enter the name of text file containing the assignment: ";
	cin>>filename;
	sourceCode.open(filename);

		//below is for failing to find a file of the input name
		while(sourceCode.fail()) {
			cout<<"Error: there is no file named "<<filename<<endl;
			cout<<"Please enter the name of the input file: ";
			cin>>filename;
			sourceCode.open(filename);
		}

		//now filling the array representing the correct answers
		string currentLine;

		while(getline(sourceCode,currentLine)) {
			//checking to see if the current line is an answer and not a question of student name
			if(currentLine.find("?")==-1 && currentLine.find("Name")==-1) {
				student_answers.push_back(currentLine);
			}
		}
}

void Assignment::grader(vector<string> student_answers) {
	for (vector<string>::iterator key_iter = key.begin() ; key_iter != key.end() ; key_iter++) {
		for (vector<string>::iterator iter = student_answers.begin() ; iter != student_answers.end() ; iter++) {//initializes the iterator method from vector class, then starts at the beginning of the vector until it reaches the end comparing the answers of a test to the key
			if (*iter == *key_iter) {
				cout << "answer " << *iter << " is correct\n"; //waiting for other methods to see how we want to deal with correct/incorrect answers

				this->test_grade = true;
			} else {
				cout << "answer " << *iter << " is incorrect\n";

				this->test_grade = false;
			}
		}
	}
}

void Assignment::FitB_grader(vector<string> fill_in_the_blank) {
	for (vector<string>::iterator FitB_key_iter = FitB_key.begin() ; FitB_key_iter != FitB_key.end() ; FitB_key_iter++) {
		for (vector<string>::iterator FitB_iter = fill_in_the_blank.begin() ; FitB_iter != fill_in_the_blank.end() ; FitB_iter++) {
			if (*FitB_iter == *FitB_key_iter) {
				cout << "answer " << *FitB_iter << " is correct\n";

				this->test_grade = true;
			} else {
				cout << "answer " << *FitB_iter << " is incorrect\n";

				this->test_grade = false;
			}
		}
	}
}

void Test::omitQuestion(vector<string> student_answers, int deletedIndex)
	student_answers.erase(studentAnswers.at(deletedIndex-1);

#endif
