#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num, res = 1, passou = 0;
    scanf("%d", &num);

    for (int i = 0; i < num; i++, num--)
    {
        res = res * num;
        passou = 1;
    }

    if (passou == 1)
    {
        printf("%d", res);
    }
    else
    {
        printf("0");
    }
}