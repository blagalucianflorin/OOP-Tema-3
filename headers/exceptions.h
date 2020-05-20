//
// Created by lblaga on 20.05.2020.
//

#ifndef OOP_TEMA_3_2_0_EXCEPTIONS_H
#define OOP_TEMA_3_2_0_EXCEPTIONS_H

#include <exception>
#include <string>

class account_exception : std::exception
{
protected:
    std::string message;

public:
    account_exception () = default;

    const char *what() const noexcept (true) override;
};

class id_not_found : public account_exception
{
public:
    id_not_found (unsigned long id);
};

class negative_deposit_amount : public account_exception
{
public:
    negative_deposit_amount (double amount);
};

class negative_withdrawal_amount : public account_exception
{
public:
    negative_withdrawal_amount (double amount);
};

class balance_too_low : public account_exception
{
public:
    balance_too_low (double balance, double amount);
};

class negative_deposits : public account_exception
{
public:
    negative_deposits (int deposits);
};

class negative_withdrawals: public account_exception
{
public:
    negative_withdrawals (int withdrawals);
};

class negative_tax : public account_exception
{
public:
    negative_tax (float tax);
};

class early_balance_update : public account_exception
{
public:
    early_balance_update ();
};

class wrong_account_type : public account_exception
{
public:
    wrong_account_type ();
};

#endif //OOP_TEMA_3_2_0_EXCEPTIONS_H
