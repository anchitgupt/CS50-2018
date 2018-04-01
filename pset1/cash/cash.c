#include <stdio.h>
#include <cs50.h>
#include<ctype.h>

int main(void)
{

 int amount;

 do
 {
 // Input Of amount
 amount =(int)(get_float("Change owed: ") * 100);

 } while( isdigit(amount) || amount < 0);

 // variable that store the number of coins
 int coin = 0;
 //logic to calculate the amount
 while(amount)
 {
  // If the amount is amount is greater that 25
 if(amount>=25)
 {
     amount=amount-25;
     coin++;
 }
 // If the amount is amount is greater that 10
 else if(amount>=10)
 {
      amount=amount-10;
      coin++;
 }
 // If the amount is amount is greater that 5
 else if(amount>=5)
 {
      amount=amount-5;
      coin++;
 }
 else  // If the amount is amount is less than 5
 {
     amount=amount-1;
     coin++;
 }
 }
 // Output:
 printf("\n%i\n",coin);
}