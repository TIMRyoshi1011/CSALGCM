#include <bits/stdc++.h>

#define MAX_N 300000

using namespace std;

typedef long long ll;

priority_queue<ll> masses;

/*
Solve a single test case.

Parameters:
n      : int                      - number of reactive items
masses : array-like of shape (n,) - list of masses of the reactive items

Returns the maximum energy generated using the given items.
*/

ll solve(int n) {
    // compute and return answer here
    ll total = 0;

    while(masses.size() > 1) {
        ll a = masses.top(); 
                masses.pop();
        ll b = masses.top();
                masses.pop();
        
        ll energy = a + b;
        total += energy;

        ll nm = (a + b + 1) / 2;

        masses.push(nm);
    }
    return total;
}
    
int main() {
    int n;

    cin >> n;

    for(int i = 0; i < n; i++) {
        ll m;
        cin >> m;
        masses.push(m);
    }
    
    cout << solve(n) << endl;
}