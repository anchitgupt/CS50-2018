#include <stdio.h>
#include <cs50.h>
#include<math.h>
int numberOfDigits(long long n);
bool calculateChecksum(long long n);
bool valid(long long num);
int main(void){

 long long number;

    // Number Input
    do
    {
    printf("Enter the Credit card Number: \t");
    number  = get_long_long();
    }// valid checks the given Credit Card Number is valid or Not
    while( valid(number) && !calculateChecksum(number));




}
// calaculate the checksum for the given sequence
bool calculateChecksum(long long temp){
    // flag variable
    bool b = false;
    // sum_o is sum of numbers at odd places
    // sum_e is sum of numbers at even places
    int sum_o =0, sum_e=0;
    // loop through the number
    while(temp!=0)
    {
        int n1 = temp % 10;
        // for odd place digit number
        if(!b){
            sum_o+=n1;
            b = true;
        }
        // for even place digit number
        else
        {
            n1*=2;
            if((n1)>=10){
                sum_e=sum_e+(n1%10);
                n1/=10;
            }
            sum_e+=(n1%10);
            b = false;
        }
        temp/=10;
    }

    return ((sum_e +sum_o)%10 == 0);
}

// checks whether the number is VISA, AMEX or MASTERCRAD
bool valid(long long num)
{
    // num is number entered
    if(num<0 || num == 0)
    {
     printf("Retry: \n");
        return true;
    }
    // n contains Number Of Digits in Credit Card
    int n = numberOfDigits(num);

    if(n == 15 || n == 16 || n == 13)
    {
      while(num>99)
      {
         num/=10;
      }
      // condition for the AMEX
    if(n == 15)
    {
        if(num == 37){
            printf("AMEX\n");
            return false;
        }
    }
    else
    // condition for MASTERCARD
    if(n == 16 && (num == 51|| num ==52
        || num ==53|| num ==54|| num ==55))
        {
            printf("MASTERCARD\n");
            return false;
        }
    else
    // condition for VISA
    if( (n== 13 || n== 16 ) && num/10 == 4)
            {
                printf("VISA\n");
                return false;
             }
    else
    {
         printf("INVALID\n");
         return true;
    }
  }
  else
  {
     printf("INVALID\n");
        exit(0);
  }

    return true;
}

// function to calculate the number of digits of credit card
int numberOfDigits(long long n)
{
    if (n == 0)
        return 0;
    return floor( log10( llabs( n ) ) ) + 1;
}