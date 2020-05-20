//
// Created by lblaga on 20.05.2020.
//

#include "../headers/account.h"

#include <utility>

Account::Account (std::string owner_name) : created (std::time (nullptr))
{
    this -> owner_name = std::move(owner_name);
}

Account::~Account () = default;

double Account::change_balance (double amount)
{
    this -> balance += amount;

    return (this -> balance);
}

double Account::get_balance () const
{
    return (this -> balance);
}

void Account::set_id (unsigned long new_id)
{
    this -> id = new_id;
}

unsigned long Account::get_id () const
{
    return (this -> id);
}

std::string Account::get_owner_name () const
{
    return (this -> owner_name);
}

time_t Account::get_created () const
{
    return (this -> created);
}

double Account::calc_balance_change (double curr_balance, double percentage)
{
    return (curr_balance * percentage);
}

std::istream &operator>> (std::istream &in, Account &my_acc)
{
    in >> my_acc . balance;
    in >> my_acc . owner_name;
    return (in);
}
