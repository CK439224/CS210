/*
****************************
*Name: Christopher King    *
*Date: 1/29/23             *
*Clase: CS-210             *
*Project2 AirGead Banking  *
****************************
*/

#include <iostream>
#include <iomanip>
#include <vector>
#include "DataInput.h"

using namespace std;

DataInput::DataInput() {

}

//User input method. Used to collect the users inputs
void DataInput::userInput() {
	double userInput;
	cout << "Initial Investment Amount : ";
	cin >> userInput;
	DataInput::posNumberCheck(userInput);
	setM_InitialInvestAmt(userInput);
	cout << "Monthly Deposit: ";
	cin >> userInput;
	DataInput::posNumberCheck(userInput);
	setM_MonthDep(userInput);
	cout << "Annual Interest: ";
	cin >> userInput;
	DataInput::posNumberCheck(userInput);
	setM_AnnualInt(userInput);
	cout << "Number of years: ";
	cin >> userInput;
	DataInput::posNumberCheck(userInput);
	setM_NumYears(userInput);
	system("pause");
	system("cls");
}
//Gets the initial investment amount
double DataInput::getM_InitialInvestAmt() const {
	return m_initialInvestAmt;
}
//Sets the initial investment amount
void DataInput::setM_InitialInvestAmt(double t_initialInvestAmt) {
	m_initialInvestAmt = t_initialInvestAmt;
}
//Gets the monthy deposit amount
double DataInput::getM_MonthlyDep() const {
	return m_monthDep;
}
//Sets the monthly deposit amount
void DataInput::setM_MonthDep(double t_monthlDep) {
	m_monthDep = t_monthlDep;
}
//Gets the annual interest percentage
double DataInput::getM_AnnualInt() const {
	return m_annualInt;
}
//Sets the annual interest percentage
void DataInput::setM_AnnualInt(double t_annualInt) {
	m_annualInt = t_annualInt;
}
//Gets the number of years
double DataInput::getM_NumYears() const {
	return m_numYears;
}
//Sets the number of years
void DataInput::setM_NumYears(double t_numYears) {
	m_numYears = t_numYears;
}
//Method used to print the header data
void DataInput::printHeader() {
	system("cls");
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
}
//Method to get the information and to call for the report to be printed
void DataInput::promptUser() {
	printHeader();
	userInput();
	cout << getM_InitialInvestAmt() << endl;
	cout << getM_MonthlyDep() << endl;
	cout << getM_AnnualInt() << endl;
	cout << getM_NumYears() << endl;
	printReport();
}
//Calculates the interest over the years with out making monthy deposits.
void DataInput::calcWithOutMonthlyDep() {
	double yearEndBalance = 0.00;
	double yearEndEarnedInterest = 0.00;
	double openAmt = getM_InitialInvestAmt();
	double interestRate = getM_AnnualInt();
	double currBal = openAmt;

	for (int i = 1; i <= getM_NumYears(); ++i) {
		int year = i;

		yearEndEarnedInterest = ((currBal) * ((interestRate / 100.00)));
		yearEndBalance = ((currBal)+yearEndEarnedInterest);
		cout << " ";
		cout << left << setw(10) << year;
		cout << fixed << setprecision(2) << setw(23) << yearEndBalance << setw(15) << yearEndEarnedInterest << endl;
		currBal = yearEndBalance;
		cout << endl;

	}
}
//Calculates the interest over the years with making monthy deposits.
void DataInput::calcWithMonthlyDep() {
	double yearEndBalance = 0.00;
	double yearEndEarnedInterest;
	double openAmt = getM_InitialInvestAmt();
	double interestRate = getM_AnnualInt();
	double monthDep = getM_MonthlyDep();
	double currBal = openAmt;
	double monthInt;

	for (int i = 1; i <= getM_NumYears(); ++i) {
		int year = i;

		yearEndEarnedInterest = 0;

		for (int j = 1; j <= 12; ++j) {
			monthInt = ((currBal + monthDep) * ((interestRate / 100) / 12));
			yearEndBalance = (currBal + monthDep) + monthInt;
			currBal = yearEndBalance;
			yearEndEarnedInterest = yearEndEarnedInterest + monthInt;
		}

		cout << " ";
		cout << left << setw(10) << year;
		cout << fixed << setprecision(2) << setw(23) << yearEndBalance << setw(15) << yearEndEarnedInterest << endl;
		currBal = yearEndBalance;
		cout << endl;

	}
}

//Method used to print the report headings and the calculation results.
void DataInput::printReport() {
	cout << "   Balance and Interest Without Aditional Monthly Deposits   " << endl;
	cout << "=============================================================" << endl;
	printf(" %-10s%-23s%-15s", "Year", "Year End Balance", "Year End Earned Interest");
	cout << endl;

	DataInput::calcWithOutMonthlyDep();
	cout << endl;

	cout << "     Balance and Interest With Aditional Monthly Deposits    " << endl;
	cout << "=============================================================" << endl;
	printf(" %-10s%-23s%-15s", "Year", "Year End Balance", "Year End Earned Interest");
	cout << endl;

	DataInput::calcWithMonthlyDep();


}
//Method to check if the user would like to restart the program
bool DataInput::choiceCheck() {
	string userChoice;
	cout << endl;
	cout << "Would you like to try more values? (y or n)" << endl;
	cin >> userChoice;

	if ((userChoice == "y") || (userChoice == "Y")) {
		return true;
	}
	else {
		return false;
	}
}
//Method to confirm users input is a positive number.
void DataInput::posNumberCheck(double& userInput) {
	while (userInput < 0) {
		while (userInput < 0) {
			cout << "Please select a positive number: " << endl;
			cin >> userInput;
			userInput = userInput;
		}
	}
}

