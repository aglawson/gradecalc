#include <iostream>
#include "Header.h"
using namespace std;

void printmenu()
{
	cout << "Make a Selection" << endl;
	cout << "A: Add Assignment" << endl;
	cout << "P: Print Assignments and Total Grade" << endl;
	cout << "F: Find out what you need on the final to get your desired grade" << endl;
	cout << "D: Delete Last Entered Assignment" << endl;
	cout << "C: Clear All Assignments" << endl;
	cout << "Q: Quit" << endl;
}
int main()
{
	string name;
	int possible;
	float percentage;
	char userChoice;

	Assignments myass;
	cout << "To accurately calculate your grades, this program requires information about the weight of each assignment." << endl;
	cout << "For example, if your class syllabus says the final exam is worth 25% of your overall grade, enter 25." << endl;
	cout << "Please have your syllabus available for reference" << endl << endl;
	printmenu();

	cin >> userChoice;
	while (userChoice != 'Q' && userChoice != 'q')
	{
		switch (userChoice)
		{
		case 'a':
		case 'A':
			myass.addAssignment();
			break;

		case 'p':
		case 'P':
			myass.printGrades();
			break;
		case 'd':
		case 'D':
			myass.deleteLastAssignment();
			break;
		case 'f':
		case 'F':
			myass.whatif();
			break;
		case 'c':
		case 'C':
			myass.clearAssignments();
		case 'q':
		case 'Q':
			break;
		}
		printmenu();
		cin >> userChoice;
	}
}