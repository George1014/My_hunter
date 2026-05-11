/*
** EPITECH PROJECT, 2025
** my_hunter
** File description:
** string utility functions
*/

#include "my_hunter.h"

static void reverse_string(char *str, int length)
{
    int i = 0;
    int j = length - 1;
    char temp;

    while (i < j) {
        temp = str[i];
        str[i] = str[j];
        str[j] = temp;
        i++;
        j--;
    }
}

static void handle_zero(char *str)
{
    str[0] = '0';
    str[1] = '\0';
}

static int handle_negative(int *num)
{
    if (*num < 0) {
        *num = -(*num);
        return 1;
    }
    return 0;
}

static int convert_digits(int num, char *str)
{
    int i = 0;

    while (num != 0) {
        str[i] = (num % 10) + '0';
        i++;
        num /= 10;
    }
    return i;
}

void my_itoa(int num, char *str)
{
    int i;
    int is_negative;

    if (num == 0) {
        handle_zero(str);
        return;
    }
    is_negative = handle_negative(&num);
    i = convert_digits(num, str);
    if (is_negative) {
        str[i] = '-';
        i++;
    }
    str[i] = '\0';
    reverse_string(str, i);
}

int my_strlen(const char *str)
{
    int len = 0;

    while (str[len])
        len++;
    return len;
}

void my_strcpy(char *dest, const char *src)
{
    int i = 0;

    while (src[i]) {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
}

void my_strcat(char *dest, const char *src)
{
    int i = 0;
    int j = my_strlen(dest);

    while (src[i]) {
        dest[j + i] = src[i];
        i++;
    }
    dest[j + i] = '\0';
}
