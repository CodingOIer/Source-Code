#include <cstdio>
#include <string>
#include <vector>

// Global Variable

std::vector<std::string> code;

// Tools Function

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

std::string method(std::string op, std::vector<std::string> args)
{
    std::string res = op;
    res += "(";
    for (int i = 0; i < int(args.size()); i++)
    {
        res += args[i];
        if (i == int(args.size()) - 1)
        {
            break;
        }
        res += ", ";
    }
    res += ")";
    return res;
}
std::string method(std::string op, std::vector<int> args)
{
    std::vector<std::string> argss;
    for (const auto &val : args)
    {
        argss.push_back(std::to_string(val));
    }
    return method(op, argss);
}

void let(int ref, std::string val)
{
    std::string end = std::to_string(ref) + " = " + val + ";";
    code.push_back(end);
}

void endProgram()
{
    for (const std::string &line : code)
    {
        printf("%s\n", line.c_str());
    }
    code.clear();
}

// Answer Function

void vote(std::vector<int> input, int output, int hold)
{
    std::vector<std::string> can;
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
            can.push_back(method("AND", wait));
        }
    }
    let(output, method("OR", can));
}

// Main Function

int main()
{
    vote(range(1, 3), 4, 2);
    endProgram();
    return 0;
}
