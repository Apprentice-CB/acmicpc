#include <stdio.h>
#define MAXN (9)
int sudoku[MAXN][MAXN];
int box[MAXN][MAXN+1]; // 3x3칸 번호, 숫자
int garo[MAXN][MAXN+1]; // row index, 숫자
int sero[MAXN][MAXN+1]; // column index, 숫자
typedef struct pixel
{
    int r, c; // 세로, 가로
} pixel;
pixel bin[81];
int bp;
void InputData(void){
    bp = 0;
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            scanf("%d", &sudoku[r][c]);
            if (sudoku[r][c] == 0)
            {
                bin[bp].r = r;
                bin[bp++].c = c;
            }
            else 
            {
                box[(r/3)*3 + c/3][sudoku[r][c]] = 1;
                garo[r][sudoku[r][c]] = 1;
                sero[c][sudoku[r][c]] = 1;
            }
        }
    }
}
void OutputData(void){
    for (int r=0; r<MAXN; r++){
        for (int c=0; c<MAXN; c++){
            printf("%d ", sudoku[r][c]);
        }
        printf("\n");
    }
}

//pixel p 기준 가로 세로 박스 체크하기
int checkGaro(pixel p)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[p.r][i] == 0) return 1;
    }
    int temp[11] = {0, };
    for (int i = 0; i < 9; i++)
    {
        if (temp[sudoku[p.r][i]] != 0) return 0; // 가로 체크하는거니까 row를 고정
        temp[sudoku[p.r][i]] = 1;
    }
    // for (int i = 1; i <= 9; i++)
    // {
    //     if (temp[i] == 0) return 0;
    // }
    return 1;
}

int checkSero(pixel p)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[i][p.c] == 0) return 1;
    }
    int temp[11] = {0, };
    for (int i = 0; i < 9; i++)
    {
        if (temp[sudoku[i][p.c]] != 0) return 0;
        temp[sudoku[i][p.c]] = 1;
    }
    // for (int i = 1; i <= 9; i++)
    // {
    //     if (temp[i] == 0) return 0;
    // }
    return 1;
}

int checkBox(pixel p)
{
    for (int i = 0; i < 9; i++)
    {
        if (sudoku[(p.r/3)*3 + (i/3)][(p.c/3)*3 + i%3] == 0) return 1; // 아직 칸이 다 안찼다면 계속 진행
    }
    int temp[11] = {0, };
    for (int i = 0; i < 9; i++)
    {
        if (temp[sudoku[(p.r/3)*3 + (i/3)][(p.c/3)*3 + i%3]] != 0) return 0;
        temp[sudoku[(p.r/3)*3 + (i/3)][(p.c/3)*3 + i%3]] = 1;
    }
    // for (int i = 1; i <= 9; i++)
    // {
    //     if (temp[i] == 0) return 0;
    // }
    return 1;
}

int DFS(int depth) // 시작하는 칸
{
    if (depth > 0)
    {
        if (!checkGaro(bin[depth-1]))
        {
            // printf("Garo failed at %d, %d, sudoku:%d\n", bin[depth-1].r, bin[depth-1].c, sudoku[bin[depth-1].r][bin[depth-1].c]);
            return 0; // 가로 체크했는데 안되면 쫑
        }
        if (!checkSero(bin[depth-1])) 
        {
            // printf("Sero failed at %d, %d, sudoku:%d\n", bin[depth-1].r, bin[depth-1].c, sudoku[bin[depth-1].r][bin[depth-1].c]);
            return 0; // 세로 체크했는데 안되면 쫑
        }
        if (!checkBox(bin[depth-1])) 
        {
            // printf("Box failed at %d, %d, sudoku:%d\n", bin[depth-1].r, bin[depth-1].c, sudoku[bin[depth-1].r][bin[depth-1].c]);
            return 0; // 박스 체크했는데 안되면 쫑
        }
    }

    // 종료 조건, 끝까지 도달했는데
    if (depth >= bp)
    {
        if (checkGaro(bin[depth-1]) * checkSero(bin[depth-1]) * checkBox(bin[depth-1])) // 다 동작하는거면
        {
            OutputData();
            return 1;
        }
        return 0;
    }

    // 채워나가기
    pixel s = bin[depth];
    for (int nidx = 1; nidx <= 9; nidx++)
    {
        if (box[(s.r/3)*3 + s.c/3][nidx] == 1) continue; // 박스 안에 이미 숫자가 있으면 패스
        if (garo[s.r][nidx] == 1) continue; // 이미 가로 줄 안에 박스가 있으면 패스
        if (sero[s.c][nidx] == 1) continue; // 이미 세로 줄 안에 박스가 있으면 패스
        box[(s.r/3)*3 + s.c/3][nidx] = 1;
        garo[s.r][nidx] = 1;
        sero[s.c][nidx] = 1;
        sudoku[s.r][s.c] = nidx;
        // printf("sudoku[%d][%d] become %d\n", s.r, s.c, nidx);
        if(DFS(depth+1)) return 1; // 쭉 들어갔는데 동작하면 끝내기
        box[(s.r/3)*3 + s.c/3][nidx] = 0; // 동작 안하면 다시 초기화
        garo[s.r][nidx] = 0;    
        sero[s.c][nidx] = 0;
        sudoku[s.r][s.c] = 0;
    }
    return 0;
}

int main(void){
    InputData();//입력받는 부분

    DFS(0);    // 0번 칸부터 작성해 나가기

    // OutputData();//출력하는 부분
    return 0;
}