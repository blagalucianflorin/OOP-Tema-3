//
// Created by lblaga on 20.05.2020.
//

#ifndef OOP_TEMA_3_2_0_SAVINGS_ACCOUNT_H
#define OOP_TEMA_3_2_0_SAVINGS_ACCOUNT_H

#include "account.h"

#include <list>
#include <utility>
#include <iostream>


class Savings_account : public Account
{
public:
    typedef enum {QUARTER, HALF, FULL} year_interval;

    Savings_account (std::string owner_name, float interest_rate, year_interval interest_interval);

    ~Savings_account () = default;

    Savings_account &operator= (const Savings_account &old_acc);

    friend std::istream &operator>> (std::istream &in, Savings_account &my_acc);

    double update_balance ();

    float get_interest_rate () const;

    year_interval get_interest_interval () const;

    std::list <std::pair <time_t, double>> get_balance_updates () const;

    std::pair <time_t, double> get_last_update () const;

    void display () override;

private:
    float interest_rate;

    year_interval interest_interval;

    std::list <std::pair <time_t, double>> balance_updates;
};

#endif //OOP_TEMA_3_2_0_SAVINGS_ACCOUNT_H
