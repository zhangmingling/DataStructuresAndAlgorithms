#include <stdio.h>
int main()
{
    int y = 1;
    while (y < 5)
    {
        if (y % 2 == 0)
        {
            printf("%d is even\n", y);
        }
        else
        {
            printf("%d is odd\n", y);
        }
        y++;
    }
    return 0;
}