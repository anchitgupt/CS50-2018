#include <stdio.h>
#include <cs50.h>
#include<string.h>
#include<ctype.h>

// CIPHERTEXT = (PLAINTEXT + KEY) % 26

int main(int argc, string argv[])
{
    // checks for exaclty 2 number of arguments
    if(argc != 2)
    {
        printf("\nUsage: %s", argv[0]);
        return 1;
    }
    else
    // this checks for whether user had entered valid alphabet or not
    {
         for (int i = 0, n = strlen(argv[1]); i < n; i++)
        {
            if (!isalpha(argv[1][i]))
            {
                printf("Key must be alphabetic chars only.");

                return 1;
            }
        }
    }
    // key variable contains KEY
    string key = argv[1];
    // plain contains the PLain text
    string plain = get_string("Plaintext: ");

    // stores length of the PLaintext
    int len_p = strlen(plain);
    // stores length of the key
    int len_k = strlen(key);
    // variable to iterate the key
    int j =0;
    // loop through the plainetxt
    for(int i=0;i<len_p;i++)
    {
         if(isalpha(plain[i]))
         {
             if(isupper(plain[i]))
             {
                 if(isupper(key[j]))
                 {
                    // get the new Alphabet in 65 to 90
                    plain[i] = plain[i] +  key[j] -'A' ;
                    // increment to next location of key
                    j = (j+1)%len_k;
                    // if value becomes greater than 90
                    if(plain[i] > 90)
                    plain[i] = 64 + plain[i] -90;
                 }
                 else
                 {
                    // get the new Alphabet in 65 to 90
                    plain[i] = plain[i] +  key[j] -'a' ;
                    // increment to next location of key
                    j = (j+1)%len_k;
                    // if value becomes greater than 90
                    if(plain[i]>90)
                    plain[i] = 64 + plain[i] -90;
                 }
         }
         else
         {
                if(isupper(key[j]))
                {
                    // get the new Alphabet in 97 to 122
                  plain[i] =  'a' + (plain[i] -'a' + key[j] - 'A')%26;
                  // increment to next location of key
                  j = (j+1)%len_k;
                  // if value becomes greater than 122
                  if(plain[i]>122)
                  plain[i] = 96 + plain[i] -122;
                }
                else
                {
                plain[i] =  'a' + (plain[i] -'a' + key[j] - 'a')%26;
                  j=(j+1)%len_k;
                  if(plain[i]>122)
                  plain[i] = 96 + plain[i] -122;
                }
         }
        }
    }
    printf("ciphertext: %s\n", plain);
}