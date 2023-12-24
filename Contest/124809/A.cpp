#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int digitSum(int num)
{
    int sum = 0;
    while (num > 0)
    {
        sum += num % 10;
        num /= 10;
    }
    return sum;
}

int main()
{
    int T;
    cin >> T;

    vector<int> results;

    for (int t = 0; t < T; ++t)
    {
        int n;
        cin >> n;

        int numDigits = 0;
        int temp = n;
        while (temp > 0)
        {
            temp /= 10;
            numDigits++;
        }

        int maxSum = 0;
        int current = n;
        for (int i = 1; i <= numDigits; ++i)
        {
            int option1 = current + (int)pow(10, i - 1);
            int option2 = current - (int)pow(10, i - 1);
            int option3 = current;

            maxSum = max(maxSum, max(digitSum(option1), max(digitSum(option2), digitSum(option3))));

            current = option3;
        }

        results.push_back(maxSum);
    }

    for (int i = 0; i < T; ++i)
    {
        cout << results[i] << endl;
    }

    return 0;
}
