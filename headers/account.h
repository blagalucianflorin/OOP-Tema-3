//
// Created by lblaga on 20.05.2020.
//

#ifndef OOP_TEMA_3_2_0_ACCOUNT_H
#define OOP_TEMA_3_2_0_ACCOUNT_H

#include <string>
#include <ctime>
#include <iostream>
#include "exceptions.h"

class Account
{
private:
    unsigned long id = -1;

    std::string owner_name;

    const time_t created;

    double balance = 0;

public:
    Account (std::string owner_name);

    virtual ~Account () = 0;

    friend std::istream &operator>> (std::istream &in, Account &my_acc);

    double change_balance (double amount);

    double get_balance () const;

    void set_id (unsigned long new_id);

    unsigned long get_id () const;

    std::string get_owner_name () const;

    time_t get_created () const;

    static double calc_balance_change (double curr_balance, double percentage);

    virtual void display () = 0;
};

#endif //OOP_TEMA_3_2_0_ACCOUNT_H
