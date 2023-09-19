#include <stdio.h>
char map[5][10];
char testmap[5][10];
int used[15];
int num[15];
int startnums[15];
void InputData(void){
	for (int h=0; h<5; h++){
		scanf("%s", map[h]);
	}
}
void OutputData(void){
	for (int h=0; h<5; h++){
		printf("%s\n", map[h]);
	}
}

int avail1()
{
    if (num[1] != 0 && num[3] != 0 && num[6] != 0 && num[8] != 0) return 1;
    return 0;
}
int avail2()
{
    if (num[2] != 0 && num[3] != 0 && num[4] != 0 && num[5] != 0) return 1;
    return 0;
}
int avail3()
{
    if (num[1] != 0 && num[4] != 0 && num[7] != 0 && num[11] != 0) return 1;
    return 0;
}
int avail4()
{
    if (num[2] != 0 && num[6] != 0 && num[9] != 0 && num[12] != 0) return 1;
    return 0;
}
int avail5()
{
    if (num[5] != 0 && num[7] != 0 && num[10] != 0 && num[12] != 0) return 1;
    return 0;
}
int avail6()
{
    if (num[8] != 0 && num[9] != 0 && num[10] != 0 && num[11] != 0) return 1;
    return 0;
}

int check1()
{
    if (num[1] + num[3] + num[6] + num[8] == 26) return 1;
    return 0;
}
int check2()
{
    if (num[2] + num[3] + num[4] + num[5] == 26) return 1;
    return 0;
}
int check3()
{
    if (num[1] + num[4] + num[7] + num[11] == 26) return 1;
    return 0;
}
int check4()
{
    if (num[2] + num[6] + num[9] + num[12] == 26) return 1;
    return 0;
}
int check5()
{
    if (num[5] + num[7] + num[10] + num[12] == 26) return 1;
    return 0;
}
int check6()
{
    if (num[8] + num[9] + num[10] + num[11] == 26) return 1;
    return 0;
}

int DFS(int startbox) // 시작 칸,
{
    // 매번 각 줄마다 가능한지 check
    if (avail1())   // 가능한데 
    {
        if (!check1()) return 0; //더했더니 26이 아니면 쫑
    }
    if (avail2())
    {
        if (!check2()) return 0;
    }
    if (avail3())
    {
        if (!check3()) return 0;
    }
    if (avail4())
    {
        if (!check4()) return 0;
    }
    if (avail5())
    {
        if (!check5()) return 0;
    }
    if (avail6())
    {
        if (!check6()) return 0;
    }
    // 모두 가능한 경우
    if (avail1() * avail2() * avail3() * avail4() * avail5() * avail6() * check1() * check2() * check3() * check4() * check5() * check6())
    {
        // printf("DFS Done\n");
        map[0][4] = num[1]-1+'A';
        map[1][1] = num[2]-1+'A';
        map[1][3] = num[3]-1+'A';
        map[1][5] = num[4]-1+'A';
        map[1][7] = num[5]-1+'A';
        map[2][2] = num[6]-1+'A';
        map[2][6] = num[7]-1+'A';
        map[3][1] = num[8]-1+'A';
        map[3][3] = num[9]-1+'A';
        map[3][5] = num[10]-1+'A';
        map[3][7] = num[11]-1+'A';
        map[4][4] = num[12]-1+'A';
        return 1;
    }

    if (num[startbox] != 0) 
    {
        // printf("Go directly into DFS %d\n", startbox+1);
        if (DFS(startbox+1)) return 1;// 이미 채워져 있으면 다음 꺼로 바로 넘기기
        return 0;
    }

    // 안채워져 있으면 거기다가 이제 하나씩 넣어봐야됨
    for (int aidx = 1; aidx <= 12; aidx++)
    {
        if (used[aidx] == 1) continue; // 이미 숫자가 사용되어 있으면 continue;
        used[aidx] = 1;
        num[startbox] = aidx;
        // for (int i = 1; i <= 12; i++)
        // {
        //     printf("%d ", num[i]);
        // } printf("\n");
        if (DFS(startbox+1)) return 1;
        used[aidx] = 0;
        num[startbox] = 0;
    }
    return 0;
}

int main(void){
	InputData();//입력받는 부분

	//먼저 있는 알파벳 체크
    for (int yidx = 0; yidx < 5; yidx++)
    {
        for (int xidx = 0; xidx < 9; xidx++)
        {
            if (map[yidx][xidx] != '.' && map[yidx][xidx] != 'x')
            {
                if (yidx == 0)
                {
                    num[1] = map[yidx][xidx] - 'A'+1;
                    used[num[1]] = 1;
                }
                else if (yidx == 1)
                {
                    num[2+xidx/2] = map[yidx][xidx] - 'A'+1;
                    used[num[2+xidx/2]] = 1;
                }
                else if (yidx == 2)
                {
                    if (xidx == 2) 
                    {
                        num[6] = map[yidx][xidx] - 'A'+1;
                        used[num[6]] = 1;
                    }
                    if (xidx == 6) 
                    {
                        num[7] = map[yidx][xidx] - 'A'+1;
                        used[num[7]] = 1;
                    }
                }
                else if (yidx == 3)
                {
                    num[8+xidx/2] = map[yidx][xidx] - 'A'+1;
                    used[num[8+xidx/2]] = 1;
                }
                else
                {
                    num[12] = map[yidx][xidx] - 'A'+1;
                    used[num[12]] = 1;
                }
            }
        }
    }
    for (int i = 1; i <= 12; i++)
    {
        startnums[i] = num[i];
    }

    // printf("nums: ");
    // for (int i = 1; i <=12; i++)
    // {
    //     printf("%d ", num[i]);
    // }printf("\n");
    // printf("used: ");
    // for (int i = 1; i <= 12; i++)
    // {
    //     printf("%d ", used[i]);
    // } printf("\n");
    DFS(1);


	OutputData();//출력하는 부분
	return 0;
}