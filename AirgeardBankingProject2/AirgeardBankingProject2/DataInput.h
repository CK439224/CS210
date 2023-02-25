/*
****************************
*Name: Christopher King    *
*Date: 1/29/23             *
*Clase: CS-210             *
*Project2 AirGead Banking  *
****************************
*/

#ifndef DATAINPUT_H
#define DATAINPUT_H

#include <vector>
using namespace std;

class DataInput {
public:   //Public Members
	DataInput();
	double getM_InitialInvestAmt() const;
	void setM_InitialInvestAmt(double t_initialInvestAmt);
	double getM_MonthlyDep() const;
	void setM_MonthDep(double t_monthlyDep);
	double getM_AnnualInt() const;
	void setM_AnnualInt(double t_annualInt);
	double getM_NumYears() const;
	void setM_NumYears(double t_numYears);
	void promptUser();
	void userInput();
	void printReport();
	void calcWithOutMonthlyDep();
	void calcWithMonthlyDep();
	bool choiceCheck();
	void posNumberCheck(double& userInput);

private:   //Private members
	double m_initialInvestAmt = 0;
	double m_monthDep = 0;
	double m_annualInt = 0;
	double m_numYears = 0;
	void printHeader();
};


#endif

