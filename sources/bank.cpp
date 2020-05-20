//
// Created by lblaga on 20.05.2020.
//

#include "../headers/bank.h"

#include <utility>


Bank::Bank (std::string bank_name)
{
    this -> bank_name = std::move(bank_name);
}

std::string Bank::get_bank_name () const
{
    return (this -> bank_name);
}

void Bank::set_bank_name (const std::string &new_bank_name)
{
    this -> bank_name = new_bank_name;
}

Account &Bank::get_account (unsigned long id)
{
    if (this -> savings_accounts . get_accounts () . count (id) != 0)
        return this -> savings_accounts . get_account (id);
    if (this -> current_accounts . get_accounts () . count (id) != 0)
        return this -> current_accounts . get_account (id);
    throw (id_not_found (id));
}

void Bank::display ()
{
    std::cout << "[Bank Display Start]\n";
    std::cout << "Bank Name: " << this -> get_bank_name () << "\n";
    std::cout << "Savings accounts:\n";
    this -> savings_accounts . display ();
    std::cout << "Current accounts:\n";
    this -> current_accounts . display ();
    std::cout << "[Bank Display End]\n\n";
}

void Bank::add_account (std::string owner_name, int deposits, int withdrawals, float tax)
{
    Current_account new_acc (std::move(owner_name), deposits, withdrawals, tax);

    new_acc . set_id (current_id++);
    this -> current_accounts . add_account (new_acc);
}

void Bank::add_account (std::string owner_name, float interest_rate, Savings_account::year_interval interest_interval)
{
    Savings_account new_acc (std::move(owner_name), interest_rate, interest_interval);

    new_acc . set_id (current_id++);
    this -> savings_accounts . add_account (new_acc);
}

void Bank::add_account (Account *my_acc)
{
    my_acc -> set_id (current_id++);
    if (typeid (*my_acc) == typeid (savings_accounts))
        this -> savings_accounts . add_account (*my_acc);
    if (typeid (*my_acc) == typeid (current_accounts))
        this -> current_accounts . add_account (*my_acc);
}

void Bank::display_full_year_save_accounts ()
{
    this -> savings_accounts . display_full_year_save_accounts ();
}

