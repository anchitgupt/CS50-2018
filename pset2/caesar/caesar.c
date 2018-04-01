#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>


 int main(int argc, string argv[])
 {

    int key=atoi(argv[1]);
    if (argc != 2)
    {
        printf("Nope\n");
        return 1;
    }

    if (key < 0)
    {
        printf("Nope\n");
        return 1;
    }
    else
    {

        string code = get_string("plaintext: ");
        printf("\nciphertext: ");
        for (int i = 0, n=strlen(code); i<n;i++)
            {
                if islower(code[i])
                    printf("%c", (((code[i] + key) - 97) % 26) + 97);
                else if isupper(code[i])
                    printf("%c", (((code[i] + key) - 65) % 26) + 65);
                else
                    printf("%c", code[i]);
            }
            printf("\n");
            return 0;
    }
 }