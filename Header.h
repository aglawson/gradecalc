#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <iterator>
using namespace std;

struct Assignment
{
	string assignmentname;
	int pointsPossible;
	float gradePercentage;
	float assignmentGrade;
};

class Assignments
{
public:
	void addAssignment()
	{
		string name;
		int possible;
		float earned;
		Assignment A;
		cout << "Enter Assignment Name (NO SPACES): ";
		cin >> name;
		A.assignmentname = name;
		cout << "How Much of Overall Grade is " << name << " worth? ";
		cin >> possible;
		A.pointsPossible = possible;
		cout << "Enter Percentage Grade Earned: ";
		cin >> earned;
		A.gradePercentage = earned / 100;
		AssignmentStorage.push_back(A);
		AssignmentCount++;
	}
	float calcGrade()
	{
		Assignment A;
		float totalGrade = 0;
		int count;

		for (int i = 0; i < AssignmentCount; i++)
		{
			AssignmentStorage[i].assignmentGrade = AssignmentStorage[i].pointsPossible * AssignmentStorage[i].gradePercentage;
		}

		for(int count = 0; count < AssignmentCount; count++)
		{
			totalGrade += AssignmentStorage[count].assignmentGrade;
		}

		return totalGrade;

	}
	void printGrades(void)
	{
		Assignment A;
		float gradesofar = 0;
		int pointsattempted = 0;
		cout << "Here are your " << AssignmentCount << " assignments" << endl;
		for (int i = 0; i < AssignmentCount; i++)
		{
			cout << AssignmentStorage[i].assignmentname << ": ";
			cout << AssignmentStorage[i].gradePercentage * AssignmentStorage[i].pointsPossible<< "/";
			cout << AssignmentStorage[i].pointsPossible << " ";
			cout << endl;
		}

		for (int j = 0; j < AssignmentCount; j++)
		{
			gradesofar += AssignmentStorage[j].gradePercentage;
			pointsattempted += AssignmentStorage[j].pointsPossible;
		}
		cout << "Grade out of Completed Assignments: " << (calcGrade() /(float) pointsattempted) * 100 << "% "<< endl;
		cout << "Total Grade: " << calcGrade() << "/100%" << endl;
	}

	void whatif()
	{
		float desiredGrade;
		int finalexamvalue;
		float need;
		cout << "Enter Desired Overall Course Grade Percentage (ex. 90): ";
		cin >> desiredGrade;
		cout << "How many overall grade points is your final worth? ";
		cin >> finalexamvalue;
		if (calcGrade() + finalexamvalue >= desiredGrade)
		{
			need = ((desiredGrade - calcGrade()) /(float) finalexamvalue) * 100;
			cout << "To get " << desiredGrade << "% in the class, you need a " << need << "% on the final exam" << endl;
		}
		else
		{
			cout << "At this point, there is no possible way to get " << desiredGrade << "% in the class" << endl;
		}
	}

	void deleteAssignment()
	{
		AssignmentStorage.pop_back();
		AssignmentCount--;
	}

private:
	int AssignmentCount = 0;
	vector<Assignment> AssignmentStorage;
};