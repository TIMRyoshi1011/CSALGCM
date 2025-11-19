#include <bits/stdc++.h>

#define MAX_N 300000

using namespace std;

vector<pair<int, int>> intervals(MAX_N);


/*
Solve a single test case.

n  : int - number of books
y1 : int - start year to cover
y2 : int - end year to cover

Returns the minimum books needed to cover years y1 to y2
*/
int solve(int n, int y1, int y2){
    // compute and return answer here
    sort(intervals.begin(), intervals.begin() + n);
    int curr_end = y1;
    int ctr = 0;
    int i = 0;

    while(curr_end < y2) {
        int max_end = curr_end;

        while(i < n && intervals[i].first <= curr_end) {
            max_end = max(max_end, intervals[i].second);
            i++;
        }

        if(max_end == curr_end) return -1;

        curr_end = max_end;
        ctr++;
    }

    return ctr;
}

int main() {
    int n, y1, y2;

    cin >> n >> y1 >> y2;

    for(int i = 0; i < n; i++) {
        cin >> intervals[i].first >> intervals[i].second;
    }

    cout << solve(n,y1,y2) << endl;
}