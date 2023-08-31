#include <stdio.h>
#include <string.h>

int N, D, K, C;
int A[3000000+10];
int cont[3010];
void InputData(void){
    scanf("%d %d %d %d", &N, &D, &K, &C);
    for (int i=0; i<N ; i++){
        scanf("%d", &A[i]);
    }
}

int main(void){
    int ans = -1;

    InputData();// 입력받는 부분

    // 여기서부터 작성
    int max_cnt = 0;
    int cnt = 1;
	cont[C] = 1; // Coupon
    for (int i = 0; i < K; i++)	// First sliding window
    {
		//printf("input : %d\n", A[i]);
		if (cont[A[i]] == 0)
		{
			cnt++;
		}
		cont[A[i]]++;
    }
	max_cnt = cnt;
	//printf("first cnt: %d\n", cnt);
	for (int i = 0; i < N; i++)
	{
		int in = A[(K+i) % N];
		int out = A[i];
		//printf("in : %d, out : %d ", in, out);
		cont[out]--;
		if (cont[out] == 0)
		{
			cnt--;
		}
		if (cont[in] == 0)
		{
			cnt++;
		}
		cont[in]++;

		if (max_cnt < cnt) max_cnt = cnt;
		//printf("%d\n", cnt);
	}

    printf("%d\n", max_cnt);// 출력하는 부분
    return 0;
}