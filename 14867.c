#include <stdio.h>
int A, B, C, D;

typedef struct status
{
    int a, b, t;
} status;

int visited[1000+10][1000+10];

status queue[1000*1000+10];
int wp, rp;

void enqueue(int a, int b, int t)
{
    queue[wp].a = a;
    queue[wp].t = t;
    queue[wp++].b = b;
}
status dequeue()
{
    return queue[rp++];
}
int empty()
{
    return wp==rp;
}

int BFS()
{
    enqueue(0, 0, 0);
    visited[0][0] = 1;

    status next;
    int next_a, next_b;
    while(!empty())
    {
        next = dequeue();
        if (next.a == C && next.b == D)
        {
            return next.t;
        }
        // 1. F(A)
        if (visited[A][next.b] == 0)
        {
            enqueue(A, next.b, next.t+1);
            visited[A][next.b] = 1;
        }
        // 2. F(B)
        if (visited[next.a][B] == 0)
        {
            enqueue(next.a, B, next.t+1);
            visited[next.a][B] = 1;
        }
        // 3. E(A)
        if (visited[0][next.b] == 0)
        {
            enqueue(0, next.b, next.t+1);
            visited[0][next.b] = 1;
        }
        // 4. E(B)
        if (visited[next.a][0] == 0)
        {
            enqueue(next.a, 0, next.t+1);
            visited[next.a][0] = 1;
        }
        // 5. M(A, B) -> A+B, 0
        if (B - next.b >= next.a) // A를 B에 붓는데, A가 다 들어가는 경우
        {
            if (visited[0][next.b + next.a] == 0)
            {
                enqueue(0, next.a + next.b, next.t+1);
                visited[0][next.b + next.a] = 1;
            }
        }
        else
        {
            if (visited[next.a - (B - next.b)][B] == 0) // A가 다 안들어가는 경우
            {
                enqueue(next.a-(B-next.b), B, next.t+1);
                visited[next.a-(B-next.b)][B] = 1;
            }
        }
        // 6. M(B, A)
        if (A - next.a >= next.b) // B를 A에 붓는데, B가 다 들어가는 경우
        {
            if (visited[next.a + next.b][0] == 0)
            {
                enqueue(next.a+next.b, 0, next.t+1);
                visited[next.a+next.b][0] = 1;
            }
        }
        else
        {
            if (visited[A][next.b - (A-next.a)] == 0) // B가 다 안들어가는 경우
            {
                enqueue(A, next.b-(A-next.a), next.t+1);
                visited[A][next.b-(A-next.a)] = 1;
            }
        }
    }
    return -1;
}

void InputData(void) {
	scanf("%d %d %d %d", &A, &B, &C, &D);
}
int main(void) {
	int ans = -2;
	InputData();//입력받는 부분
	
	// 여기서부터 작성
    ans = BFS();

	printf("%d\n", ans);// 출력하는 부분
	return 0;
}