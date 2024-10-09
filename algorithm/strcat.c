#include <stdio.h>

char *MyStrcat(char *dest, const char *src)
{
    if (dest == NULL || src == NULL)
    {
        return NULL;
    }
    char *start = dest;
    while (*dest != '\0')
    {
        dest++;
    }
    while (*src != '\0')
    {
        *dest++ = *src++;
    }
    *dest = '\0';
    return start;
}

int main()
{
    char dest[] = "he";
    char src[] = "llo";
    printf("%s\n", MyStrcat(dest, src));
    return 0;
}