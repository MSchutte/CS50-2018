#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("You did not enter a key!\n");
        return 1;
    }

    int shift = atoi(argv[1]);
    string text = get_string("plaintext: ");
    char ciphertext[strlen(text)];

    if (shift > 26)
    {
        shift = shift % 26;
    }

    for (int i = 0, n = strlen(text); i < n; i++)
    {
        // Convert lower letters
        if (islower(text[i]))
        {
            ciphertext[i] = (((text[i] + shift) - 'a') % 26) + 'a';
        }
        // convert capital letters
        else if (isupper(text[i]))
        {
            ciphertext[i] = (((text[i] + shift) - 'A') % 26) + 'A';
        }
        // pass non-letters through
        else
        {
            ciphertext[i] = text[i];
        }
    }

    printf("ciphertext: %s\n", ciphertext);
    return 0;
}
