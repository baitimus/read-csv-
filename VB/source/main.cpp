#pragma once 

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include "structs.h"




std::string csvFile = "C:/Users/uozuio/source/repos/VB/VB/source/20240818_1430_Kontoauszug.csv";
vector<Expense> readcsv() {
    vector<Expense> expenses; // creating array of structs 
    ifstream transactions;

    transactions.open(csvFile);// openning file

    if (transactions.fail())
    {
        std::cout << "unable to open file: " << csvFile << endl;

    } //errorhandling 
    else
    {
        std::cout << "file opend" << endl;

    }
    
    string line;
    getline(transactions, line);// skipping first line since it is just describing what is waht lol;
    //std::cout << line << std::endl;
    
    while (getline(transactions, line)) {
        stringstream ss(line);
        Expense expense;
        string belastungStr, gutschriftStr, saldoStr;

        // Extract each field using the ';' delimiter
        getline(ss, expense.buchung, ';');
        getline(ss, expense.valuta, ';');
        getline(ss, expense.buchungstext, ';');
        getline(ss, belastungStr, ';');
        getline(ss, gutschriftStr, ';');
        getline(ss, saldoStr, ';');

        // Convert the string fields to double, handle empty strings
        expense.belastung = belastungStr.empty() ? 0.0 : stod(belastungStr);
        expense.gutschrift = gutschriftStr.empty() ? 0.0 : stod(gutschriftStr);
        expense.saldo = stod(saldoStr);

        // Add the expense to the vector
        expenses.push_back(expense);
    }

    transactions.close();
    return expenses;
}



int main()  
{
    vector<Expense> expenses = readcsv(); // delcaring vector fuction
   

   
    for (const auto& expense : expenses) {
        cout << "Buchung: " << expense.buchung << ", "
            << "Valuta: " << expense.valuta << ", "
            << "Buchungstext: " << expense.buchungstext << ", "
            << "Belastung: " << expense.belastung << ", "
            << "Gutschrift: " << expense.gutschrift << ", "
            << "Saldo: " << expense.saldo << endl;
    } // print checking if work 
    size_t numberOfExpenses = expenses.size();
    cout << "Number of transactions: " << numberOfExpenses << endl;
    return 0;
}
    
    
