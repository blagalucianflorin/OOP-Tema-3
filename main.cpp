#include <iostream>
#include <zconf.h>

#include "headers/bank.h"

int main ()
{
    Bank my_bank ("BCR");

    Bank my_bank2 ("Transilvania");

    Savings_account *save_acc1;
    Current_account *curr_acc1;

    my_bank . add_account ("Blaga Lucian-Florin", 15, 15, 0.01);

    my_bank . add_account ("Ciocea Mihaela-Diana", 0.05, Savings_account::FULL);

    my_bank2 = my_bank;

    save_acc1 = dynamic_cast <Savings_account*> (&(my_bank . get_account (1)));

    curr_acc1 = dynamic_cast <Current_account*> (&(my_bank . get_account (0)));

    save_acc1 -> update_balance ();

    curr_acc1 -> deposit (999);

    my_bank . display ();

    my_bank2 . display ();
}

