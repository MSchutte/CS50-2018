#include <stdio.h>
#include <cs50.h>
#include <unistd.h>
#include <crypt.h>
#include <string.h>
#define _XOPEN_SOURCE


// Cracking passwords
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./crack hash\n");
        return 1;
    }

    char *hash = argv[1];
    char key_array[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key_num = strlen(key_array);
    char salt_array[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789./";
    int salt_num = strlen(salt_array);
    char key[5] = {'\0'}, salt[2] = {'\0'};
    salt[0] = hash[0];
    salt[1] = hash[1];
    string crypt_hash;

    for (int a = 0; a < key_num; a++)
    {
        key[0] = key_array[a];
        key[1] = '\0';

        crypt_hash = crypt(key, salt);
        if (strcmp(crypt_hash, hash) == 0)
        {
            printf("%s\n", key);
            return 0;
        }

    }
    printf("Check1 done\n");

    for (int a = 0; a < key_num; a++)
    {
        for (int b = 0; b < key_num; b++)
        {
            key[0] = key_array[a];
            key[1] = key_array[b];
            key[2] = '\0';

            crypt_hash = crypt(key, salt);
            if (strcmp(crypt_hash, hash) == 0)
            {
                printf("%s\n", key);
                return 0;
            }
        }
    }
    printf("Check2 done\n");

    for (int a = 0; a < key_num; a++)
    {
        for (int b = 0; b < key_num; b++)
        {
            for (int c = 0; c < key_num; c++)
            {
                key[0] = key_array[a];
                key[1] = key_array[b];
                key[2] = key_array[c];
                key[3] = '\0';

                crypt_hash = crypt(key, salt);
                if (strcmp(crypt_hash, hash) == 0)
                {
                    printf("%s\n", key);
                    return 0;
                }
            }
        }
    }
    printf("Check3 done\n");

    for (int a = 0; a < key_num; a++)
    {
        for (int b = 0; b < key_num; b++)
        {
            for (int c = 0; c < key_num; c++)
            {
                for (int d = 0; d < key_num; d++)
                {
                    key[0] = key_array[a];
                    key[1] = key_array[b];
                    key[2] = key_array[c];
                    key[3] = key_array[d];
                    key[4] = '\0';

                    crypt_hash = crypt(key, salt);
                    if (strcmp(crypt_hash, hash) == 0)
                    {
                        printf("%s\n", key);
                        return 0;
                    }
                }
            }
        }
    }

    printf("Check4 done\n");

    for (int a = 0; a < key_num; a++)
    {
        for (int b = 0; b < key_num; b++)
        {
            for (int c = 0; c < key_num; c++)
            {
                for (int d = 0; d < key_num; d++)
                {
                    for (int e = 0; e < key_num; e++)
                    {
                        key[0] = key_array[a];
                        key[1] = key_array[b];
                        key[2] = key_array[c];
                        key[3] = key_array[d];
                        key[4] = key_array[e];

                        crypt_hash = crypt(key, salt);
                        if (strcmp(crypt_hash, hash) == 0)
                        {
                            printf("%s\n", key);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    printf("Check5 done. Nothing found.\n");
}
