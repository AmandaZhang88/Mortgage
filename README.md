# Mortgage

This Mortgage program using C++, that is determine the monthly payment on a loan. The class 
should have member functions for setting the loan amount, interest rate, and number of years of the loan. It 
should also have member functions for returning the monthly payment amount and the total amount paid to the 
bank over the life of the loan.

monthlyPayment = (loanAmount ∗ monthlyInterestRate ∗ powerFactor)/(powerFactor − 1)

where powerFactor = (1 + monthlyInterestRate)^numberOfPayments

and monthlyInterestRate = annualInterestRate / 12

and numberOfPayments = numberOfYears * 12

For example, if you borrow $250,000.00 in a 30-year fixed rate mortgage, at 4.75 % interest per year:

numberOfPayments = 30 * 12 = 360

monthlyInterestRate = 0.0475 / 12 = 0.00395833

powerFactor = (1 + 0.00395833)^360 = 4.14618

Monthly payment = $1304.12.

Total Pay back = (Monthly payment) * (numberOfPayments) = $469482.60.
