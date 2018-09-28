#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main (void)
{
    printf("'Cash' tells you how many coins it takes to make a given amount of change.\nGive it a try!\n");
    int coins = 0;

    //Get user entry & convert to integer
    float entry = get_float ("Change owed: $");
    float change = entry;
    change = 100*change;
    change = roundf(change*100)/100;
    int converted = change;

    //Subract Quarters, counting each one until there's not enough change for a Quarter
    while (converted >= 25)
    {
        converted = converted - 25;
        coins++;
    }

    //Subract Dimes, counting each one until there's not enough change for a Dime
    while (converted >= 10)
    {
        converted = converted - 10;
        coins++;
    }

    //Subract Nickels, counting each one until there's not enough change for a Nickel
    while (converted >= 5)
    {
        converted = converted - 5;
        coins++;
    }

    //Subract Pennies, counting each one until there's not enough change for a Penny
    while (converted > 0)
    {
        converted = converted - 1;
        coins++;
    }

    printf("It will take %i coins to make $%0.2f in change\n", coins, entry);
}