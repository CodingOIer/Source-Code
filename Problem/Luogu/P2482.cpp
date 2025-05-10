#include <cstdio>
#include <cstring>
#include <vector>
constexpr int MaxN = 1e2 + 5;

// 常量

constexpr int K = 1001; // 杀
constexpr int D = 1002; // 闪
constexpr int P = 1003; // 桃
constexpr int F = 1004; // 决斗
constexpr int N = 1005; // 南蛮入侵
constexpr int W = 1006; // 万箭齐发
constexpr int J = 1007; // 无懈可击
constexpr int Z = 1008; // 诸葛连弩

constexpr int MZ = 2001; // 主猪
constexpr int ZZ = 2002; // 忠猪
constexpr int FZ = 2003; // 反猪

constexpr int LF = 3001; // 类反猪
constexpr int SF = 3002; // 跳反猪
constexpr int SZ = 3003; // 跳忠猪

constexpr int GE = 4001; // Good End
constexpr int BE = 4002; // Bad End
constexpr int WJ = 4003; // 未结束

// 全局变量

int n, m;
int role[MaxN];
int jump[MaxN];
int health[MaxN];
char temp[105];
bool dead[MaxN];
bool combo[MaxN];
std::vector<int> deck;
std::vector<int> v[MaxN];
std::vector<int>::iterator cardIt;

// 函数实现

int discernCard(char ch)
{
    switch (ch)
    {
    case 'K': {
        return K;
    }
    case 'D': {
        return D;
    }
    case 'P': {
        return P;
    }
    case 'F': {
        return F;
    }
    case 'N': {
        return N;
    }
    case 'W': {
        return W;
    }
    case 'J': {
        return J;
    }
    case 'Z': {
        return Z;
    }
    default: {
        return -1;
    }
    }
}
char toChar(int x)
{
    switch (x)
    {
    case K: {
        return 'K';
    }
    case D: {
        return 'D';
    }
    case P: {
        return 'P';
    }
    case F: {
        return 'F';
    }
    case N: {
        return 'N';
    }
    case W: {
        return 'W';
    }
    case J: {
        return 'J';
    }
    case Z: {
        return 'Z';
    }
    default: {
        return '#';
    }
    }
}
void initDeck()
{
    for (int i = 1; i <= m; i++)
    {
        char ch = '\0';
        for (; discernCard(ch) == -1;)
        {
            ch = getchar();
        }
        deck.push_back(discernCard(ch));
    }
    cardIt = deck.begin();
}
int getCard()
{
    int res = *cardIt;
    cardIt++;
    if (cardIt == deck.end())
    {
        cardIt--;
    }
    return res;
}
int distance(int x, int y)
{
    int res = 0;
    for (;;)
    {
        if (x == y)
        {
            break;
        }
        if (!dead[x])
        {
            res++;
        }
        x++;
        if (x == n + 1)
        {
            x = 1;
        }
    }
    return res;
}
std::vector<int>::iterator find(int id, int card)
{
    auto it = v[id].begin();
    for (; it != v[id].end() && *it != card;)
    {
        it++;
    }
    return it;
}
bool have(int id, int card)
{
    return find(id, card) != v[id].end();
}
void jumpTo(int own, int ju)
{
    if (jump[own] == 0)
    {
        jump[own] = ju;
    }
}
void putOut(int own, int card)
{
    v[own].erase(find(own, card));
}
bool wantPut(int own, int card)
{
    if (have(own, card))
    {
        putOut(own, card);
        return true;
    }
    else
    {
        return false;
    }
}
std::vector<int> genPlay(int x)
{
    std::vector<int> v;
    for (int i = 1; i <= n; i++)
    {
        if (!dead[i])
        {
            v.push_back(x);
        }
        x++;
        if (x == n + 1)
        {
            x = 1;
        }
    }
    return v;
}
void deadCheck(int own)
{
}
void hurt(int own, int to, int x, bool mistake)
{
    health[to] -= x;
    if (role[to] == MZ)
    {
        jumpTo(own, mistake ? LF : SF);
    }
    else
    {
        if (jump[to] == LF || jump[to] == SF)
        {
            jumpTo(own, SZ);
        }
        if (jump[to] == SZ)
        {
            jumpTo(own, SF);
        }
    }
    deadCheck(to);
}
void kill(int own, int to)
{
    putOut(own, K);
    if (have(to, D))
    {
        putOut(to, D);
    }
    else
    {
        hurt(own, to, 1, false);
    }
}
void tryBestKill(int id, int to)
{
    if (combo[id])
    {
        for (; have(id, K);)
        {
            kill(id, to);
        }
    }
    else
    {
        if (have(id, K))
        {
            kill(id, to);
        }
    }
}
void basicPlay(int id)
{
}
void MZinPlay(int id)
{
}
void ZZinPlay(int id)
{
}
void FZinPlay(int id)
{
    if (distance(id, 1) <= 1)
    {
    }
}
void inPlay(int id)
{
    if (dead[id])
    {
        return;
    }
    v[id].push_back(getCard());
    v[id].push_back(getCard());
}
int checkEnd()
{
    if (dead[1])
    {
        return BE;
    }
    for (int i = 1; i <= n; i++)
    {
        if (role[i] == FZ && !dead[i])
        {
            return WJ;
        }
    }
    return GE;
}

// 主函数

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        health[i] = 4;
        scanf(" %s", temp);
        if (strcmp(temp, "MP") == 0)
        {
            role[i] = MZ;
        }
        else if (strcmp(temp, "ZP") == 0)
        {
            role[i] = ZZ;
        }
        else if (strcmp(temp, "FP") == 0)
        {
            role[i] = FZ;
        }
        for (int j = 1; j <= 4; j++)
        {
            char ch;
            scanf(" %c", &ch);
            v[i].push_back(discernCard(ch));
        }
    }
    initDeck();
    dead[2] = true;
    int end = checkEnd();
    for (; end == WJ;)
    {
        for (int i = 1; i <= n; i++)
        {
            inPlay(i);
            end = checkEnd();
            if (end != WJ)
            {
                break;
            }
        }
    }
    if (end == GE)
    {
        printf("MP\n");
    }
    else if (end == BE)
    {
        printf("FP\n");
    }
    for (int i = 1; i <= n; i++)
    {
        if (dead[i])
        {
            printf("DEAD\n");
        }
        else
        {
            for (int j = 0; j < int(v[i].size()); j++)
            {
                printf("%c%c", toChar(v[i][j]), j == int(v[i].size()) - 1 ? '\n' : ' ');
            }
        }
    }
    return 0;
}