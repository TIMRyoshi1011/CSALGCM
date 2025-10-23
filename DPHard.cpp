// NOTE: THIS PROGRAM WAS NOT SUBMITTED IN HACKERRANK

#include <bits/stdc++.h>

#define MAX_N 13

using namespace std;

int edges[MAX_N * (MAX_N - 1) / 2][2];

/*
This function solves a single test case.

Parameters:
n : int - number of locations
m : int - number of connections
k : int - number of sages
l : int - maximum moves allowed

Returns the shortest number of moves possible to visit all sages or 
-1 if it is impossible.
*/
int solve(int n,int m,int k,int l) {
    // compute and return answer here
    vector<vector<int>>graph(n + 1);

    for(int i = 0; i < m; i++) {
        graph[edges[i][0]].push_back(edges[i][1]);
        graph[edges[i][1]].push_back(edges[i][0]);
    }

    int total = 1 << k;

    vector<vector<int>> d(n + 1, vector<int>(total, -1));

    queue<pair<int, int>> q;

    int startMask = 1 << (1 - 1);

    d[1][startMask] = 0;
    q.push({1, startMask});

    int answer = -1;
    int allVisited = (1 << k) - 1;

    while (!q.empty()) {
        auto [node, mask] = q.front();
        q.pop();

        int currentDist = d[node][mask];

        if (mask == allVisited) {
            answer = currentDist;
            break;
        }

        for (int nxt : graph[node]) {
            int nextMask = mask;

            if (nxt <= k) {
                int bit = 1 << (nxt - 1);
                
                if (mask & bit) 
                    continue;
                nextMask |= bit;
            }

            if (d[nxt][nextMask] == -1) {
                d[nxt][nextMask] = currentDist + 1;
                q.push({nxt, nextMask});
            }
        }
    }
    if (answer != -1 && answer <= l) 
        return answer;

    return -1;
}

int main() {
    int n, m, k, l;

    cin >> n >> m >> k >> l;

    for(int i = 0; i < m; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> edges[i][j];
        }
    }

    int result = solve(n,m,k,l);

    if(result == -1) {
        cout << "GANONDORF WINS!\n";
    } else {
        cout << result << endl;
    }
}