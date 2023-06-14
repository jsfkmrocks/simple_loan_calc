//Jordan Brown - Loan Amoritization

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

//Function to find the monthly payment
double findPayment(double value, int months, double APR)
    {
        //define variables
        double factor, payment, m_rate;
        
        //calculate monthly rate
        m_rate=(APR/100)/12;
        
        //calculate factor
        factor=pow((1+m_rate),months);
        
        //calculate payment
        payment=(factor*value*m_rate)/(factor-1);
        
        //return statement
        return payment;
    }

int main()
{
    //Initialize Variables
    double value, APR, payment, total, m_rate;
    int months;
    
    //Gather Inputs
    cout << "\nPlease enter the initial loan value: $";
    cin >> value;
    cout << "Please enter the number of months of the loan: ";
    cin >> months;
    cout << "Please enter the APR (in percent): ";
    cin >> APR;
    
    //Call Function and find monthly payment
	cout << setprecision(2) << fixed;
	m_rate=(APR/100)/12; 
    total=findPayment(value, months, APR);
    cout << "\nWith initial loan value of: $" << value << endl;
    cout << "paid over " << months << " months" << endl;
    cout << "and an APR of: %" << APR << endl;
    cout << "\nYour monthly payment is: $" << total << "\n" << endl;

	
//Table

	//Setup
	const char seperator = ' ';
	const int Width = 20;


	//Build
	cout << left << setw(Width) << setfill(seperator) << "Month";
	cout << left << setw(Width) << setfill(seperator) << "Starting Balance";
	cout << left << setw(Width) << setfill(seperator) << "Interest";
	cout << left << setw(Width) << setfill(seperator) << "Payment";
	cout << left << setw(Width) << setfill(seperator) << "New Balance" << endl;

	for (int i = 1; i <= months; i++)
	{
		cout << left << setw(Width) << setfill(seperator) << i;
		cout << left << setw(Width) << setfill(seperator) << value;
		//Find interest
		double interest = m_rate * value;
		cout << left << setw(Width) << setfill(seperator) << interest;
		cout << left << setw(Width) << setfill(seperator) << total;
		//Take out paymnet add in interest
		value = (value - total + interest);
		cout << left << setw(Width) << setfill(seperator) << value << endl;
		
	}
}
