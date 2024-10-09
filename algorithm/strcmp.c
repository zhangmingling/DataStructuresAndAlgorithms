#include <stdio.h>
#include <stdbool.h>

bool MyStrcmp(const char *dest, const char *src)
{
    while (*dest != '\0' && *src != '\0')
    {
        if (*dest != *src)
        {
            return (*dest - *src);
        }
        dest++;
        src++;
    }
    return (*dest - *src);
}

int main()
{
    const char *str1 = "hello";
    const char *str2 = "hello";
    if (MyStrcmp(str1, str2))
    {
        printf("same\n");
    }
    else
    {
        printf("not the same\n");
    }
    return 0;
}