#include <cs50.h>
#include <stdio.h>
#include <string.h>

int count_digits(long number);
bool is_valid(long number, int number_length);
void long_to_string(long number, char num_str[]);
bool is_company(int number_length, string num_str, string company_name);
bool same_prefix(string s1, string s2);

int main(void)
{
    // Prompt user to enter card number
    long number = 0;

    do
    {
        number = get_long("Number: ");
    }
    while (number < 0);

    // Count length of card number
    int number_length = count_digits(number);

    // Validate card number
    char num_str[128];
    long_to_string(number, num_str);

    if (!is_valid(number, number_length))
    {
        printf("INVALID");
    }
    else if (is_company(number_length, num_str, "AMEX"))
    {
        printf("AMEX");
    }
    else if (is_company(number_length, num_str, "MASTERCARD"))
    {
        printf("MASTERCARD");
    }
    else if (is_company(number_length, num_str, "VISA"))
    {
        printf("VISA");
    }
    else
    {
        printf("INVALID");
    }

    printf("\n");
}

int count_digits(long number)
{
    // Count the number of digits in the number
    int count = 1;

    while (number > 9)
    {
        number /= 10;
        count++;
    }

    return count;
}

bool is_valid(long number, int number_length)
{
    int sum = 0;
    char num_str[128];
    long_to_string(number, num_str);

    // Calculate checksum for even place-valued digits counting backwards
    for (int i = number_length - 2; i > -1; i -= 2)
    {
        char digit_char = num_str[i];
        int digit_int = digit_char - '0';

        sum += (digit_int < 5) ? digit_int * 2 : digit_int * 2 - 9;
    }

    // Calculate checksum for odd place-valued digits counting backwards
    for (int i = number_length - 1; i > -1; i -= 2)
    {
        char digit_char = num_str[i];
        int digit_int = digit_char - '0';

        sum += digit_int;
    }

    // Check if the last digit of the total is 0
    return sum % 10 == 0;
}

void long_to_string(long number, char num_str[])
{
    // Convert a long integer to its string format
    sprintf(num_str, "%ld", number);
}

bool is_company(int number_length, string num_str, string company_name)
{
    // Check if the length and prefix of the number match the requirements for the specified company
    if (same_prefix(company_name, "AMEX"))
    {
        return number_length == 15 &&
               (same_prefix(num_str, "34") ||
                same_prefix(num_str, "37"));
    }
    else if (same_prefix(company_name, "MASTERCARD"))
    {
        return number_length == 16 &&
               (same_prefix(num_str, "51") ||
                same_prefix(num_str, "52") ||
                same_prefix(num_str, "53") ||
                same_prefix(num_str, "54") ||
                same_prefix(num_str, "55"));
    }
    else if (same_prefix(company_name, "VISA"))
    {
        return (number_length == 13 ||
                number_length == 16) &&
               (same_prefix(num_str, "4"));
    }

    return false;
}

bool same_prefix(string s1, string s2)
{
    // Check if two strings have the same prefix
    return strncmp(s1, s2, strlen(s2)) == 0;
}

// Style50 is really annoying
// and still wants me to add more comments
// even though doing so is now absolutely unnecessary
// so I am adding extra comments here and now it finally stops yelling at me