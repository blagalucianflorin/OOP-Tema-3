//
// Created by lblaga on 20.05.2020.
//

#ifndef OOP_TEMA_3_2_0_CURRENT_ACCOUNT_H
#define OOP_TEMA_3_2_0_CURRENT_ACCOUNT_H

#include "account.h"

#include <utility>
#include <iostream>

class Current_account : public Account
{
private:
    int deposits = -1;

    int withdrawals = -1;

    float tax = 0.0;

public:
    Current_account (std::string owner_name);

    Current_account (std::string owner_name, int deposits, int withdrawals, float tax);

    ~Current_account () = default;

    Current_account &operator= (const Current_account &old_acc);

    friend std::istream &operator>> (std::istream &in, Current_account &my_acc);

    int get_deposits () const;

    int get_withdrawals () const;

    float get_tax () const;

    void deposit (double amount);

    void withdraw (double amount);

    void display () override;
};

#endif //OOP_TEMA_3_2_0_CURRENT_ACCOUNT_H
