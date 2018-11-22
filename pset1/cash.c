#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{
    float change;
    do
    {
        change = get_float("How much change? ");
    }
    while (change < 0);
    int cents = round(change * 100);

    // quarters (25c)
    int quarters = cents / 25;
    int left = cents % 25;
    // dimes (10c)
    int dimes = left / 10;
    left = left % 10;
    // nickels (5c)
    int nickels = left / 5;
    left = left % 5;
    // penny(c)
    int pennies = left;

    int coins = quarters + dimes + nickels + pennies;

    printf("%i \n", coins);
}
