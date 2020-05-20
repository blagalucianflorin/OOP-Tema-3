//
// Created by lblaga on 20.05.2020.
//

#include "../headers/exceptions.h"

const char *account_exception::what () const noexcept (true)
{
    return this -> message . c_str();
}

id_not_found::id_not_found (unsigned long id)
{
    this -> message = "Account_exception: ID not found. (";
    this -> message += std::to_string(id) + ")";
}

negative_deposit_amount::negative_deposit_amount (double amount)
{
    this -> message = "Account_exception: Tried to deposit a negative amount. (";
    this -> message += std::to_string (amount) + ")";
}

negative_withdrawal_amount::negative_withdrawal_amount (double amount)
{
    this -> message = "Account_exception: Tried to withdraw a negative amount. (";
    this -> message += std::to_string (amount) + ")";
}

balance_too_low::balance_too_low (double balance, double amount)
{
    this -> message = "Account_exception: Tried to withdraw an amount larger than the balance. (";
    this -> message += std::to_string (balance) + " - " + std::to_string (amount) + ")";
}

negative_deposits::negative_deposits (int deposits)
{
    this -> message = "Account_exception: Cannot set a negative amount of deposits. (";
    this -> message += std::to_string (deposits) + ")";
}

negative_withdrawals::negative_withdrawals (int withdrawals)
{
    this -> message = "Account_exception: Cannot set a negative amount of withdrawals. (";
    this -> message += std::to_string (withdrawals) + ")";
}

negative_tax::negative_tax (float tax)
{
    this -> message = "Account_exception: Cannot set a negative tax. (";
    this -> message += std::to_string (tax) + ")";
}

early_balance_update::early_balance_update ()
{
    this -> message = "Account_exception: Tried to update the balance of a savings account too soon.";
}

wrong_account_type::wrong_account_type ()
{
    this -> message = "Account_exception: Wrong Account type.";
}
