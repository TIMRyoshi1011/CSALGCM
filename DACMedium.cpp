#include <bits/stdc++.h>

#define MAX_N 200000

using namespace std;

int doors[MAX_N][4];

bool credit(int P, int n, int c) {
    long long credit = 0; 

    for (int i = 0; i < n; i++) {
        int A = doors[i][0];
        int B = doors[i][1];
        int C = doors[i][2];
        int D = doors[i][3];

        if (P >= A) { 
            if (credit >= C)
                credit += B + D;
            else
                credit += B;  
        }
    }

    return credit >= c;
}

/*
This function solves a single test case.

Parameters:
n : int - number of doors
c : int - the target credit to reach

Returns the minimum Potestas Power needed to get at least c credit and 
-1 if it is impossible.
*/
int solve(int n, int c) {
    // compute and return answer here
    int M = 0;

    for (int i = 0; i < n; i++)
        M = max(M, doors[i][0]);

    int lo = 0, hi = M;
    int answer = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if (credit(mid, n, c)) {
            answer = mid; 
            hi = mid - 1;
        } 
        else {
            lo = mid + 1;
        }
    }

    return answer;
}

int main() {
    int n, c, result;
    
    cin >> n >> c;
    
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < 4; j++) {
            scanf("%d",&doors[i][j]);
        }
    }
    
    result = solve(n, c);
    if(result == -1) {
        cout << "Defectus Failure" << endl;   
    } else {
        cout << result << endl;
    }
}