#include <stdio.h>
#include <stdlib.h>
#define MAXNM ((int)1e5)
int N, M;//소마리수, 잔디구간 개수
long long A[MAXNM+10];//잔디 구간 시작
long long B[MAXNM+10];//잔디 구간 끝

typedef struct node
{
    long long A;
    long long B;
} node;

node X[MAXNM+10];

void InputData(void){
	scanf("%d %d", &N, &M);
	for (int i=0; i<M; i++){
		scanf("%lld %lld", &X[i].A, &X[i].B);
	}
}

long long max(long long a, long long b)
{
    if (a > b) return a;
    return b;
}

int isPossible(long long d) // 특정 거리 d에 대해서 가능한지 탐색
{
    long long pos = X[0].A;
    int cnt = 1;
    for (int i = 0; i < M; i++)
    {
        long long s = X[i].A;
        long long e = X[i].B;
        while (pos + d <= e)
        {
            pos = max(pos + d, s); // 다음 잔디안에 들어가면 되고 pos+d로 유지, 안들어가면 다음 첫시작으로
            cnt++;
        }
    }
    return cnt;
}

int compare(const void* a, const void* b)
{
    node x = *(node*) a;
    node y = *(node*) b;
    if (x.A > y.A) return 1;
    else if (x.A == y.A) return 0;
    return -1;
}

int main(void){
	long long ans = 0;
	InputData();//입력

    qsort(X, M, sizeof(node), compare);
    long long s = 1; long long e = X[M-1].B;
    long long m; // 소들 간의 구간
    while (s <= e)
    {
        m = (s + e) / 2;
        if (isPossible(m) >= N) // 가능하다면 구간을 늘려야지
        {
            ans = m;
            s = m + 1;
        }
        else    // 불가능하다면 구간 줄이기
        {
            e = m - 1;
        }
    }

	printf("%lld\n", ans);//출력
	return 0;
}