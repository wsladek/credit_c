#include <stdio.h>
#include <cs50.h>
#include <math.h>


int main(void)
{
    //Get user input, introduce variables for counting digits and doing the maths
    long card = get_long_long("Credit Card Number: ");
    long countme = card;
    long digitize = card;
    int count = 0;
    int total = 0;

    //Count digits
    while (countme != 0)
    {
        countme = countme/10;
        count++;
    }

    //Store digits in array
    int canoncount = count;
    int digits [count];
    while (count > 0)
    {
        digits [count-1] = digitize % 10;
        digitize /= 10;
        count = count - 1;
    }

    //Reset count so I can use it again
    count = canoncount;

    //Step 1: Multiply every other digit by 2, starting with the number’s second-to-last digit,
    //then add those products' digits together
    int steponepositions = count/2;
    int stepone [steponepositions];

    while (count > 1)
    {
        stepone [steponepositions-1] = 2*(digits [count-2]);
        count = count - 2;
        steponepositions = steponepositions-1;
    }

    count = canoncount;
    steponepositions = count/2;

    while (steponepositions > 0)
    {
        if (stepone [steponepositions - 1] > 9)
        {
            total = total + (stepone [steponepositions-1] % 10) + (stepone [steponepositions-1] / 10);
        }

        else
        {
            total = total + stepone [steponepositions - 1];
        }

        steponepositions = steponepositions - 1;
    }

    //Step 2: Add the sum to the sum of the digits that weren’t multiplied by 2.
    while (count > 0)
    {
        total = total + digits [count - 1];
        count = count - 2;
    }

    //Step 3: If the total’s last digit is 0 (or, put more formally,
    //if the total modulo 10 is congruent to 0), the number is valid!
    int validcheck = total % 10;
    int firsttwo = digits[0]*10+digits[1];

    //Step 4: Last line of output should be AMEX\n or MASTERCARD\n or VISA\n or INVALID\n
    //American Express numbers start 34 or 37; MasterCard start 51, 52, 53, 54, or 55; and Visa start with 4
    //American Express uses 15-digit numbers, MasterCard uses 16-digit numbers, and Visa uses 13- and 16-digit numbers
    if (validcheck == 0)
    {
        if ((digits [0] == 4) && (canoncount == 13 || canoncount == 16))
        {
            printf("VISA\n");
        }

        else if ((firsttwo == 34 || firsttwo == 37) && canoncount == 15)
        {
            printf("AMEX\n");
        }

        else if ((firsttwo == 51 || firsttwo == 52 || firsttwo == 53 || firsttwo == 54 || firsttwo == 55) && canoncount == 16)
        {
            printf("MASTERCARD\n");
        }

        else
        {
            printf("INVALID\n");
        }
    }


    else
    {
        printf("INVALID\n");
    }
}
