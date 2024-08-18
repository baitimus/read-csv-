#pragma once


#include <fstream>
#include <iostream>

using namespace std;

struct Expense {
    std::string buchung;         // Transaction date
    std::string valuta;          // Value date
    std::string buchungstext;    // Transaction description
    double belastung;            // Debit amount (0 if not applicable)
    double gutschrift;           // Credit amount (0 if not applicable)
    double saldo;                // Account balance after the transaction
};
