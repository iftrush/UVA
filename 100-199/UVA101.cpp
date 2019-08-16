#include <cstdio>
#include <cstring>
#include <list>
#include <algorithm>
using namespace std;

list<int> stk[25];
int pos[25];

void init(int n)
{

    for (int i = 0; i < n; i++)
    {
        (stk + i)->clear();
        (stk + i)->push_back(i);
    }

    for (int i = 0; i < n; i++)
        *(pos + i) = i;
}

void clear_above(int x)
{

    int px = pos[x];

    while (stk[px].back() != x)
    {

        int num = (stk + px)->back();
        (stk + num)->push_back(num);
        *(pos + num) = num;
        (stk + px)->pop_back();
    }
}

void move(int x, int y)
{

    int px = pos[x], py = pos[y];

    auto move_begin = std::find(stk[px].begin(), stk[px].end(), x);
    auto move_end = stk[px].end();

    stk[py].insert(stk[py].end(), move_begin, move_end);

    for (auto it = move_begin; it != move_end; it++)
    {
        *(pos + *it) = py;
    }
    stk[px].erase(move_begin, move_end);
}

void result(int n)
{

    for (int i = 0; i < n; ++i)
    {
        printf("%d:", i);

        for (auto it = stk[i].begin(); it != stk[i].end(); it++)
            printf(" %d", *it);
        putchar('\n');
    }
}

int main()
{
    int n;
    scanf("%d", &n);

    init(n);

    char cmd1[10], cmd2[10];
    int a, b;

    while (scanf("%s %d %s %d", cmd1, &a, cmd2, &b) == 4)
    {

        if (a == b)
            continue;
        if (pos[a] == pos[b])
            continue;
        if (strcmp("move", cmd1) == 0)
            clear_above(a);
        if (strcmp("onto", cmd2) == 0)
            clear_above(b);

        move(a, b);
    }
    result(n);

    return 0;
}

// g++ -o UVA101 UVA101.cpp