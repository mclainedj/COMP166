/* 
 * Class: COMP 166
 * Lab: 01
 * Author: Mclaine De Jesus
 * Student Number: C0417594
 * 
 * Description: This program takes the price of an item and the amount given by the customer and calculates the change to be given back. 
 *
 * Created on January 12, 2022, 8:42 AM
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
 * 
 */
int main(void)
{

    //variable and array init
    
    double price, tendered, changeDue, changeRounded;
    int changeInt, changeMod, userInput;
    int change[8] = {0, 0, 0, 0, 0, 0, 0, 0}; //Array for coin denominations: $20, $10, $5, $2, $1, $0.25, $0.10, $0.05

    //main code

    userInput = 0;
    while (userInput != 1)
    { //While loop continues to run until user confirms their entry.
        printf("Please enter price of item to the nearest whole cent. Note: any numbers entered after the hundreths place will be truncated: \n");
        scanf("%lf", &price);
        price = floorl(price * 100) / 100; //Multiplies price entered to account for cents, then rounds down to the nearest integer before converting back into the proper currency format.
        printf("Amount entered was: %.2f \n If this is correct, enter 1 \n", price);
        scanf("%i", &userInput);
    }
    userInput = 0;
    while (userInput != 1)
    {
        printf("Please enter amount tendered to the nearest whole cent. Note: any numbers entered after the hundreths place will be truncated: \n");
        scanf("%lf", &tendered);
        tendered = floorl(tendered * 100) / 100;
        printf("Amount entered was: %.2f \n If this is correct, enter 1 \n", tendered);
        scanf("%i", &userInput);
    }
    changeDue = (tendered - price) * 100; //Converts to integer value
    changeMod = (int)changeDue % 10;      //Value for remainder to decide whether to round up, down or to 5.
    if (changeMod >= 3 && changeMod <= 7)
    { //If cent value ends in 3-7, will round to 5.
        changeRounded = floorl(changeDue / 10) / 10 + 0.05;
    }
    else
    { //Otherwise rounds to the nearest value of 10.
        changeRounded = roundl(changeDue / 10) / 10;
    }
    changeInt = changeRounded * 100; //Converts to integer value for use in coin calculations later.

    if (changeRounded >= 0)
    { //States user's change as long as it is a valid amount (over or equal to 1 cent)
        printf("Change is: $%.2lf \n", changeRounded);
    }
    else
    { //If not enough cash was tendered, prompts for payment.
        changeRounded = changeRounded * -1;
        printf("Tendered amount was less than the price of the item. Please pay: %.2lf \n", changeRounded);
        return (EXIT_SUCCESS);
    }
    /*
     *Following if statements all follow the same flow:
     *Check if current change is equal or higher than the coin denomination (ex. 2000 corresponds to $20)
     *If yes, places value of current change / coin value into the change array which tracks the type of currency.
     *Changes current change to new value by subtracting the amount of coins * the value of the coins from the current change.
     */
    if (changeInt >= 2000)
    {
        change[0] = changeInt / 2000;
        changeInt = changeInt - change[0] * 2000;
    }
    if (changeInt >= 1000)
    {
        change[1] = changeInt / 1000;
        changeInt = changeInt - change[1] * 1000;
    }
    if (changeInt >= 500)
    {
        change[2] = changeInt / 500;
        changeInt = changeInt - change[2] * 500;
    }
    if (changeInt >= 200)
    {
        change[3] = changeInt / 200;
        changeInt = changeInt - change[3] * 200;
    }
    if (changeRounded >= 100)
    {
        change[4] = changeInt / 100;
        changeInt = changeInt - change[4] * 100;
    }
    if (changeInt >= 25)
    {
        change[5] = changeInt / 25;
        changeInt = changeInt - change[5] * 25;
    }
    if (changeInt >= 10)
    {
        change[6] = changeInt / 10;
        changeInt = changeInt - change[6] * 10;
    }
    if (changeInt >= 5)
    {
        change[7] = changeInt / 5;
        changeInt = changeInt - change[7] * 5;
    }
    printf("Bills and Coins Received: %i $20 Bill(s), %i $10 Bill(s), %i $5 Bill(s), %i Toonie(s), %i, Loonie(s), %i Quarter(s), %i Dime(s), %i Nickel(s) \n ", change[0], change[1], change[2], change[3], change[4], change[5], change[6], change[7]);
    return (EXIT_SUCCESS);
}
