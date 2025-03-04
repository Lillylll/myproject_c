
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int a, b;
    a = 100;
    b = 200;
    printf("请输入一个数字：");
    scanf("%d", &a);

    printf("a=%d\n", a);
    printf("b=%d\n", b);
    system("pause");

    return 0;
}