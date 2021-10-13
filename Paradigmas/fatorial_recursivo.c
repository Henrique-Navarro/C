#include <stdio.h>
#include <stdlib.h>

int fatorial(int num)
{
    int result;
    if (num == 0)
    {
        return 1;
    }
    else
    {
        result = num * (fatorial(num - 1));
    }

    return result;
}

int main()
{
    int num;
    scanf("%d", &num);

    int res = fatorial(num);
    printf("%d", res);
}