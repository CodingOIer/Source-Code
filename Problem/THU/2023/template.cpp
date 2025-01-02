#include <cstdio>
#include <string>
#include <vector>

// Constexpr Variable

constexpr int TRUE = 14222;
constexpr int FALSE = 14223;
constexpr int TempAddrBegin = 14224;

// Global Variable

int currTempAddr = TempAddrBegin;

// Tool Function

std::string addr(int x)
{
    return std::to_string(x);
}

int getTempAddr()
{
    return currTempAddr++;
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
    if (args.size() == 1)
    {
        return args[0];
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

// Main Function

int main()
{
    return 0;
}
