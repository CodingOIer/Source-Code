#include <cstdio>
#include <cstring>
#include <set>
const int MaxT = 1e2 + 5;
const int MaxN = 15;
int t;
int cnt;
int p[MaxT][MaxN][MaxN];
char op[MaxN];
char tmp[MaxN];
std::set<int> temp;
void input()
{
    for (int i = 1; i <= 9; i++)
    {
        scanf("%*s");
        scanf("%s", tmp);
        for (int j = 1; j <= 9; j++)
        {
            p[0][i][j] = tmp[2 * j - 1] - '0';
        }
    }
    scanf("%*s");
}
void copy(int dest, int from)
{
    memcpy(p[dest], p[from], sizeof(p[dest]));
}
bool checkRow(int state, int x, int k)
{
    for (int i = 1; i <= 9; i++)
    {
        if (p[state][x][i] == k)
        {
            return false;
        }
    }
    return true;
}
bool checkCol(int state, int x, int k)
{
    for (int i = 1; i <= 9; i++)
    {
        if (p[state][i][x] == k)
        {
            return false;
        }
    }
    return true;
}
bool checkBlock(int state, int x, int y, int k)
{
    int base_x = ((x - 1) / 3) * 3 + 1;
    int base_y = ((y - 1) / 3) * 3 + 1;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (p[state][base_x + i][base_y + j] == k)
            {
                return false;
            }
        }
    }
    return true;
}
void init(int from = cnt)
{
    cnt++;
    copy(cnt, from);
}
void insert(int x, int y, int k)
{
    init();
    if (p[cnt][x][y] != 0)
    {
        printf("Error!\n");
        return;
    }
    if (!checkRow(cnt, x, k))
    {
        printf("Error:row!\n");
        return;
    }
    if (!checkCol(cnt, y, k))
    {
        printf("Error:column!\n");
        return;
    }
    if (!checkBlock(cnt, x, y, k))
    {
        printf("Error:square!\n");
        return;
    }
    p[cnt][x][y] = k;
    printf("OK!\n");
}
void remove(int x, int y)
{
    init();
    if (p[cnt][x][y] == 0)
    {
        printf("Error!\n");
        return;
    }
    p[cnt][x][y] = 0;
    printf("OK!\n");
}
void query(int x, int y)
{
    init();
    if (p[cnt][x][y] != 0)
    {
        printf("Error!\n");
        return;
    }
    for (int i = 1; i <= 9; i++)
    {
        if (checkRow(cnt, x, i) && checkCol(cnt, y, i) && checkBlock(cnt, x, y, i))
        {
            temp.insert(i);
        }
    }
    printf("%d\n", temp.size());
    for (int k : temp)
    {
        printf("%d\n", k);
    }
    temp.clear();
}
void merge(int x, int y)
{
    init(x);
    int answer_1, answer_2;
    answer_1 = 0;
    answer_2 = 0;
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (p[cnt][i][j] != 0)
            {
                answer_1++;
            }
        }
    }
    for (int i = 1; i <= 9; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (p[cnt][i][j] == 0 && p[y][i][j] != 0 && checkRow(cnt, i, p[y][i][j]) && checkCol(cnt, j, p[y][i][j]) &&
                checkBlock(cnt, i, j, p[y][i][j]))
            {
                answer_2++;
                p[cnt][i][j] = p[y][i][j];
            }
        }
    }
    printf("%d %d\n", answer_1, answer_2);
}
void print(int now = cnt)
{
    for (int i = 1; i <= 9; i++)
    {
        printf("+-+-+-+-+-+-+-+-+-+\n");
        printf("|%d|%d|%d|%d|%d|%d|%d|%d|%d|\n", p[now][i][1], p[now][i][2], p[now][i][3], p[now][i][4], p[now][i][5],
               p[now][i][6], p[now][i][7], p[now][i][8], p[now][i][9]);
    }
    printf("+-+-+-+-+-+-+-+-+-+\n");
}
int main()
{
    freopen("sudoku.in", "r", stdin);
    freopen("sudoku.out", "w", stdout);
    input();
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        scanf("%s", op);
        if (strcmp(op, "Insert") == 0)
        {
            int x, y, k;
            scanf("%d%d%d", &x, &y, &k);
            insert(x, y, k);
        }
        else if (strcmp(op, "Delete") == 0)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            remove(x, y);
        }
        else if (strcmp(op, "Query") == 0)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            query(x, y);
        }
        else if (strcmp(op, "Merge") == 0)
        {
            int x, y;
            scanf("%d%d", &x, &y);
            merge(x, y);
        }
        else if (strcmp(op, "Print") == 0)
        {
            print();
        }
        if (i == 5)
        {
            printf("##############\n");
            print();
        }
    }
    return 0;
}