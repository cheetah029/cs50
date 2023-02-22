#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Declare constant minimum and maximum possible heights and spaces between pyramids
    int MIN_HEIGHT = 1;
    int MAX_HEIGHT = 8;
    int SPACES_BETWEEN_PYRAMIDS = 2;

    // Get user to input a height between MIN_HEIGHT and MAX_HEIGHT
    int height = 0;

    do
    {
        height = get_int("Height: ");
    }
    while (height < MIN_HEIGHT || height > MAX_HEIGHT);

    // Print spaces and hashes for each row
    for (int i = 0; i < height; i++)
    {
        // Print spaces before the hashes for the first pyramid
        for (int j = 0; j < height - i - 1; j++)
        {
            printf(" ");
        }

        // Print hashes for the first pyramid
        for (int k = 0; k < i + 1; k++)
        {
            printf("#");
        }

        // Print spaces to separate the pyramids
        for (int l = 0; l < SPACES_BETWEEN_PYRAMIDS; l++)
        {
            printf(" ");
        }

        // Print hashes for the second pyramid
        for (int m = 0; m < i + 1; m++)
        {
            printf("#");
        }

        // Print a new line at the end of the row
        printf("\n");
    }
}