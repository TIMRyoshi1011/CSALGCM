#include <bits/stdc++.h>

#define MOD 1000000007
#define MAX_N 5500

using namespace std;

/*
This function solves a single test case.

Parameters:
n : int - input to the given recurrence

Returns the value of F(n)
*/
int solve(int n) {
    // compute and return answer here
    int F[MAX_N];
    F[0] = 1;

    for(int i = 1; i <= n; i++) {
        int bound = i / 2;
        int sum = 0;

        for (int j = 0; j <= bound; j++)
            sum  = (sum + F[j]) % MOD;

        F[i] = sum % MOD;
    }   
    return F[n];
}

int main() {
    int n;
    
    cin >> n;
    cout << solve(n) << endl;
}