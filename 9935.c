#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXN ((int)1e6)
#define MAXB (36)
char str[MAXN + 10];
char boom[MAXB + 10];
char stk[MAXN + 10];
int sp;

void InputData(void) {
	scanf("%s", str);
	scanf("%s", boom);
}

void push(char s)
{
	stk[sp++] = s;
}

void pop()
{
	sp--;
}

int main(void) {
	InputData();
	
	sp = 0;
	int go_back = 0;
	int str_len = strlen(str);
	int boom_len = strlen(boom);
	for (int i = 0; i < str_len; i++)
	{
		push(str[i]);
		go_back = 1;
		if (sp < boom_len) 
		{
			continue;
		}
		for (int j = 0; j < boom_len; j++)
		{
			if (stk[sp-boom_len+j] != boom[j])
			{
				go_back = 0;
				break;
			}
		}
		if (go_back == 1)
		{
			for (int j = 0; j < boom_len; j++)
			{
				pop();
			}
		}

	}
	
	stk[sp] = '\0';
	if (sp == 0) printf("FRULA");
	else {
		printf("%s", stk);
	}
	
	return 0;
}
