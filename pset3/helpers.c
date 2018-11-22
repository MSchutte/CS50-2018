// Helper functions for music

#include <cs50.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include "helpers.h"

// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int x = fraction[0] - '0';
    int y = fraction[2] - '0';
    int division = 8 / y;
    int dur = x * division;
    return dur;
}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    double n;
    double freq;
    int octave = note[strlen(note) - 1] - '0';
    int steps = octave - 4;
    n = steps * 12;

    if (note[1] == '#')
    {
        n++;
    }
    else if (note[1] == 'b')
    {
        n--;
    }

    if (note[0] == 'B')
    {
        n = n + 2;
    }
    else if (note[0] == 'C')
    {
        n = n - 9;
    }
    else if (note[0] == 'D')
    {
        n = n - 7;
    }
    else if (note[0] == 'E')
    {
        n = n - 5;
    }
    else if (note[0] == 'F')
    {
        n = n - 4;
    }
    else if (note[0] == 'G')
    {
        n = n - 2;
    }

    freq = round((pow(2.00, n / 12)) * 440);
    return freq;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    if (strcmp(s, "") == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}
