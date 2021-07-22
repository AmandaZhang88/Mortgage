// A class implementation file: Mortgage.cpp
// the number function definitions are stored there.

#include "Mortgage.h"
#include<iostream>
#include<cmath>
#include<cstdlib>
using namespace std;

double Mortgage::getLoanAmount() const {
	return loanAmount;
}

double Mortgage::getInterestRate() const {
	return annualInterestRate;
}

double Mortgage::getNumYears() const {
	return years;
}

void Mortgage::setLoanAmount(double a) {
	while (a < 0 ) {
		cout << " please input a vaild loan amount: ";
		cin >> years;
	};
	loanAmount = a;
}

void Mortgage::setInterestRate(double r) {
	while (r < 0 || r >1){
			cout << " please input a vaild interest rate: ";
			cin >> r;
		};
	annualInterestRate = r;
}

void  Mortgage::setNumYears(int y) {
	while (y < 0 || y >70){
			cout << " please input a vaild year between 0 - 70: ";
			cin >> years;
		};
	years = y;
}

double Mortgage::getMonthlyPayMent(double loanAmount, double annualInterestRate, int years) {
	numberOfPayments = years * 12;                          
	monthlyInterestRate = (annualInterestRate / 12);               
	powerFactor = pow((1 + monthlyInterestRate), numberOfPayments);  // (1+monthlyInterestRate)^ numberOfPayments
	// cout << powerFactor << endl;
	monthlyPayment = (loanAmount * monthlyInterestRate * powerFactor) / (powerFactor - 1);
	return monthlyPayment;
}

double Mortgage::getTotalAmountPaid(double loanAmount, double annualInterestRate, int years) {
	double totalPayBack = (monthlyPayment) * (numberOfPayments);
	//cout << monthlyPayment << "  * " << numberOfPayments << " = " << totalPayBack;
	return totalPayBack;
}
void Mortgage::outputPaymentSchedule(double loanAmount, double annualInterestRate, int years, string outFileName) {
	double balance = getLoanAmount();
	ofstream outFile(outFileName);
	outFile << setw(5) << "Pmt#";
	outFile << setw(22) << "Payment Amount";
	outFile << setw(22) << "Interest";
	outFile << setw(22) << "Contrib to principle";
	outFile << setw(22) << "Remaining balance" << endl;
	for (size_t i = 0; i < numberOfPayments; i++)
	{
		double interest = monthlyInterestRate * balance;
		double contrib_to_principle = getMonthlyPayMent(loanAmount, annualInterestRate, years) - interest;
		balance = balance - contrib_to_principle;
		outFile << setw(5) << (i + 1);
		outFile << setw(20) << getMonthlyPayMent(loanAmount, annualInterestRate, years);
		outFile << setw(20) << interest;
		outFile << setw(20) << contrib_to_principle;
		outFile << setw(20) << balance << endl;
	}
	outFile.close();

}
