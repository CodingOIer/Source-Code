#include <cstdio>
#include <thread>
#include <vector>
constexpr int MaxN = 3e5 + 5;
constexpr long long Mod = 998'244'353;
int n, k, type;
char *s[MaxN];
long long pow2[MaxN];
long long ezp(long long x, long long y)
{
    return y == 1 ? x : y == 2 ? x * x % Mod : y == 3 ? x * x % Mod * x % Mod : -1;
}
void thread_func(int start_i, int end_i, long long &local_answer)
{
    for (int i = start_i; i <= end_i; i++)
    {
        long long temp = 0;
        for (int j = 1; j < i; j++)
        {
            for (int l = 1; l <= k; l++)
            {
                temp += (s[i][l] ^ s[j][l]) * pow2[l - 1];
                temp %= Mod;
            }
            local_answer = (local_answer + ezp(temp, type)) % Mod;
            temp = 0;
        }
    }
}
int main()
{
    scanf("%d%d%d", &n, &k, &type);
    for (int i = 1; i <= n; i++)
    {
        s[i] = new char[k + 5];
        scanf(" %s", s[i] + 1);
    }
    pow2[0] = 1;
    for (int i = 1; i <= k; i++)
    {
        pow2[i] = pow2[i - 1] * 2 % Mod;
    }
    long long answer = 0;
    const int num_threads = 64;
    std::vector<std::thread> threads(num_threads);
    std::vector<long long> local_answers(num_threads, 0);
    int chunk_size = n / num_threads;
    int remaining = n % num_threads;
    int start = 1;
    for (int tid = 0; tid < num_threads; tid++)
    {
        int current_chunk = chunk_size + (tid < remaining ? 1 : 0);
        int end = start + current_chunk - 1;
        if (end > n)
            end = n;
        threads[tid] = std::thread(thread_func, start, end, std::ref(local_answers[tid]));
        start = end + 1;
    }
    for (auto &t : threads)
    {
        t.join();
    }
    for (auto &la : local_answers)
    {
        answer = (answer + la) % Mod;
    }
    printf("%lld\n", answer);
    for (int i = 1; i <= n; i++)
    {
        delete[] s[i];
    }
    return 0;
}
