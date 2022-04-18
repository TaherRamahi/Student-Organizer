#include <iostream>
#include <fstream>
#include "studentClass.h"

using namespace std;

vector <Student> theStudents;
ifstream inputFile("projectData.txt");
ofstream outputFile("theOutputFile.txt");


int main()
{
	Student student;

	while (!inputFile.eof())
	{
		
		student.aquireData(inputFile);
		theStudents.push_back(student);
	}

	
	// TEST WORK's
	
			sortingAlg(theStudents);
	
	

	for (int i = 0; i < theStudents.size(); i++)
	{
		cout.width(20);
		cout <<left <<theStudents.at(i).GetFirstName() << "  ";
		cout.width(20);

		cout<<left << theStudents.at(i).GetLastName() ;
		
		cout.width(10);
		cout << setprecision(3) << theStudents.at(i).CouseAverage() << "     ";
		cout.width(5);
		cout << theStudents.at(i).LetterGrade() << endl;
	}
	
	for (int i=0; i< theStudents.size();  i++)
	{
		theStudents.at(i).printData(outputFile);
		
		
	}
	

	return 0;
}

