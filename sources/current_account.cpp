//
// Created by lblaga on 20.05.2020.
//

#include "../headers/current_account.h"

#include <utility>

Current_account::Current_account (std::string owner_name) : Account (std::move (owner_name))
{

}

Current_account::Current_account (std::string owner_name, int deposits, int withdrawals, float tax)
                                  : Account (std::move (owner_name))
{
    if (deposits < 0)
        throw (negative_deposits (deposits));
    if (withdrawals < 0)
        throw (negative_withdrawals (withdrawals));
    if (tax < 0)
        throw (negative_tax (tax));

    this -> withdrawals = withdrawals;
    this -> deposits = deposits;
    this -> tax = tax;
}

Current_account &Current_account::operator= (const Current_account &old_acc)
{
    if (this != &old_acc)
    {
        this -> change_balance (-(this -> get_balance ()) + old_acc . get_balance ());
        this -> deposits = old_acc . get_deposits ();
        this -> withdrawals = old_acc . get_withdrawals ();
        this -> tax = old_acc . get_tax ();
    }

    return (*this);
}

std::istream &operator>> (std::istream &in, Current_account &my_acc)
{
    in >> (*dynamic_cast<Account*> (&my_acc));
    in >> my_acc . deposits;
    in >> my_acc . withdrawals;
    in >> my_acc . tax;

    return (in);
}

int Current_account::get_deposits () const
{
    return (this -> deposits);
}

int Current_account::get_withdrawals () const
{
    return (this -> withdrawals);
}

float Current_account::get_tax () const
{
    return (this -> tax);
}

void Current_account::deposit (double amount)
{
    if (amount < 0)
        throw (negative_deposit_amount (amount));
    if (this -> get_deposits () != -1)
    {
        if (this -> get_deposits () == 0)
            amount = amount - calc_balance_change (amount, this -> get_tax ());
        else
            (this -> deposits)--;
    }
    this -> change_balance (amount);
}

void Current_account::withdraw (double amount)
{
    if (amount < 0)
        throw (negative_withdrawal_amount (amount));
    if (this -> get_withdrawals () != -1)
    {
        if (this -> get_withdrawals () == 0)
            amount = amount + calc_balance_change (amount, this -> get_tax ());
        else
            (this -> withdrawals)--;
    }
    if (amount > this -> get_balance())
        throw (balance_too_low (this -> get_balance (), amount));
    this -> change_balance (-amount);
}

void Current_account::display()
{
    time_t created_raw;
    struct tm * created_info;

    std::cout << "[Current Account Display Start]\n";

    std::cout << "\tAccount ID: " << this -> get_id () << "\n";

    std::cout << "\tOwner: " << this -> get_owner_name () << "\n";

    std::cout << "\tBalance: " << this -> get_balance () << "\n";

    std::cout << "\tDate Created: ";
    created_raw = this -> get_created ();
    time (&created_raw);
    created_info = localtime (&created_raw);
    std::cout << asctime (created_info);

    std::cout << "\tDeposits left: ";

    if (this -> get_deposits () == -1)
        std::cout << "Unlimited\n";
    else
        std::cout << this -> get_deposits () << "\n";

    std::cout << "\tWithdrawals left: ";

    if (this -> get_withdrawals () == -1)
        std::cout << "Unlimited\n";
    else
        std::cout << this -> get_withdrawals () << "\n";

    std::cout << "[Current Account Display End]\n";
}
