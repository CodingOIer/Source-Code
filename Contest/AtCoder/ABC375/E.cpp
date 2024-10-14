#include <cmath>
#include <iostream>
#include <numeric>
#include <unordered_map>
#include <vector>

using namespace std;

// 定义一个方法来获取每个队伍的成员及其权重
void calculateTeamWeight(const vector<int> &A, const vector<int> &B, vector<int> &teamWeight)
{
    for (size_t i = 0; i < A.size(); ++i)
    {
        teamWeight[A[i] - 1] += B[i];
    }
}

// 主要函数，检查是否可以平衡队伍并找出最小转换人数
int minTransfers(vector<int> &A, vector<int> &B)
{
    int n = A.size();

    // 队伍只有3个，初始化其力量为0
    vector<int> teamWeight(3, 0);
    calculateTeamWeight(A, B, teamWeight);

    int totalWeight = accumulate(teamWeight.begin(), teamWeight.end(), 0);

    // 检查能否平均分配
    if (totalWeight % 3 != 0)
    {
        return -1; // 无法平分
    }

    int targetWeight = totalWeight / 3;
    int transferCount = 0;
    unordered_map<int, int> excessMap;

    for (int i = 0; i < 3; ++i)
    {
        int excess = teamWeight[i] - targetWeight;

        if (excess != 0)
        {
            // 记录多余或缺少的力量和需要的转换
            while (!excessMap.empty() && (excess > 0 && excessMap.begin()->first < 0) ||
                   (excess < 0 && excessMap.begin()->first > 0))
            {
                int otherExcess = excessMap.begin()->first;
                int count = min(abs(excess), abs(otherExcess));
                excess -= count * (otherExcess > 0 ? 1 : -1);
                if (count == abs(otherExcess))
                    excessMap.erase(excessMap.begin());
                else
                    excessMap[otherExcess - count * (otherExcess > 0 ? 1 : -1)] -= 1;
                transferCount += count;
            }
            if (excess != 0)
                excessMap[excess]++;
        }
    }

    return transferCount;
}

// 主函数，运行测试用例
int main()
{
    int N;
    cin >> N;
    vector<int> A(N), B(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> A[i];
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> B[i];
    }

    int result = minTransfers(A, B);
    if (result != -1)
    {
        cout << "Possible with " << result << " transfers" << endl;
    }
    else
    {
        cout << "Not possible" << endl;
    }

    return 0;
}