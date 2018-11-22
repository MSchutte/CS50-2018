#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int x[8], y[8], a, b, c, sum = 0, z = 0;
    long long cc, m1 = 10, m2 = 1;

    cc = get_long_long("What is your creditcardnumber?\n");

    for (int i = 0; i < 8; i++)
    {
        x[i] = (cc / m1 % 10) * 2;
        m1 = m1 * 100;
    }

    for (int p = 0; p < 8; p++)
    {
        a = x[p] % 10;
        b = x[p] / 10 % 10;
        sum = sum + a + b;
    }

    for (int k = 0; k < 8; k++)
    {
        y[k] = cc / m2 % 10;
        m2 = m2 * 100;
        sum = sum + y[k];
    }

    int valid = sum % 10;

    if (valid == 0)
    {
        // AMEX start with 34 or 37, 15 nrs
        // MASTERCARD start with 51, 52, 53, 54 or 55, 16 nrs
        // VISA start with 4, 13 or 16 nrs

        if ((x[7] == 0 && y[7] == 3) && (x[6] / 2 == 4 || x[6] / 2 == 7))
        {
            printf("AMEX\n");
        }
        else if (x[7] / 2 == 5 && (y[7] < 6))
        {
            printf("MASTERCARD\n");
        }
        else if (x[7] / 2 == 4 || (y[6] == 4 && x[6] / 2 == 7 && x[7] / 2 == 0 && y[7] == 0))
        {
            printf("VISA\n");
        } else {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }

    return 0;

}
