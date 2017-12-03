//test.h
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
		int correct_answers;

		vector<string> student_answers;//where we will store new test answers
		vector<string> fill_in_the_blank;//where we fill in the fill in the blank answers
		vector<string> key;//the correct answers to the text
		vector<string> FitB_key;//correct answers to fill in the blank

		vector<bool> correctness;//to make grading easier
	public: 
		Test();
		Test(string temp_name);

		void set_name(string student_name);

		void answer_input(string filename);

		float grader(vector<string> student_answers);
		float FitB_grader(vector<string> fill_in_the_blank);

		//accessors
		string getName();
};

Test::Test() {
	name = "";
	assignment_name = "";
	test_grade = 0.0;
}

Test::Test(string temp_name) {
	name = "";
	assignment_name = temp_name;
	test_grade = 0.0;
}

void Test::set_name(string student_name) {
	name = student_name;
}
string Test::getName(){
	return name;
}

void Test::answer_input(string filename) {
	ifstream sourceCode;
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
		//if(currentLine.find("?") == -1 && currentLine.find("Name") == -1) {
			student_answers.push_back(currentLine);
		//}
	}
}

float Test::grader(vector<string> student_answers) {
	int key_size = key.size();//make the size a constant to reduce complexity
	for (int i = 0; i < key_size ; i++) {
		if (student_answers[i] == key[i]) {
			cout << "the answer is correct" << endl;
			//will compare the two and if they are the same, set the correctness array equal to true
			correctness[i] = true;
		} else {
			cout << "the answer is incorrect" << endl;
			//same thing but sets it to false
			correctness[i] = false;
		}
	}
	
	correct_answers = 0;
	int size = correctness.size();

	for (int i = 0; i < size; i++) {
		if (correctness[i]) {//if the answer is correct
			correct_answers++;
		}
	}

	test_grade = correct_answers / size;
	return test_grade;
}

#endif
