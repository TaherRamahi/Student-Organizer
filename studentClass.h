#pragma once
#include<iostream>
#include <vector>
#include <cmath>
#include <iomanip>  
using namespace std;



class Student
{
	string firstName;
	string lastName;
	vector <float> quizScore;
	vector <float> testScore;
	float finalProject;

public:
	Student();
	bool aquireData(istream& in);
	void printData(ostream& out);
	string GetFirstName();
	string GetLastName();
	float CouseAverage();
	bool DisplayCourseAverage(ostream& out);
	string LetterGrade();
	//TEST FUNCTON
	float getTestScore();
	



};
void sortingAlg(vector<Student>& theOne);


float theSize();