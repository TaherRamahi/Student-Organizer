#include "studentClass.h"

vector<float> theCourseAvg;

Student::Student()
{
	string firstName = "";
	string lastName = "";
	vector <float> quizScore;
	vector <float> testScore;
	float finalProject = 0;

}

bool Student::aquireData(istream& in)
{
	if (in.good())
	{
		in >> firstName >> lastName;

		//cout << firstName << lastName;
		
		for (int i = 0 ; i < 4; i++)
		{
			float tempVal = 0;
			in >> tempVal;

			quizScore.push_back(tempVal);

		}
		
		for (int q=0; q < 2; q++)
		{
			float tempVal2 = 0;
			in >> tempVal2;

			testScore.push_back(tempVal2);

		}
		in >> finalProject;
		return true;
	}
	else
	{
		return false;
	}
}




string Student::GetFirstName()
{
	return firstName;
}

string Student::GetLastName()
{
	return lastName;
}
// this should work properly
float Student::CouseAverage()
{
	float theAvg;
	float tempQuiz = 0;
	float tempTest = 0;
	float tempFinal = 0;
	//this is only to calculate the quiz score
	for (int i = 0; i < quizScore.size(); i++)
	{
		tempQuiz += quizScore.at(i);
	}
	tempQuiz = tempQuiz / quizScore.size();
	tempQuiz = tempQuiz * 10;
	tempQuiz = tempQuiz * 35;

	//this is for test score calculation
	for (int i = 0; i < testScore.size(); i++)
	{
		tempTest += testScore.at(i);
	}
	tempTest = tempTest / testScore.size();
	tempTest = tempTest * 35;

	tempFinal = finalProject * 30;

	theAvg = tempQuiz + tempFinal + tempTest;
	theAvg = theAvg / 100;

	return  theAvg;
}

// should be working
bool Student::DisplayCourseAverage(ostream& out)
{
	if (out.good())
	{
		out << CouseAverage();
		return true;
	}

	else
	{
		return false;
	}
}
void Student::printData(ostream& out)
{
	if (out.good())
	{
		out.width(20);
		out << left << firstName;

		out.width(20);
		out << left << lastName;

		for (int i = 0; i < 4; i++)
		{
			out.width(4);
			out << right << quizScore.at(i);
		}
		for (int i = 0; i < 2; i++)
		{
			out.width(5);
			out << right << testScore.at(i);
		}

		out.width(5);
		out << right << finalProject ;

		out.width(10);
		setprecision(3);
		DisplayCourseAverage(out);
	
		out.width(5);
		out << LetterGrade();
		
		out<< endl;
	
	
	}

}

// DONE
string Student::LetterGrade()
{
	if (CouseAverage() >= 93)
	{
		return "A";
	}
	else if (CouseAverage() >= 90)
	{
		return "A-";
	}
	else if (CouseAverage() >= 87)
	{
		return "B+";
	}
	else if (CouseAverage() >= 83)
	{
		return "B";
	}
	else if (CouseAverage() >= 80)
	{
		return "B-";
	}
	else if (CouseAverage() >= 77)
	{
		return "C+";
	}
	else if (CouseAverage() >= 73)
	{
		return "C";
	}
	else if (CouseAverage() >= 70)
	{
		return "C-";
	}
	else if (CouseAverage() >= 67)
	{
		return "D+";
	}
	else if (CouseAverage() >= 63)
	{
		return "D";
	}
	else if (CouseAverage() >= 60)
	{
		return "D-";
	}
	else
	{
		return "F";
	}

}

//THIS ISNT WORKING RIGHT NOW 
void sortingAlg(vector<Student>& theOne)
{
	// int i = 0;
	//float tempVar = theOne.at(i).CouseAverage();
	vector<float> theCourseAvg;
	for (int i = 0; i < theOne.size(); i++)
	{
		theCourseAvg.push_back(theOne.at(i).CouseAverage());
	}
	
	for (int i = 0; i < theCourseAvg.size(); i++)
	{
		
		for (int q = 0; q < theCourseAvg.size() - 1; q++)
		{
		
				if (theCourseAvg.at(q + 1) > theCourseAvg.at(i))
				{

					swap(theOne.at(i), theOne.at(q + 1));

				}
		}

	}
	
}




// TEST FUNCTIONS

float Student::getTestScore()
{
	return quizScore.at(0);
}


