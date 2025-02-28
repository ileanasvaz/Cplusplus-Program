/* Ileana Vazquez 
*CS210 Project 2
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	//Declare variables for input 
	float initialInvestment, monthlyDeposit, annualInterest, months, years;

	//Declare variables to store year end total amount, interest, and year-end interest
	float totalAmount, interestAmount, yearlyTotalInterest;

	//Display menu to user
	cout << "**************************************" << endl;
	cout << "************ Data Input **************" << endl;
	cout << "Initial Investment Amount: $" << endl;
	cout << "Monthly Deposit: $" << endl;
	cout << "Annual Interest: %" << endl;
	cout << "Number of years: " << endl;
	cout << "**************************************" << endl;

	// Get user input 
	cout << "Initial Investment Amount: $";
	cin >> initialInvestment;
	cout << "Monthly Deposit: $";
	cin >> monthlyDeposit;
	cout << "Annual Interest: %";
	cin >> annualInterest;
	cout << "Number of years: ";
	cin >> years;

	//Calculate the total number of months 
	months = years * 12;

	//Initialize totalAmount to initial investment 
	totalAmount = initialInvestment;

	//Display resuts WITHOUT monthly deposits 
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "----------------------------------------------------------------" << endl;
	cout << "Year        Year End Balance            Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//Calculate yearly interest and year-end total without monthly deposits 
	for (int i = 0; i < years; i++) {
		//Calculate yearly interest amount 
		interestAmount = (totalAmount) * (annualInterest / 100);

		//Update total amount by adding interest 
		totalAmount = totalAmount + interestAmount;

		//Display year-end data with correct formatting 
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}

	// Reinitialize totalAmount for next calculation with monthly deposits 
	totalAmount = initialInvestment;

	//Display results WITH monthly deposits 
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "-------------------------------------------------------------" << endl;
	cout << "Year         Year End Balance       Year End Earned Interest " << endl;
	cout << "-------------------------------------------------------------" << endl;

	//Calculate yearly interest and year end total with monthly deposits 
	for (int i = 0; i < years; i++) {
		//Initialize yearly total interest for this year 
		yearlyTotalInterest = 0;

		//Loop through each month of the year 
		for (int j = 0; j < 12; j++) {
			//Calculate monthly interest for the current month 
			interestAmount = ((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12;

			//Add monthly interest to yearly total interest 
			yearlyTotalInterest = yearlyTotalInterest + interestAmount;

			//Update totalAmount with monthly deposit and interest 
			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}

		//Display year end data with monthly deposits 
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearlyTotalInterest << endl;
	}

	return 0;
}