//
// Created by lblaga on 20.05.2020.
//

#ifndef OOP_TEMA_3_2_0_BANK_H
#define OOP_TEMA_3_2_0_BANK_H

#include "account_handler.h"

#include <string>
#include <iostream>
#include <utility>

class Bank
{
private:
    std::string bank_name;

    Account_handler <Savings_account> savings_accounts;

    Account_handler <Current_account> current_accounts;

public:
    Bank (std::string bank_name);

    std::string get_bank_name () const;

    void set_bank_name (const std::string &new_bank_name);

    void add_account (std::string owner_name, int deposits, int withdrawals, float tax);

    void add_account (std::string owner_name, float interest_rate, Savings_account::year_interval interest_interval);

    void add_account (Account *my_acc);

    Account &get_account (unsigned long id);

    void display ();

    void display_full_year_save_accounts ();
};

#endif //OOP_TEMA_3_2_0_BANK_H
