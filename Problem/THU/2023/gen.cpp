#include <algorithm>
#include <cstdio>
#include <string>
#include <vector>

// Constexpr Variable

constexpr int TempAddrBegin = 14224;
constexpr int TRUE = TempAddrBegin - 2;
constexpr int FALSE = TempAddrBegin - 1;

// Global Variable

int currTempAddr = TempAddrBegin;

// Tool Function

std::string addr(int x)
{
    return std::to_string(x);
}

int getTempAddr(int size = 1)
{
    return currTempAddr += size;
}

std::vector<int> range(int l, int r, int step = 1)
{
    std::vector<int> res;
    for (int i = l; i <= r; i += step)
    {
        res.push_back(i);
    }
    return res;
}

// Important Function

void let(int cur, int val)
{
    printf("%d = %d;\n", cur, val);
}

int method(std::string op, std::vector<int> cargs)
{
    std::vector<int> args;
    for (const auto &arg : cargs)
    {
        if (arg != 0)
        {
            args.push_back(arg);
        }
    }
    for (; args.size() > 10;)
    {
        std::vector<int> temp;
        for (int i = 0; i < 10; i++)
        {
            temp.push_back(args.back());
            args.pop_back();
        }
        int newExpr = method(op, temp);
        args.push_back(newExpr);
    }
    int res = getTempAddr();
    printf("%d = %s(", res, op.c_str());
    for (int i = 0; i < int(args.size()); i++)
    {
        printf("%s", addr(args[i]).c_str());
        if (i == int(args.size()) - 1)
        {
            break;
        }
        printf(", ");
    }
    printf(");\n");
    return res;
}

int method(std::string op, int cargs)
{
    return method(op, std::vector<int>{cargs});
}

int NOT(int args)
{
    return method("NOT", args);
}

int AND(std::vector<int> args)
{
    return method("AND", args);
}

int OR(std::vector<int> args)
{
    return method("OR", args);
}

int XOR(std::vector<int> args)
{
    return method("XOR", args);
}

int NAND(std::vector<int> args)
{
    return method("NAND", args);
}

int NOR(std::vector<int> args)
{
    return method("NOR", args);
}

int NXOR(std::vector<int> args)
{
    return method("NXOR", args);
}

void init()
{
    let(FALSE, 0);
    let(TRUE, NOT(FALSE));
}

// Answer Function

void vote(std::vector<int> input, int output, int hold)
{
    std::vector<int> can;
    for (int j = 0; j < 1 << int(input.size()); j++)
    {
        int cnt = 0;
        std::vector<int> wait;
        for (int i = 0; i < int(input.size()); i++)
        {
            if (j >> i & 1)
            {
                wait.push_back(input[i]);
                cnt++;
            }
        }
        if (cnt >= hold)
        {
            can.push_back(AND(wait));
        }
    }
    let(output, OR(can));
}

void decode(int E, std::vector<int> input, std::vector<int> output)
{
    for (int j = 0; j < 1 << int(input.size()); j++)
    {
        std::vector<int> wait;
        wait.push_back(E);
        for (int i = 0; i < int(input.size()); i++)
        {
            wait.push_back(NXOR({j >> i & 1 ? TRUE : FALSE, input[i]}));
        }
        let(output[j], AND(wait));
    }
}

void choose(int E, std::vector<int> input, std::vector<int> value, int output)
{
    int temp = getTempAddr();
    let(temp, 0);
    for (int j = 0; j < 1 << int(input.size()); j++)
    {
        std::vector<int> wait;
        wait.push_back(E);
        for (int i = 0; i < int(input.size()); i++)
        {
            wait.push_back(NXOR({j >> i & 1 ? TRUE : FALSE, input[i]}));
        }
        temp = OR({temp, AND({AND(wait), value[j]})});
    }
    let(output, temp);
}

void compare(std::vector<int> a, std::vector<int> b, int output)
{
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    int temp = getTempAddr();
    let(temp, FALSE);
    for (int i = 0; i < int(a.size()); i++)
    {
        std::vector<int> wait;
        wait.push_back(AND({NXOR({a[i], FALSE}), NXOR({b[i], TRUE})}));
        for (int j = 0; j < i; j++)
        {
            wait.push_back(NXOR({a[j], b[j]}));
        }
        temp = OR({temp, AND(wait)});
    }
    let(output, temp);
}

void notCore(std::vector<int> a, std::vector<int> output)
{
    for (int i = 0; i < int(a.size()); i++)
    {
        let(output[i], NOT(a[i]));
    }
}

void addCore(std::vector<int> a, std::vector<int> b, std::vector<int> output, int beginPreAdd = FALSE)
{
    int preAdd = getTempAddr();
    let(preAdd, beginPreAdd);
    for (int i = 0; i < int(a.size()); i++)
    {
        let(output[i], XOR({preAdd, a[i], b[i]}));
        int temp = getTempAddr();
        vote({preAdd, a[i], b[i]}, temp, 2);
        preAdd = temp;
    }
}

void reduceCore(std::vector<int> a, std::vector<int> b, std::vector<int> output)
{
    int notTempBegin = getTempAddr(16);
    std::vector<int> temp = range(notTempBegin, notTempBegin + 15);
    notCore(b, temp);
    addCore(a, temp, output, TRUE);
}

void alu(std::vector<int> op, std::vector<int> a, std::vector<int> b, std::vector<int> output)
{
}

// Main Function

int main()
{
    init();
    // vote(range(1, 3), 4, 2);
    // decode(1, range(2, 6), range(7, 38));
    // choose(1, range(2, 6), range(7, 38), 39);
    // compare(range(1, 16), range(17, 32), 33);
    addCore(range(1, 16), range(17, 32), range(33, 48));
    return 0;
}
