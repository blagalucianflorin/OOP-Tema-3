//
// Created by lblaga on 20.05.2020.
//

#include "../headers/savings_account.h"

Savings_account::Savings_account (std::string owner_name, float interest_rate, year_interval interest_interval)
                                  : Account (std::move (owner_name))
{
    this -> interest_rate = interest_rate;
    this -> interest_interval = interest_interval;
}

Savings_account &Savings_account::operator= (const Savings_account &old_acc)
{
    if (this != &old_acc)
    {
        this -> change_balance (-(this -> get_balance ()) + old_acc . get_balance ());
        this -> interest_interval = old_acc . get_interest_interval ();
        this -> interest_rate = old_acc . get_interest_rate ();
        this -> balance_updates = old_acc . get_balance_updates ();
    }

    return (*this);
}

std::istream &operator>> (std::istream &in, Savings_account &my_acc)
{
    std::string aux;

    in >> my_acc;
    in >> my_acc . interest_rate;
    in >> aux;
    if (aux == "QUARTER")
        my_acc . interest_interval = Savings_account::QUARTER;
    else if (aux == "HALF")
        my_acc . interest_interval = Savings_account::HALF;
    else if (aux == "FULL")
        my_acc . interest_interval = Savings_account::FULL;

    return (in);
}

double Savings_account::update_balance ()
{
    double added_amount;
//    double full_year = 3600 * 24 * 365;

    int full_year = 4; // debug

    switch (this -> get_interest_interval ())
    {
        case QUARTER:
            full_year /= 4;
            break;
        case HALF:
            full_year /= 2;
            break;
        case FULL:
            full_year /= 1;
            break;
    }

    if (time (nullptr) - this -> get_last_update () . first < full_year)
        throw (early_balance_update ());

    added_amount = calc_balance_change (this -> get_balance (), this -> get_interest_rate ());

    this -> balance_updates . emplace_back(time (nullptr), added_amount);

    return (change_balance (added_amount));
}

float Savings_account::get_interest_rate () const
{
    return (this -> interest_rate);
}

Savings_account::year_interval Savings_account::get_interest_interval () const
{
    return (this -> interest_interval);
}

std::list <std::pair <time_t, double>> Savings_account::get_balance_updates () const
{
    return (this -> balance_updates);
}

std::pair <time_t, double> Savings_account::get_last_update () const
{
    return (this -> get_balance_updates () .back ());
}

void Savings_account::display()
{
    time_t created_raw;
    struct tm * created_info;

    std::cout << "[Savings Account Display Start]\n";

    std::cout << "\tAccount ID: " << this -> get_id () << "\n";

    std::cout << "\tOwner: " << this -> get_owner_name () << "\n";

    std::cout << "\tBalance: " << this -> get_balance () << "\n";

    std::cout << "\tDate Created: ";
    created_raw = this -> get_created ();
    time (&created_raw);
    created_info = localtime (&created_raw);
    std::cout << asctime (created_info);

    if (!this -> get_balance_updates ().empty())
    {
        std::string correct_date;
        created_raw = this -> get_last_update () . first;
        time (&created_raw);
        created_info = localtime (&created_raw);
        std::cout << "\tLast Update: ";
        correct_date = asctime (created_info);
        correct_date.pop_back();
        std::cout << correct_date;
        std::cout << "\t(Amount: " << this -> get_last_update () . second << ")\n";
    }
    else
        std::cout << "\tLast Update: N/A\n";

    std::cout << "\tInterest Rate: " << this -> get_interest_rate () << "\n";

    std::cout << "\tInterest Interval: ";

    switch (this -> get_interest_interval ())
    {
        case QUARTER:
            std::cout << "3 Months\n";
            break;
        case HALF:
            std::cout << "6 Months\n";
            break;
        case FULL:
            std::cout << "12 Months\n";
            break;
    }

    if (!this -> get_balance_updates () . empty())
    {
        std::cout << "\tBalance Updates:\n";
        for (auto curr_update : this -> get_balance_updates ())
        {
            std::string correct_date;
            created_raw = curr_update . first;
            time (&created_raw);
            created_info = localtime (&created_raw);
            std::cout << "\t\t";
            correct_date = asctime (created_info);
            correct_date.pop_back();
            std::cout << correct_date;
            std::cout << "\t(Amount: " << curr_update . second << ")\n";

        }
    }

    std::cout << "[Savings Account Display End]\n";
}

