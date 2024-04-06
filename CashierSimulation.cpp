//File: Proyect1.cpp
//Name: Leonardo Cruz
//Date: 10/21/2023
//Description: This program is a Cashier which will print a summary of three items the customer will ask for. 
// Usage: The customer will give inputs and the program will print the result of some basic calculations.  

#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <math.h>
using namespace std;

int main() {
	
	// 1st Item Data
	string itemName1;
	cout << "What item do you want?" << endl;
	getline (cin,itemName1);
	
	int unitPrice1;
	cout << "How much is the " << itemName1 << "?" << endl;
	cin >> unitPrice1;
	
	int itemQuantity1;
	cout << "How many do you need?" << endl;
	cin >> itemQuantity1;
	
	cin.ignore(10000, '\n'); // This clears the buffer.

	// 2nd Item Data
	string itemName2;
	cout << "What item do you want?" << endl;
	getline(cin, itemName2);
	
	int unitPrice2;
	cout << "How much is the " << itemName2 << "?" << endl;
	cin >> unitPrice2;
	
	int itemQuantity2;
	cout << "How many do you need?" << endl;
	cin >> itemQuantity2;
	
	cin.ignore(10000, '\n'); // This clears the buffer specifically, cleans the line we just write and the enter we did press.

	// 3rd Item Data
	string itemName3;
	cout << "What item do you want?" << endl;
	getline(cin, itemName3);
	
	int unitPrice3;
	cout << "How much is the " << itemName3 << "?" << endl;
	cin >> unitPrice3;
	
	int itemQuantity3;
	cout << "How many do you need?" << endl;
	cin >> itemQuantity3;
	cin.ignore(10000, '\n'); // This clears the buffer specifically, cleans the line we just write and the enter we did press.

	// Tax Rate Prompt
	double taxRate;
	cout << "What is the Tax Rate?" << endl;
	cin >> taxRate;

	system("CLS"); // This just clean the console to start  printing the Summary.

	// Printing the Summary 
	
	

	cout << "----- Panther Express cashier's program -----" << endl;
	cout << "Unit name: " << itemName1 << endl;
	cout << "Unit price for " << itemName1 << ": " << unitPrice1 << endl;
	cout << "Unit quantity for " << itemName1 << ": " << itemQuantity1 << endl << endl;

	cout << "Unit name: " << itemName2 << endl;
	cout << "Unit price for " << itemName2 << ": " << unitPrice2 << endl;
	cout << "Unit quantity for " << itemName2 << ": " << itemQuantity2 << endl << endl;

	cout << "Unit name: " << itemName3 << endl;
	cout << "Unit price for " << itemName3 << ": " << unitPrice3 << endl;
	cout << "Unit quantity for " << itemName3 << ": " << itemQuantity3 << endl << endl;

	cout << "Tax rate (in whole numbers): " << taxRate << endl << endl;

	int cwidth = 15; // Set a general column width of 15 characters

	cout << "$----- cost summary -----$" << endl;
	cout << left << setw(cwidth) << "Item"; 
	cout << left << setw(cwidth+10) << "Price"; 
	cout << left << setw(cwidth-5) << "Quantity"; 
	cout << left << setw(cwidth) << "Cost" << endl;
	cout << "--------------------------------------------------------------" << endl;

	int cost1 = unitPrice1 * itemQuantity1;
	int cost2 = unitPrice2 * itemQuantity2;
	int cost3 = unitPrice3 * itemQuantity3; // Calculates cost for each item PRE TAX to print it.
	

	cout << left << setw(cwidth) << itemName1;	cout << setw(1) << "$"; cout << left << setw(cwidth + 9) << unitPrice1;	cout << left << setw(cwidth - 5) << itemQuantity1;  cout << setw(1) << "$"; cout << left << setw(cwidth) << cost1 << endl;
	cout << left << setw(cwidth) << itemName2;	cout << setw(1) << "$";cout << left << setw(cwidth + 9) << unitPrice2;	cout << left << setw(cwidth - 5) << itemQuantity2;  cout << setw(1) << "$"; cout << left << setw(cwidth) << cost2 << endl;
	cout << left << setw(cwidth) << itemName3;	cout << setw(1) << "$";cout << left << setw(cwidth + 9) << unitPrice3;	cout << left << setw(cwidth - 5) << itemQuantity3;  cout << setw(1) << "$"; cout << left << setw(cwidth) << cost3 << endl << endl;

	cout << "$----- cost pretax -----$" << endl;
	double totalCostPreTax = double(cost1 + 0.0) + double(cost2 + 0.0) + double(cost3 + 0.0); // Calculates cost total PRE TAX
	cout << totalCostPreTax << endl << endl;
	

	cout << "$----- cost w/ tax -----$" << endl;\
	taxRate = taxRate / 100.0; // As the customer did input the tax rate in a percentage value, we have to convert it.
	double totalCost = totalCostPreTax + (taxRate * totalCostPreTax) + 0.0; // Calculates cost total POST TAX
	cout << totalCost << endl << endl;

	cout << "--------------------------------------------------------------" << endl;

	double customerMoney;
	cout << "How much money do you have?" << endl;
	cin >> customerMoney;
	
	cout << endl << endl;

	cout << "$--------- Change --------$" << endl;
	double change = customerMoney - totalCost;
	cout << change << endl;
	cout << "--------------------------------------------------------------" << endl << endl;

	double backup_change = change; // Saves to double change value to another variable to be able to calculate the denominations of the decimal part of the number

	cout << "Denominations ..." << endl;
	int bills100 = change / 100; 
	change = change - (bills100*100); // Reduce the number of change to can calculate the next lower bills.
	cout << setw(cwidth) << left << "$100 bills:" << bills100 << endl;

	int bills20 = change / 20;
	change = change - (bills20*20);
	cout << setw(cwidth) << left << "$20 bills:" << bills20 << endl;

	int bills10 = change / 10;
	change = change - (bills10*10);
	cout << setw(cwidth) << left << "$10 bills:" << bills10 << endl;

	int bills5 = change / 5;
	change = change - (bills5*5);
	cout << setw(cwidth) << left << "$5 bills:" << bills5 << endl;
	
	int bills1 = change / 1;
	change = change - (bills1 * 1); 
	cout << setw(cwidth) << left << "$1 bills:" << bills1 << endl;

	double decimalPartOfChange = backup_change - ((bills100*100) + (bills20*20) + (bills10*10) + (bills5*5) + (bills1*1)); // Calculates the decimal part of change using the backup we did.
	
	

	decimalPartOfChange = decimalPartOfChange * 100.00; // Runs to the right the coma of the number two spaces. // 40
	
	int quarters = decimalPartOfChange / 25;	
	cout << setw(cwidth) << left << "Quarters:" << quarters << endl; 
	decimalPartOfChange = decimalPartOfChange - (quarters*25);// Reduce the number of the decimalPartOfChange to can calculate the next lower coins.
	

	int dimes = decimalPartOfChange / 10;
	cout << setw(cwidth) << left << "Dimes:" << dimes << endl;
	decimalPartOfChange = decimalPartOfChange - (dimes*10);
	

	int nickels = int(decimalPartOfChange) / 5;
	cout << setw(cwidth) << left << "Nickels:" << nickels << endl;
	decimalPartOfChange = decimalPartOfChange - (nickels*5);

	int pennies = decimalPartOfChange / 1;
	cout << setw(cwidth) << left << "Pennies:" << pennies << endl;
	decimalPartOfChange = decimalPartOfChange - (pennies*1);

	


	return 0;

}