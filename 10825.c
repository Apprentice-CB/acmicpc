#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct p
{
    char name[11];
    int kor;
    int eng;
    int math;
} p;

p students[100000+10];
int N;


void getInput()
{
    scanf("%d", &N);
    for (int i = 0; i < N; i++)
    {
        scanf("%s %d %d %d", students[i].name, &students[i].kor, &students[i].eng, &students[i].math);
    }
}

int compare (const void* a, const void * b)
{
    p x = *(p*) a; p y = *(p*) b;
    if (x.kor < y.kor) return 1;
    else if (x.kor == y.kor)
    {
        if (x.eng > y.eng) return 1;
        else if (x.eng == y.eng)
        {
            if (x.math < y.math) return 1;
            else if (x.math == y.math) return strcmp(x.name, y.name);
            else return -1;
        }
        else return -1;
    }
    else return -1;
}

int main(void)
{
    getInput();
    qsort(students, N, sizeof(p), compare);
    for (int i = 0; i < N; i++)
    {
        printf("%s\n", students[i].name);
    }
}