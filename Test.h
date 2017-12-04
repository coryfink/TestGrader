//test.h
#ifndef _TEST_H_
#define _TEST_H_

#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>

using namespace std;

class Test {
	private:
		string name;
		string assignment_name;
		float test_grade;

	public:
		Test();
		Test(string temp_name);

		vector<string> student_answers;//where we will store new test answers

		void set_name(string student_name);

		string getName();

		void answer_input(string filename);

		float grader(vector<string> student_answers, vector<string> key);

		void omitQuestion(vector<string> student_answers, int deletedIndex);

		void delete_index();

		vector<string> * get_vector();

		void printAnswers();
};

Test::Test() {
	name = "";
	assignment_name = "";
	test_grade = 0.0;
}

Test::Test(string temp_name) {
	name = temp_name;
	assignment_name = "";
	test_grade = 0.0;
}

void Test::set_name(string student_name) {
	name = student_name;
}

string Test::getName() {
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

float Test::grader(vector<string> student_answers, vector<string> key) {
	int key_size = key.size();//make the size a constant to reduce complexity
	float questions = key.size();
	float counter = 0;
	
	/*for (int i = 0; i < key_size ; i++) {
		if (student_answers[i] == key[i]) {
			cout << "\tthe answer is correct\n";
			//will compare the two and if they are the same, set the correctness array equal to true
		
			correctness.push_back(true);
		} else {
			cout << "\tthe answer is incorrect\n";
			//same thing but sets it to false
			correctness.push_back(false);
		}
	}
	
	correct_answers = 0;
	int size = correctness.size();

	for (int i = 0; i < size; i++) {
		if (correctness[i] == true) {//if the answer is correct
			correct_answers++;
			cout << "nom nom \n";
		}
	}
	*/

	for (int i = 0; i < key_size ; i++) {
		if (student_answers[i] == key[i]) {
			counter++;
		} else if (student_answers[i] == "NULL") {
			--questions;
		}
	}

	test_grade = counter / questions;
	cout << counter << "/" << questions << endl;
	cout << test_grade << endl;
	return test_grade;
}

vector<string> * Test::get_vector() {
	vector<string> * pointer = &student_answers;
	return pointer;
}

void Test::printAnswers() {
	for(vector<string>::iterator sa_iter = student_answers.begin(); sa_iter != student_answers.end(); ++sa_iter) {
		cout << "Answer: " << *sa_iter << endl;
	}
}
#endif
