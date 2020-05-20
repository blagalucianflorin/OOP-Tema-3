//
// Created by lblaga on 20.05.2020.
//

#include "../headers/account_handler.h"

template <class acc>
Account_handler <acc>::Account_handler () = default;

template <class acc>
Account_handler<acc> &Account_handler <acc>::operator= (const Account_handler &old_hand)
{
    this -> accounts = old_hand . get_accounts ();

    return (*this);
}

template <class acc>
std::unordered_map <unsigned long, acc> Account_handler <acc>::get_accounts () const
{
    return (this -> accounts);
}

template <class acc>
void Account_handler <acc>::display ()
{
    for (auto curr_account : this -> get_accounts ())
        curr_account . second . display ();
}

template <>
void Account_handler <Current_account>::add_account (std::string owner_name, int deposits, int withdrawals, float tax)
{
    auto new_acc = new Current_account (std::move (owner_name), deposits, withdrawals, tax);

    new_acc -> set_id (current_id);

    this -> accounts . insert (std::make_pair(current_id++, *new_acc));
}

template <>
void Account_handler <Savings_account>::add_account (std::string owner_name, float interest_rate,
                                         Savings_account::year_interval interest_interval)
{
    auto new_acc = new Savings_account (std::move (owner_name), interest_rate, interest_interval);

    new_acc -> set_id (current_id);

    this -> accounts . insert (std::make_pair(current_id++, *new_acc));
}

template <class acc>
void Account_handler <acc>::add_account (Account &my_acc)
{
    acc *new_acc;

    new_acc = dynamic_cast<acc*> (&my_acc);
    if (new_acc == nullptr)
        std::cout << "failed conversion\n";
    else
    {
        new_acc -> set_id (current_id);
        this -> accounts . insert (std::make_pair (current_id++, *new_acc));
    }
}

template <class acc>
std::unordered_map <unsigned long, acc> &Account_handler <acc>::get_accounts ()
{
    return (this -> accounts);
}

template <class acc>
acc &Account_handler <acc>::get_account (unsigned long id)
{
    if (this -> get_accounts () . count (id) != 0)
        return ((this -> get_accounts () . find (id) -> second));
    throw (id_not_found(id));
}

template <>
void Account_handler <Savings_account>::display_full_year_save_accounts ()
{
    for (auto curr_acc : this -> get_accounts ())
        if (curr_acc . second . get_interest_interval() == Savings_account::FULL)
            curr_acc . second . display();
}

template class Account_handler<Savings_account>;
template class Account_handler<Current_account>;
