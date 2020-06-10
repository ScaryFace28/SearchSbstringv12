#include <iostream>
#include <string>
#include <vector>
#include "tester.h"



void TRF(char* x, int m, char* y, int n) {
    int period, i, j, shift, u, periodOfU, disp, init,
        state, mu, mpNext[XSIZE + 1];
    char* xR;
    Graph aut;

    /* Preprocessing */
    aut = newSuffixAutomaton(2 * (m + 2), 2 * (m + 2) * ASIZE);
    xR = reverse(x, m);
    buildSuffixAutomaton(xR, m, aut);
    init = getInitial(aut);
    preMp(x, m, mpNext);
    period = m - mpNext[m];
    i = 0;
    shift = m;

    /* Searching */
    j = 0;
    while (j <= n - m) {
        i = m - 1;
        state = init;
        u = m - 1 - shift;
        periodOfU = (shift != m ?
            m - shift - mpNext[m - shift] : 0);
        shift = m;
        disp = 0;
        while (i > u &&
            getTarget(aut, state, y[i + j]) !=
            UNDEFINED) {
            disp += getShift(aut, state, y[i + j]);
            state = getTarget(aut, state, y[i + j]);
            if (isTerminal(aut, state))
                shift = i;
            --i;
        }
        if (i <= u)
            if (disp == 0) {
                cout<<(j);
                shift = period;
            }
            else {
                mu = (u + 1) / 2;
                if (periodOfU <= mu) {
                    u -= periodOfU;
                    while (i > u &&
                        getTarget(aut, state, y[i + j]) !=
                        UNDEFINED) {
                        disp += getShift(aut, state, y[i + j]);
                        state = getTarget(aut, state, y[i + j]);
                        if (isTerminal(aut, state))
                            shift = i;
                        --i;
                    }
                    if (i <= u)
                        shift = disp;
                }
                else {
                    u = u - mu - 1;
                    while (i > u &&
                        getTarget(aut, state, y[i + j]) !=
                        UNDEFINED) {
                        disp += getShift(aut, state, y[i + j]);
                        state = getTarget(aut, state, y[i + j]);
                        if (isTerminal(aut, state))
                            shift = i;
                        --i;
                    }
                }
            }
        j += shift;
    }
}