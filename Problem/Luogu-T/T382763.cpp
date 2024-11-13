#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<string> words(N);
    for (int i = 0; i < N; i++)
    {
        cin >> words[i];
    }

    int score = 0;
    int consecutiveRhymes = 0;
    int lastRhymeLength = 0;

    for (int i = 0; i < N; i++)
    {
        int wordLength = words[i].size();
        int rhymeLength = 0;
        int j = i + 1;

        while (j < N)
        {
            bool isRhyme = true;
            for (int k = 1; k <= min(wordLength, int(words[j].size())); k++)
            {
                if (words[i][wordLength - k] != words[j][k - 1])
                {
                    isRhyme = false;
                    break;
                }
            }
            if (!isRhyme)
            {
                break;
            }
            rhymeLength++;
            j++;
        }

        if (rhymeLength == 0)
        {
            score += lastRhymeLength == 1 ? 2 : 0;
            consecutiveRhymes = 0;
        }
        else
        {
            if (rhymeLength > 1)
            {
                score += rhymeLength * (rhymeLength + 1) / 2;
                consecutiveRhymes = 0;
            }
            else
            {
                consecutiveRhymes++;
                if (consecutiveRhymes >= 5)
                {
                    score *= 2;
                    consecutiveRhymes = 0;
                }
            }
            lastRhymeLength = rhymeLength;
        }
        i = j - 1;
    }

    cout << score << endl;

    return 0;
}
