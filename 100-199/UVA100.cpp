#include <cstdio>
#include <map>
#include <algorithm>
using namespace std;

map<int, int> m;

void solve(int n)
{
    int t = n & 1 ? 3 * n + 1 : n / 2;
    if (!m[n])
        solve(t);
    m[n] = m[t] + 1;
}

int main()
{
    m[1] = 1;
    for (int i, j, ans; ~scanf("%d%d", &i, &j);)
    {
        ans = 0;
        for (int k = min(i, j), l = i + j - k; k <= l; k++)
        {
            if (!m[k])
                solve(k);
            if (ans < m[k])
                ans = m[k];
        }
        printf("%d %d %d\n", i, j, ans);
    }
    return 0;
}

// g++ -o UVA100 UVA100.cpp
