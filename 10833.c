#include <stdio.h>

int main(void)
{
    int N = 0;
    scanf("%d", &N);
    int sum = 0;
    int stu = 0;
    int app = 0;
    for (int i = 0; i < N; i++)
    {
        scanf("%d %d", &stu, &app);
        sum += app % stu;
    }
    printf("%d", sum);
}