#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>


int main(int argc, string argv[])
{
    // Check # of arguments
    if (argc != 2)
    {
        printf("k\n");
        return 1;
    }

    string k = argv[1];

    // Check if k is alpha
    for (int l = 0, n = strlen(k); l < n; l++)
    {
        if (!isalpha(k[l]))
        {
            printf("k\n");
            return 1;
        }
    }

    string plain = get_string("plaintext: ");
    int j, shift, l = 0;
    printf("ciphertext: ");

    // Encrypt plain text with k
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        if (islower(plain[i]))
        {
            j = (l % strlen(k));
            shift = tolower(k[j]) - 'a';
            printf("%c", (((plain[i] + shift) - 'a') % 26) + 'a');
            l++;
        }
        else if (isupper(plain[i]))
        {
            j = (l % strlen(k));
            shift = tolower(k[j]) - 'a';
            printf("%c", (((plain[i] + shift) - 'A') % 26) + 'A');
            l++;
        }
        else
        {
            printf("%c", plain[i]);
        }

    }

    printf("\n");
    return 0;
}
