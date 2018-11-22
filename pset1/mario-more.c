#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int n;
    int s;
    int h;
    // prompt the user to define the height of the half pyramid (n)
    do
    {
        n = get_int("Enter a number between 0 and 23: ");
    }
    while (n < 0 || n > 23);

    // set the starting number of spaces (s) and hashtags (h) for the first row
    s = n - 1;
    h = 1;

    // print the pyramid
    for (int i = 0; i < n; i++)
    {
        for (int j = s; j > 0; j--)
        {
            printf(" ");
        }

        for (int k = 0; k < h; k++)
        {
            printf("#");
        }
        printf("  ") ;
        for (int k = 0; k < h; k++)
        {
            printf("#");
        }

        s--;
        h++;
        printf("\n");
    }
}
