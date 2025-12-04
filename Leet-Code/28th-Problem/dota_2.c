#include <stdlib.h>
#include <string.h>


char* predictPartyVictory(char *senate) {
    int n = strlen(senate);
    if (n == 0) {
        char *ans = malloc(1);
        ans[0] = '\0';
        return ans;
    }

    
    int *rq = malloc(n * sizeof(int));
    int *dq = malloc(n * sizeof(int));
    int r_front = 0, r_rear = 0;
    int d_front = 0, d_rear = 0;

    
    for (int i = 0; i < n; ++i) {
        if (senate[i] == 'R') rq[r_rear++] = i;
        else dq[d_rear++] = i;
    }

    
    while (r_front < r_rear && d_front < d_rear) {
        int r_idx = rq[r_front++];
        int d_idx = dq[d_front++];

        if (r_idx < d_idx) {
            // R bans D, R gets to go again in next round -> push r_idx + n
            rq[r_rear++] = r_idx + n;
        } else {
            // D bans R, D goes again in next round
            dq[d_rear++] = d_idx + n;
        }
    }

    char *result;
    if (r_front < r_rear) {
        result = malloc(8);
        strcpy(result, "Radiant");
    } else {
        result = malloc(5);
        strcpy(result, "Dire");
    }

    free(rq);
    free(dq);
    return result;
}
