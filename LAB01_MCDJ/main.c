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
int main(void) {
    double price, tendered, changeDue;
    int changeItems, changeRounded;
    int change[8] = {0,0,0,0,0,0,0,0};
    
    printf("Please enter price of item to the nearest whole cent. Note: any numbers entered after the hundreths place will be truncated: \n");
    scanf("%lf", &price);
    price = floorl(price*100)/100;
    printf("Amount entered was: %.2f \n", price);
    
    printf("Please enter amount tendered to the nearest whole cent. Note: any numbers entered after the hundreths place will be truncated: \n");
    scanf("%lf", &tendered);
    tendered = floorl(tendered*100)/100;
    printf("Amount entered was: %.2f \n", tendered);
    
    changeDue = roundl((tendered-price)*10)/10;
    changeRounded = changeDue;
    printf("%lf", changeDue);
    
    /*if (changeDue >= 0){
        printf("Change is: %.2lf \n", changeDue);
    }
    else{
        changeDue = changeDue * -1;
        printf("Tendered amount was less than the price of the item. Please pay: %.2lf \n", changeDue);
        return (EXIT_SUCCESS);
    }
    
    for (int coin; coin < 8; coin++){
        
    }*/
    
    return (EXIT_SUCCESS);
}

