#include <cstdio>

int n, m;
int T[1000001], P[10001], next[10001];

void getNext() {
    next[0] = -1, next[1] = 0;
    int i = 1, j = 0;
    while(i < m) {
        if(j == -1 || P[j] == P[i]) {
            ++i, ++j;
            next[i] = j;
        }
        else j = next[j];
    }
}

int KMP_Next() {
    int i = 0, j = 0;
    while(i < n && j != m) {
        if(j == -1 || T[i] == P[j]) {
            ++i; ++j;
        }
        else j = next[j];
    }
    if(j == m) return i - m + 1;
    else return -1;
}

// int suffix[10001];
// void getSuffix() {
//     suffix[0] = -1;
//     for (int i = 1; i < m; ++i) {
//         int pre = suffix[i - 1];
//         while (pre >= 0 && P[pre + 1] != P[i]) {
//             pre = suffix[pre];
//         }
//         if (P[pre + 1] == P[i]) suffix[i] = pre + 1;
//         else suffix[i] = -1;
//     }
// }

// int KMP_Suffix() {
//     int tidx, pidx;
//     for(tidx = 0, pidx = 0; tidx < n && pidx < m; ) {
//         if (T[tidx] == P[pidx]) {
//             ++tidx, ++pidx;
//         } else if (pidx == 0) {
//             ++tidx;
//         } else {
//             pidx = suffix[pidx - 1] + 1;
//         }
//     }
//     if (pidx == m) return tidx - m + 1;
//     else return -1;
// }

int main() {
    int t;
    scanf("%d", &t);
    while(t --) {
        scanf("%d%d", &n, &m);
        for(int i(0); i<n; i++) scanf("%d", T+i);
        for(int i(0); i<m; i++) scanf("%d", P+i);
        getNext();

        // for (int i = 0; i < m; ++i) {
        //     printf("%d ", next[i]);
        // }
        // printf("\n");

        printf("%d\n", KMP_Next());
    }
    return 0;
}