#include <stdio.h>
#include <stdlib.h>

int soma(int x, int y, int z)
{

    if (x >= y)
    {
        if (y >= z)
        {
            x + y;
            x + z;
        }

        if (x < z)
        {
            y + z;
            y + x;
        }
    }
}

int main()
{
    int num1, num2, num3;
    scanf("%d %d %d", &num1, &num2, &num3);

    int res = soma(num1, num2, num3);
    printf("%d", res);
}