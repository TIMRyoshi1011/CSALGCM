#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

const unsigned long long LIMIT = 1000000000000000000ULL;

/*
This function solves a single test case.

Parameters:
k : int - the index of the string in the sequence to consider
i : int - the index of the character to find in M_k

Returns the ith letter in M_k.
*/
char solve(ll k, ll i, const vector<unsigned long long>& len) {
    const string M1 = "MARIO";
    const string M2 = "LUIGI";

    if (k == 1) return M1[i - 1];
    if (k == 2) return M2[i - 1];

    if ((unsigned long long)i <= len[k - 2]) 
        return solve(k - 2, i, len);
    else 
        return solve(k - 1, i - len[k - 2], len);
}

int main() {
    ll i, k;
    cin >> k >> i;

    vector<unsigned long long>len = {0, 5, 5};

    while (true) {
        unsigned long long next = len[len.size() - 2] + len[len.size() - 1];

        if (next > LIMIT) {
            len.push_back(LIMIT);
            break;
        }
        len.push_back(next);
    }

    if (k >= (ll)len.size()) 
        k = len.size() - 1;

    cout << solve(k, i, len) << endl;
}