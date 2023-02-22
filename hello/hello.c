#include <stdio.h>
#include <cs50.h>

int main(void)
{
    // Prompts user to input their name
    string name = get_string("What's your name? ");

    // Greets user
    printf("hello, %s\n", name);
}