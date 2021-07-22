// A “main program” file: Lab13a.cpp

#include<iostream>
#include<iomanip>
#include"Mortgage.h"    // nedded for Mortgage class
using namespace std;

int main() {
	char answer = 'y';
	do {
		Mortgage loan;      // define an instance of the Mortgage class
		double loanAmount,
			annualInterestRate,
			monthlyInterestRate,
			totalYearsToRepay,
			numberOfPayments;
		int    years;
		double monthlyPayment;


		cout << "Enter the amount of the loan: ";
		cin >> loanAmount;
		loan.setLoanAmount(loanAmount);

		cout << "Enter the annual interest rate in decimal form (example .075):  ";
		cin >> annualInterestRate;
		loan.setInterestRate(annualInterestRate);

		cout << "Enter the length of the loan in years: ";
		cin >> years;
		loan.setNumYears(years);

		// display the Mortgage's data
		cout << "\nLoan Amount: " << noshowpoint << loan.getLoanAmount() << endl;
		cout << "Annual Interest Rate: " << loan.getInterestRate() << endl;
		cout << "Years to repay: " << loan.getNumYears() << endl;
		cout << "Monthly Payment: $" << setprecision(2) << fixed << loan.getMonthlyPayMent(loanAmount, annualInterestRate, years) << endl;
		cout << "Total Pay Back: $" << setprecision(2) << fixed << loan.getTotalAmountPaid(loanAmount, annualInterestRate, years) << endl;
		//loan.outputPaymentSchedule(loanAmount, annualInterestRate, years, outFileName);

		cout << "Do you wish to process another loan?  ";
		cin >> answer;
		cout << "------------------------" << endl;
	} while (answer == 'Y' || answer == 'y');

	return 0;
}