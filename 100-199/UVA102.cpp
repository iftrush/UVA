#include <cstdio>

int main()
{
    int n;
    int B[3], G[3], C[3], move[6];
    char s[][4] = {"BCG", "BGC", "CBG", "CGB", "GBC", "GCB"};
    while (~scanf("%d %d %d %d %d %d %d %d %d",
                  B, G, C,
                  (B + 1), (G + 1), (C + 1),
                  (B + 2), (G + 2), (C + 2)))
    {
        int sum = 0;
        for (int i = 0; i < 3; i++)
            sum += (*(B + i) + *(G + i) + *(C + i));

        *(move + 0) = sum - *(B + 0) - *(G + 2) - *(C + 1); //BCG
        *(move + 1) = sum - *(B + 0) - *(G + 1) - *(C + 2); //BGC
        *(move + 2) = sum - *(B + 1) - *(G + 2) - *(C + 0); //CBG
        *(move + 3) = sum - *(B + 2) - *(G + 1) - *(C + 0); //CGB
        *(move + 4) = sum - *(B + 1) - *(G + 0) - *(C + 2); //GBC
        *(move + 5) = sum - *(B + 2) - *(G + 0) - *(C + 1); //GCB

        int min = sum, cur, step;

        for (int i = 0; i < 6; i++)
        {
            cur = *(move + i);
            if (cur < min)
            {
                min = cur;
                step = i;
            }
        }
        printf("%s %d\n", s[step], min);
    }
    return 0;
}

// g++ -o UVA102 UVA102.cpp