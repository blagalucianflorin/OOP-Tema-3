//
// Created by lblaga on 20.05.2020.
//

#ifndef OOP_TEMA_3_2_0_ACCOUNT_HANDLER_H
#define OOP_TEMA_3_2_0_ACCOUNT_HANDLER_H

#include "savings_account.h"
#include "current_account.h"

#include <unordered_map>
#include <iostream>


static unsigned long current_id;

template <class acc>
class Account_handler
{
private:
    std::unordered_map <unsigned long, acc> accounts;

public:
    Account_handler ();

    ~Account_handler () = default;

    Account_handler &operator= (const Account_handler &old_hand);

    std::unordered_map <unsigned long, acc> get_accounts () const;

    void add_account (std::string owner_name, int deposits, int withdrawals, float tax);

    void add_account (std::string owner_name, float interest_rate, Savings_account::year_interval interest_interval);

    void add_account (Account &my_acc);

    std::unordered_map <unsigned long, acc> &get_accounts ();

    acc &get_account (unsigned long id);

    void display ();

    void display_full_year_save_accounts ();
};

#endif //OOP_TEMA_3_2_0_ACCOUNT_HANDLER_H
