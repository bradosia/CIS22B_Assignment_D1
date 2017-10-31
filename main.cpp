/*
Branden Lee
CIS 22B
Fall 2017
Assignment D
Problem D1

Used Microsoft Visual Studio 2017

Car class
*/
#include <iostream>
#include <iomanip>
#include <string>
#include <limits>
#include <fstream>      // std::fstream
#include <stdio.h>
using namespace std;

/**************************************************
** global functions, and variables
**************************************************/

void input ();

/**************************************************
** Car class
**************************************************/
class Car
{
private:
	string reportingMark;
	int carNumber;
	string kind;
	bool loaded;
	string destination;
public:
	Car () { setup ("", 0, "other", false, "NONE"); } //default constructor
	Car (const Car *CarObj) { setup (CarObj->reportingMark, CarObj->carNumber, CarObj->kind, CarObj->loaded, CarObj->destination); } //copy constructor
	Car (string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit) { setup (reportingMarkInit, carNumberInit, kindInit, loadedInit, destinationInit); } //other constructor
	~Car () {} // destructor
	void setup (string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit);
	void output ();
	friend bool Car::operator==(const Car CarObj1, const Car CarObj2)
	{
		if (CarObj1.reportingMark == CarObj2.reportingMark && CarObj1.carNumber == CarObj2.carNumber&& CarObj1.kind == CarObj2.kind&& CarObj1.loaded == CarObj2.loaded&& CarObj1.destination == CarObj2.destination) { return true; }
		return false;
	}
};

int main ()
{
	input ();
	system ("pause");
	return 0;
}

/**************************************************
** Car class method definitions
**************************************************/

/******************* Car::setup *******************
** Puts the data into the data structure
** height and radius into a pointer to the Cone
**************************************************/
void Car::setup (string reportingMarkInit, int carNumberInit, string kindInit, bool loadedInit, string destinationInit)
{
	reportingMark = reportingMarkInit;
	carNumber = carNumberInit;
	kind = kindInit;
	loaded = loadedInit;
	destination = destinationInit;
}

/********************* Car::output ****************
** Calls the getVolume function to get the volume
** Prints the height, radius, and volume in a neat
** format
**************************************************/
void Car::output ()
{
	// cout << bool will output an integer
	// we create a temporary string to output the bool
	// std::boolalpha can also be used
	string loadedString = (!loaded) ? "false" : "true";
	cout << setw (16) << left << "reportingMark:" << reportingMark << endl
		<< setw (16) << left << "carNumber: " << carNumber << endl
		<< setw (16) << left << "kind: " << kind << endl
		<< setw (16) << left << "loaded: " << loadedString << endl
		<< setw (16) << left << "destination: " << destination << endl;
}

/**************************************************
** global function definitions
**************************************************/

/********************* input **********************
** Reads the height and radius from the user as
** reference parameters
**************************************************/
void input ()
{
	string carType, reportingMarkInit, kindInit, destinationInit;
	int carNumberInit;
	bool loadedInit;
	std::fstream inputFile;
	inputFile.open ("data.txt");
	if (!inputFile)
	{
		cerr << "File could not be opened." << endl;
		exit (1);
	}
	/*
	while (inputFile.peek () != EOF)
	{
		while (inputFile.peek () == ' ')
			inputFile.get ();
		cin >> carType >> reportingMarkInit >> carNumberInit >> kindInit >> loadedInit;
		while (inputFile.peek () == ' ')
			inputFile.get ();
		getline (cin, destinationInit);
		if (carType == "Car")
		{
			Car temp (reportingMarkInit, carNumberInit, kindInit, loadedInit, destinationInit);
			temp.output ();
		}
		else
		{
			cerr << "Not a car" << endl;
		}
		inputFile.close ();
	}*/
}

/* Execution results
Enter each value promted for below followed by a hard return:
reportingMark: SP
carNumber: 34567
kind: business
loaded: true

Enter the destination
i.e. Salt Lake City
Salt Lake City

Contents of car1
reportingMark:  SP
carNumber:      34567
kind:           business
loaded:         true
destination:    Salt Lake City

Contents of car2
reportingMark:  SP
carNumber:      34567
kind:           business
loaded:         true
destination:    Salt Lake City

Contents of car3
reportingMark:
carNumber:      0
kind:           other
loaded:         false
destination:    NONE
car1 is the same car as car2
car2 is not the same car as car3
*/