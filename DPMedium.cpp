#include <bits/stdc++.h>

#define MAX_C 75
#define MAX_N 75
#define MAX_K 75
#define WEIGHT 0
#define VALUE 1
#define NEG_INF -1e9

typedef long long ll;

using namespace std;

int items[MAX_N][2];

/*
This function solves one test case.

Parameters:
n     : int - number of items
c     : int - credit limit on your coupon
k     : int - limit of negative cost items you can get

Returns the maximum total appeal you can claim with your coupon.
*/
ll solve(int n, int c, int k) {
    // compute and return answer here
    int n_items[MAX_N][2];
    int p_items[MAX_N][2];
    int n_cnt = 0, p_cnt = 0;

    for (int i = 0; i < n; ++i) {
        if (items[i][0] < 0) {
            n_items[n_cnt][0] = items[i][0];
            n_items[n_cnt][1] = items[i][1];
            n_cnt++;
        } else {
            p_items[p_cnt][0] = items[i][0];
            p_items[p_cnt][1] = items[i][1];
            p_cnt++;
        }
    }

    int b = 0;
    for (int i = 0; i < n_cnt; i++) 
        b += abs(n_items[i][0]);

    int S = 2 * b + 1;
    vector<vector<ll>> N(k + 1, vector<ll>(S, NEG_INF));
    N[0][b] = 0;

    for (int i = 0; i < n_cnt; i++) {
        vector<vector<ll>> newN = N;
        int w = n_items[i][0];
        int v = n_items[i][1];

        for (int t = 0; t < k; t++) {
            for (int s = 0; s < S; s++) {
                if (N[t][s] == NEG_INF) continue;

                int new_s = s + w;
                if (0 <= new_s && new_s < S) {
                    newN[t + 1][new_s] = max(newN[t + 1][new_s], N[t][s] + v);
                }
            }
        }
        N.swap(newN);
    }

    int c_max = c + b;
    vector<ll> P(c_max + 1, 0);
    for (int i = 0; i < p_cnt; i++) {
        int w = p_items[i][0];
        int v = p_items[i][1];
        if (w > c_max) continue;
        for (int cap = c_max; cap >= w; cap--) {
            P[cap] = max(P[cap], P[cap - w] + v);
        }
    }

    ll ans = 0; 
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j < S; j++) {
            if (N[i][j] == NEG_INF) 
                continue;

            int total_n_weight = j - b;
            int r_cap = c - total_n_weight; 

            if (r_cap < 0) continue;
            if (r_cap > c_max) r_cap = c_max;
            
            ans = max(ans, N[i][j] + P[r_cap]);
        }
    }
    return ans;
}

int main() {
    int n, c, k;

    cin >> n >> c >> k;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> items[i][j];
        }
    }

    cout << solve(n,c,k) << endl;
}