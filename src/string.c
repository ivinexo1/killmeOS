#include "../include/string.h"

int strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return (int)(*str1) - (int)(*str2);
}





