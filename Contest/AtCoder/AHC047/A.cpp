#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const int M = 12;
int N_input, M_input;
ll L;

vector<string> patterns;
vector<int> prefs;

struct AhoNode
{
    int next[6];
    int fail;
    vector<int> out;
    AhoNode()
    {
        memset(next, -1, sizeof(next));
        fail = -1;
    }
};

vector<AhoNode> aho;

void buildAC()
{
    aho.clear();
    aho.emplace_back();
    for (int i = 0; i < N_input; i++)
    {
        int u = 0;
        for (char c : patterns[i])
        {
            int idx = c - 'a';
            if (aho[u].next[idx] == -1)
            {
                aho[u].next[idx] = aho.size();
                aho.emplace_back();
            }
            u = aho[u].next[idx];
        }
        aho[u].out.push_back(i);
    }
    queue<int> q;
    aho[0].fail = 0;
    for (int c = 0; c < 6; c++)
    {
        int v = aho[0].next[c];
        if (v != -1)
        {
            aho[v].fail = 0;
            q.push(v);
        }
        else
        {
            aho[0].next[c] = 0;
        }
    }
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int c = 0; c < 6; c++)
        {
            int v = aho[u].next[c];
            if (v != -1)
            {
                aho[v].fail = aho[aho[u].fail].next[c];
                for (int idx : aho[aho[v].fail].out)
                {
                    aho[v].out.push_back(idx);
                }
                q.push(v);
            }
            else
            {
                aho[u].next[c] = aho[aho[u].fail].next[c];
            }
        }
    }
}

struct Solution
{
    char C[M];
    int A[M][M];
};

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

double evaluateSolution(const Solution &sol, int K)
{
    int n = N_input;
    vector<int> countFound(n, 0);
    vector<vector<int>> cum(M, vector<int>(M));
    for (int i = 0; i < M; i++)
    {
        int sum = 0;
        for (int j = 0; j < M; j++)
        {
            sum += sol.A[i][j];
            cum[i][j] = sum;
        }
    }
    for (int sim = 0; sim < K; sim++)
    {
        vector<bool> found(n, false);
        int markov_state = 0;
        int ac_state = 0;
        char c0 = sol.C[markov_state];
        ac_state = aho[ac_state].next[c0 - 'a'];
        for (int pid : aho[ac_state].out)
            found[pid] = true;
        for (int i = 1; i < L; i++)
        {
            int r = rng() % 100;
            for (int j = 0; j < M; j++)
            {
                if (r < cum[markov_state][j])
                {
                    markov_state = j;
                    break;
                }
            }
            char cc = sol.C[markov_state];
            ac_state = aho[ac_state].next[cc - 'a'];
            for (int pid : aho[ac_state].out)
                found[pid] = true;
        }
        for (int i = 0; i < n; i++)
        {
            if (found[i])
                countFound[i]++;
        }
    }
    double score = 0;
    for (int i = 0; i < n; i++)
    {
        double Qi = double(countFound[i]) / K;
        score += prefs[i] * Qi;
    }
    return score;
}

Solution mutateSolution(const Solution &base)
{
    Solution sol = base;
    if (rng() & 1)
    {
        int i = rng() % M;
        sol.C[i] = char('a' + (rng() % 6));
    }
    else
    {
        int i = rng() % M;
        vector<int> cuts;
        cuts.push_back(0);
        cuts.push_back(100);
        for (int t = 0; t < M - 1; t++)
        {
            cuts.push_back(rng() % 101);
        }
        sort(cuts.begin(), cuts.end());
        for (int j = 0; j < M; j++)
        {
            sol.A[i][j] = cuts[j + 1] - cuts[j];
        }
    }
    return sol;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N_input >> M_input >> L;
    patterns.resize(N_input);
    prefs.resize(N_input);
    for (int i = 0; i < N_input; i++)
    {
        cin >> patterns[i] >> prefs[i];
    }
    buildAC();
    Solution bestSol;
    for (int i = 0; i < M; i++)
    {
        bestSol.C[i] = char('a' + (rng() % 6));
        vector<int> cuts = {0, 100};
        for (int t = 0; t < M - 1; t++)
        {
            cuts.push_back(rng() % 101);
        }
        sort(cuts.begin(), cuts.end());
        for (int j = 0; j < M; j++)
        {
            bestSol.A[i][j] = cuts[j + 1] - cuts[j];
        }
    }
    double bestScore = evaluateSolution(bestSol, 3);

    auto t_start = chrono::steady_clock::now();
    while (true)
    {
        auto t_now = chrono::steady_clock::now();
        double elapsed = chrono::duration<double>(t_now - t_start).count();
        if (elapsed > 1.8)
            break;

        Solution cand = mutateSolution(bestSol);
        double score = evaluateSolution(cand, 1);
        if (score > bestScore)
        {
            bestScore = score;
            bestSol = cand;
        }
    }

    for (int i = 0; i < M; i++)
    {
        cout << bestSol.C[i];
        for (int j = 0; j < M; j++)
        {
            cout << " " << bestSol.A[i][j];
        }
        cout << "\n";
    }
    return 0;
}