// NOTE: THIS PROGRAM WAS NOT SUBMITTED IN HACKERRANK

#include <bits/stdc++.h>

#define MAX_N 5500
#define INF 1000000000000000000LL

using namespace std;

typedef long long ll;

int seq1[MAX_N], seq2[MAX_N];

/*
Solve a single test case.

Parameters:
n1   : int - number of events in the original timeline
n2   : int - number of events in the fractured timeline

Returns the minimum energy needed to restore the timeline.
*/
ll solve(int n1, int n2){
    // compute and return answer here
    vector<ll> prev2(n2+1, INF), prev1(n2+1, INF), curr(n2+1, INF);

    prev1[0] = 0;
    for (int j = 1; j <= n2; ++j) prev1[j] = prev1[j-1] + (ll)seq2[j-1];

    for (int i = 1; i <= n1; ++i) {
        curr[0] = prev1[0] + 2LL * (ll)seq1[i-1];

        for (int j = 1; j <= n2; ++j) {
            ll best = INF;

            best = min(best, curr[j-1] + (ll)seq2[j-1]);
            best = min(best, prev1[j] + 2LL * (ll)seq1[i-1]);
            {
                ll replaceCost = 2LL * llabs((ll)seq2[j-1] - (ll)seq1[i-1]);
                best = min(best, prev1[j-1] + replaceCost);
            }

            if (i >= 2 && j >= 2) {
                if ((ll)seq2[j-1] == (ll)seq1[i-2] && (ll)seq2[j-2] == (ll)seq1[i-1]) {
                    ll swapCost = llabs((ll)seq2[j-1] - (ll)seq2[j-2]);
                    best = min(best, prev2[j-2] + swapCost);
                }
            }

            curr[j] = best;
        }
        prev2.swap(prev1);
        prev1.swap(curr);
    }
    return prev1[n2];
}

int main() {
    int n1, n2;
    
    cin >> n1 >> n2;
    
    for(int i = 0; i < n1; i++) {
        cin >> seq1[i];
    }
    
    for(int i = 0; i < n2; i++) {
        cin >> seq2[i];
    }
    
    cout << solve(n1,n2) << endl;
}