//pyramid
#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int size;
    do
    {
    // get the size of the pyramid
    size = get_int("Height: ");
    }
    // conditions to restric input
    while(size>23 || size<0);

    for(int i=1;i<=size;i++)
    {
        // print spaces
        for(int j=1;j<=size-i;j++)
            printf(" ");
        // print #
        for(int k=1;k<=i;k++)
            printf("#");
        // print in between space of half pyramids
        printf("  ");
        // print right half of the pyramid
        for(int j=1;j<=i;j++)
            printf("#");
        // print next line
        printf("\n");
    }
    // end for of i

}