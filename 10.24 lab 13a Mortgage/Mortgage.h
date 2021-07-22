// A class specification file: Mortgage.h 
// a header file that contains a class declaration.

#ifndef MORTGAGE_H
#define MORTGAGE_H
#include<iostream>
#include<string>
#include<iomanip>
#include<fstream>

using namespace std;

class Mortgage {           // class + classname , inside all variable  and function program need
private:
	double loanAmount,
		   annualInterestRate,
		   monthlyInterestRate,
		   monthlyPayment,
		   powerFactor,
		   totalYearsToRepay;
	int    years,
		   numberOfPayments;
	string name,
		   outFileName;

public:
	// Function prototype
	void setLoanAmount(double);
	void setInterestRate(double);
	void setNumYears(int);
	double getLoanAmount() const;
	double getInterestRate() const;
	double getNumYears() const;
	double getMonthlyPayMent(double, double, int);
	double getTotalAmountPaid(double, double, int);
	void outputPaymentSchedule(double, double, int, string);
};

#endif

