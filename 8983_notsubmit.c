#include <stdio.h>
#include <stdlib.h>
#define MAXMN ((int)1e5)
int M, N, L;
int X[MAXMN+10];
int A[MAXMN+10];
int B[MAXMN+10];
void InputData(void){
	scanf("%d %d %d", &M, &N, &L);
	for (int i=0; i<M; i++){
		scanf("%d", &X[i]);
	}
	for (int i=0; i<N; i++){
		scanf("%d %d", &A[i], &B[i]);
	}
}

int compare(const void* a, const void* b)
{
    return *(int*)a > *(int*)b;
}

int bsup(int s, int e, int d)
{
    int m = 0;
	int sol = -1;
    while (s <= e)
    {
        m = (s + e) / 2;
        if (X[m] <= d)
		{
			s = m + 1;
			sol = m;
		}
		else
		{
			e = m - 1;
		}
    }
	return sol;
}

int bslow(int s, int e, int d)
{
    int m = 0;
	int sol = -1;
	while (s <= e)
	{
		m = (s + e) / 2;
		if (X[m] >= d)
		{
			e = m - 1;
			sol = m;
		}
		else
		{
			s = m + 1;
		}
	}
	return sol;
}

int main(void){
	int ans = 0;

	InputData();// 입력받는 부분

	//여기서부터 작성
	qsort(X, M, sizeof(int), compare);

	int up;
	int low;
	for (int i = 0; i < N; i++)
	{
		if (B[i] > L) continue;
		up = bsup(0, M-1, L+A[i]-B[i]);
		low = bslow(0, M-1, A[i]+B[i]-L);
		//printf("%d %d %d \n", i, low, up);
		if (low >= 0 && low <= up)
			ans++;
	}

	printf("%d\n", ans);// 출력하는 부분
	return 0;
}