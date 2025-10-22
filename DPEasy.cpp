#include <bits/stdc++.h>

#define MAX_N 5500
#define MOD 1000000007

typedef long long ll;

using namespace std;

/*
This functions solves a single test case.

Parameters:
a : int - base case constant for the given recurrence
b : int - base case constant for the given recurrence
c : int - base case constant for the given recurrence
n : int - argument for the given recurrence

Returns the value of f(n)
*/
ll solve(int a,int b,int c,int n) {
    // compute and return answer here
    long long F[n + 1];
    F[0] = a % MOD;
    F[1] = b % MOD;
    F[2] = c % MOD;

    for(int i = 3; i <= n; i++) 
        F[i] = ((F[i - 1] * F[i - 2]) % MOD + F[i - 3]) % MOD;
    
    return F[n];
}

int main() {
    int q, a, b, c, n;

    cin >> q;

    for(int i = 0; i < q; i++) {
        cin >> a >> b >> c >> n;

        cout << solve(a,b,c,n) << endl;
    }
}