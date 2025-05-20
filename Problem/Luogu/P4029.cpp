#include <cstdio>
#include <map>
#include <regex>
#include <string>
constexpr int MaxN = 7e2 + 5;
char temp[MaxN];
std::string s;
std::regex reg("([A-Z])(\\d?)");
std::map<char, int> map;
void solve()
{
    map.clear();
    scanf("%s", temp);
    s = temp;
    int cur = s.find("=");
    for (std::sregex_iterator it(s.begin(), s.end(), reg), end; it != end; it++)
    {
        if (it->position() < cur)
        {
            map[(*it)[1].str()[0]] += (*it)[2].str().empty() ? 1 : std::stoi((*it)[2].str());
        }
        else
        {
            map[(*it)[1].str()[0]] -= (*it)[2].str().empty() ? 1 : std::stoi((*it)[2].str());
        }
    }
    bool rev = int(s.find("?")) < cur;
    for (const auto &[c, _x] : map)
    {
        int x = rev ? -_x : _x;
        if (x < 0 || x > 9)
        {
            printf("No Solution\n");
            return;
        }
    }
    bool found = false;
    for (const auto &[c, _x] : map)
    {
        int x = rev ? -_x : _x;
        if (x >= 1)
        {
            found = true;
            printf("%c", c);
        }
        if (x >= 2)
        {
            printf("%d", x);
        }
    }
    printf("%s\n", found ? "" : "No Solution");
}
int main()
{
    int t;
    scanf("%d%*d", &t);
    for (int i = 1; i <= t; i++)
    {
        solve();
    }
    return 0;
}