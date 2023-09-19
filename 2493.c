#include <stdio.h>

int stack[500000+10];
int sp;

void push(int num) {stack[++sp] = num;}
int top() {return stack[sp];}
void pop() {sp--;}
int empty() {return sp == 0;}

int N;
int A[500000+10];
int sol[500000+10];

void getInput()
{
    scanf("%d", &N);
    for (int i = 1; i <= N; i++)
    {
        scanf("%d", &A[i]);
    }
}

int main(void)
{
    getInput();

    sp = 0;
    int base = 0;
    for (int i = 1; i <= N; i++)
    {
        while (!empty()) 
        {
            if (A[i] < A[top()])
            {
                printf("%d ", top());
                break;
            }
            pop();
        }
        if (empty())
        {
            printf("0 ");
        }
        push(i);
    }

}