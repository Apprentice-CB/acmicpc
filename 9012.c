/* 
Array로 stack을 사용했음, 링크드 리스트로 stack을 사용하는 것 구현해야됨 
char에서 indexing해서 단일 문자를 비교할 때에는 strcmp함수가 아니라 그냥 char[idx] == '(' 로 해야됨
왜 쌍따옴표가 아니지?
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX (51)

typedef struct node
{
    char parenthesis;
    struct node* next;
} node;

typedef struct stack
{
    struct node* bottom;
    struct node* top;
} stack;

void initStack(stack* stck)
{
    stck->bottom = NULL;
    stck->top = NULL;
}

void push(stack* stck, char parenthesis_input)
{
    node* newNode = (node*)malloc(sizeof(node));
    newNode->next = stck->top;
    newNode->parenthesis = parenthesis_input;
    stck->top = newNode;
}

char pop(stack* stck)
{
    node* tempNode = stck->top;
    char lastData = tempNode->parenthesis;
    stck->top = tempNode->next;
    free(tempNode);
    return lastData;
}

int main()
{
    stack* s = (stack*)malloc(sizeof(stack));
    int T = 0;
    int length = 0;
    char input[MAX];
    int left = 0;
    int check = 0;
    scanf("%d", &T);
    for (int i = 0; i < T; i++) 
    {
        initStack(s);
        left = 0;
        check = 0;
        scanf("%s", input);
        length = strlen(input);        
        if (input[0] == ')')
        {
            printf("NO\n");
        }
        else if (input[length-1] == '(')
        {
            printf("NO\n");
        }
        else 
        {
            for (int idx = 0; idx < length; idx++) 
            {
                if (input[idx] == '(')
                {
                    left++;
                }
                else
                {
                    left--;
                }
                if (left < 0)
                {
                    check = 1;
                    break;
                }
            }
            if ((left == 0) && (check == 0))
            {
                printf("YES\n");
            }
            else
            {
                printf("NO\n");
            }
        }
    }
    return 0;
    
}