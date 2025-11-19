#include <bits/stdc++.h>

#define MAX_N 17

using namespace std;

typedef long long ll;

int c[MAX_N][MAX_N];

/*
Solve a single test case.

Parameters:
n : int - number of events

Returns the maximum total cinema value of the best permutation.
*/
ll solve(int n){
    // compute and return answer here
    int full = 1 << n;
    vector<vector<ll>>gain(full, vector<ll>(n, 0));

    for (int m = 1; m < full; m++) {
        int b = __builtin_ctz(m);
        int p = m ^ (1 << b);
        for (int k = 0; k < n; k++) {
            gain[m][k] = gain[p][k] + c[b][k];
        }
    }

    vector<ll> dp(full, LLONG_MIN);
    dp[0] = 0;

    for (int m = 0; m < full; m++) {
        if (dp[m] == LLONG_MIN) continue;

        for (int k = 0; k < n; k++) {
            if (m & (1 << k)) continue;

            int new_m = m | (1 << k);
            ll add = gain[m][k];
            dp[new_m] = max(dp[new_m], dp[m] + add);
        }
    }

    return dp[full - 1];
}
    
int main(){
    int n;
    
    cin >> n;
                        
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            cin >> c[i][j];
        }
    }

    cout << solve(n) << endl;
}