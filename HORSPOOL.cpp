#include <string.h>
#include <iostream>
#include <string>
#include <vector>
#include "tester.h"

using namespace std;




void HORSPOOL(char* y, char* x, int n, int m)
{
    const int arrsize=99999;
    int a, i, j, bm_bc[arrsize];
    char ch, lastch;

    /* Preprocessing */
    for (a = 0; a < arrsize; a++) bm_bc[a] = m;
    for (j = 0; j < m - 1; j++) bm_bc[x[j]] = m - j - 1;

    /* Searching */
    lastch = x[m - 1];
    i = 0;
    while (i <= n - m) {
        ch = y[i + m - 1];
        if (ch == lastch)
            if (memcmp(&y[i], x, m - 1) == 0) 
                cout<<(i);
        i += bm_bc[ch];
    }
}
