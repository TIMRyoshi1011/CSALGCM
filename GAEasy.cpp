// NOTE: THIS PROGRAM WAS NOT SUBMITTED IN HACKERRANK

#include <bits/stdc++.h>

#define MAX_N 300000

using namespace std;

int haha[MAX_N];

/*
This function solves a single test case.

Parameters:
n : int - number of available TokTik cat videos
k : int - number of videos Al wants to watch
c : int - Al's lung capacity

Returns the minimum inhales needed for Al to watch k videos or -1 if impossible
*/
int solve(int n,int k,int c) {
    // compute and return answer here
    auto feasible = [&](long long m) -> bool {
        long long used_inhales = 0;
        long long oxygen = c;
        int picked = 0;
        int i = 0;

        while(i < n && picked < k) {
            if(oxygen < 0) {
                if(used_inhales == m) return false;
                used_inhales++;
                oxygen = c;
                continue;
            }
            picked++;
            oxygen -= haha[i];
            i++;
        }
        return picked >= k;
    };

    long long left = 0, right = k - 1;
    long long answer = -1;

    while(left <= right) {
        long long mid = (left + right) / 2;
        if(feasible(mid)) {
            answer = mid;
            right = mid - 1; 
        } else {
            left = mid + 1;
        }
    }
    return (int)answer;
}

int main() {
    int N, K, C;

    cin >> N >> K >> C;

    for(int i = 0; i < N; i++) {
        cin >> haha[i];
    }

    cout << solve(N,K,C) << endl;
}