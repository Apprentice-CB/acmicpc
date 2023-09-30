#include <stdio.h>
#define MAXN ((int)5e5)
int N, K;
char str[MAXN + 10];
char stk[MAXN + 10];
int wp;

void push(char s)
{
    stk[wp++] = s;
}

int empty()
{
    return wp == 0;
}

int size()
{
    return wp;
}

char top() 
{
    return stk[wp-1];
}

void pop()
{
    wp--;
}


void InputData(void) {
	scanf("%d %d", &N, &K);
	scanf("%s", str);
}
int main(void) {
	InputData();//입력 받는 부분

	//여기서부터 작성
    wp = 0;
    for (int i = 0; i < N; i++)
    {
        while (!empty() && K && top() < str[i])
        {
            pop();
            K--;
        }
        push(str[i]);
    }
    wp -= K;
    push(0);
    printf("%s", stk);
	return 0;
}