// Ahmed Samir Hamed
// Revision DP.
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

int dp_power[10000][100];

int power_calc_mem(int x, int y) {
    if (y == 1) return dp_power[x][y] = x;
    if (y <= 0) return 1;
    if (dp_power[x][y] != -1) return dp_power[x][y];
    return dp_power[x][y] = x * x * power_calc_mem(x, y-2);
}

void read_input_power() {
    memset(dp_power, -1, sizeof(dp_power));
    int x, y;
    cin >> x >> y;
    cout << power_calc_mem(x, y) << endl;
}

/*
Problem Pre A: Cutted Segments
========================
Given an integer N denoting the Length of a line segment.
you need to cut the line segment in such a way that the cut length of a line
segment each time is integer either x , y or z.
and after performing all cutting operation the total number of cut segments must be maximum.
 */
int dp_cutted_segments[10000];
int cuts[3] = {};
int cutted_segments(int l) {
    if (l == 0) return 0;
    if (l < 0 || (l < cuts[0] && l < cuts[1] && l < cuts[2])) return (1<<32 -1);
    if (dp_cutted_segments[l] != -1) return dp_cutted_segments[l];
    dp_cutted_segments[l] = (1<<32 -1);
    lp (i, 3) {
        if(l - cuts[i] >= 0) {
            dp_cutted_segments[l] = max(dp_cutted_segments[l], 1 + cutted_segments(l - cuts[i]));
        }
    }
    return dp_cutted_segments[l];
}

void read_input_cutted_segments(){
    int t;
    cin >> t;
    while (t--) {
        memset(dp_cutted_segments, -1, sizeof(dp_cutted_segments));
        int l;
        cin >> l;
        cin >> cuts[0] >> cuts[1] >> cuts[2];
        cout << cutted_segments(l) << endl;
    }
}


/*
Problem A: Rod Cut
========================
Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n.
Determine the maximum value obtainable by cutting up the rod and selling the pieces. For example,
if length of the rod is 8 and the values of different pieces are given as following,
then the maximum obtainable value is 22 (by cutting in two pieces of lengths 2 and 6)

 */
int dp_mem_cut_rod[10000];
int dp_rod_cut[10000];

int rod_cut(int l) {
    if (l == 0) return 0;
    if (l <= 0) return 1<<32 -1;
    if (dp_mem_cut_rod[l] != -1) return dp_mem_cut_rod[l];

    int &ret = dp_mem_cut_rod[l];
    ret = dp_rod_cut[l];
    for (int j = 0; j < l; j++) {
        ret = max(ret, rod_cut(l-j) + rod_cut(j));
    }
    return ret;
}

void read_input_rod_cut() {
    memset(dp_mem_cut_rod, -1, sizeof(dp_mem_cut_rod));

    int n;
    cin >> n;

    lp (i, n) {
        cin >> dp_rod_cut[i+1];
    }

    dp_rod_cut[0] = 0;
    for (int i = 1; i <= n; i++) {
        int max_num = 1<<32 - 1;
        for (int j = 0; j <= i; j++) {
            max_num = max(max_num, dp_rod_cut[i-j] + dp_rod_cut[j]);
        }
        dp_rod_cut[i] = max_num;
    }
    cout << "Tabulation Result: Maximum obtained from rod cutting of length " << n << " is " << dp_rod_cut[n] << endl;
    cout << "Memoization Result: Maximum obtained from rod cutting of length " << n << " is " << rod_cut(n) << endl;
}

/* Problem Pre B: [Matrix Chain Multiplication]
 Given a sequence of matrices, find the most efficient way to multiply these matrices together.
 The problem is not actually to perform the multiplications,
 but merely to decide in which order to perform the multiplications.
 There are many options to multiply a chain of matrices because matrix multiplication is associative
 i.e. no matter how one parenthesize the product,
 the result will be the same.
 */

void read_input_matrix_chain_mul() {

}

/* Problem C: Longest Common Subsequence
 * Given two sequences, find the length of longest subsequence present in both of them. Both the strings are of uppercase.
 * Naive Solution: O(2^n) and the DP sol is O(n^2)
 */
int la, lb;
string a, b;
int dp_lcs[1000][1000];
int dp_lcs_mem[1000][1000];

// Old Not Working
//int dp_lcs_solve(string a, string b) {
//    bool found = false;
//    for(int i = 0; i < lb; i++) {
//        found = found || (a[0] == b[i]);
//        dp_lcs[0][i] = found;
//    }
//    found = false;
//    for(int i = 0; i < la; i++) {
//        found = found || (b[0] == a[i]);
//        dp_lcs[i][0] = found;
//    }
//    for (int i = 1; i < la; i++) {
//        for (int j = 1; j < lb; j++) {
//            dp_lcs[i][j] = max(dp_lcs[i-1][j], dp_lcs[i][j-1]) + (a[i] == b[j]);
//        }
//    }
//    return dp_lcs[la-1][lb-1];
//}

int dp_lcs_solve(string a, string b) {
    bool found = false;
    for(int i = 0; i < lb; i++) {
        dp_lcs[0][i] = 0;
    }

    found = false;
    for(int i = 0; i < la; i++) {
        dp_lcs[i][0] = 0;
    }

    for (int i = 1; i <= la; i++) {
        for (int j = 1; j <= lb; j++) {
            if(a[i] == b[j])
                dp_lcs[i][j] = 1 + dp_lcs[i-1][j-1];
            else
                dp_lcs[i][j] =  max(dp_lcs[i-1][j], dp_lcs[i][j-1]);
        }
    }

    return dp_lcs[la][lb];
}

int dp_lcs_mem_solve(int i, int j) {
    if (i <= 0 || j <= 0) return 0;
    // Remove this line to be a naive soultion.
    if (dp_lcs_mem[i][j] != -1) return dp_lcs_mem[i][j];
    int &ret = dp_lcs_mem[i][j];
    if (a[i] == b[j]) {
        return ret = 1 + dp_lcs_mem_solve(i-1, j-1);
    }
    // 3'eir keda hat el maximum between the 2 possible paths (hold the current char in a and test with the next char in b
    // , And hold the current char in b and test with the next char in a).
    return ret = max(dp_lcs_mem_solve(i, j-1), dp_lcs_mem_solve(i-1, j));
}

void read_input_lcs() {
    int t;
    cin >> t;
    while (t--) {
        memset(dp_lcs, 0, sizeof(dp_lcs));
        memset(dp_lcs_mem, -1, sizeof(dp_lcs_mem));

        cin >> la >> lb;
        string x, y;
        cin >> x >> y;
        a = " " + x;
        b = " " + y;
        cout << "Tabulation Result: " << " is " << dp_lcs_solve(a, b) << endl;
        cout << "Memoization Result: " << " is " << dp_lcs_mem_solve(la, lb) << endl;
//         Testing
//        lp(i, la) {
//            lp(j, lb) {
//                cout << dp_lcs[i][j] << " ";
//            }
//            cout << endl;
//        }
    }
}


int main() {
    read_input_lcs();
    return 0;
}








// Ahmed Samir Hamed
// Revision Greedy / DP/ Graphs.
#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
using namespace std;
#define lp(i, n)        for(int i=0;i<(int)(n);++i)

/* Problem Job Sequencing
 */
struct job {
    int deadline;
    int profit;
    job(int a, int b) : deadline(a), profit(b) {}
    bool operator < (const job& j) const {
        return profit < j.profit;
    }
};

void job_sequencing() {
    int n;
    cin >> n;

    priority_queue<job> jobs;
    vector<int> deadlines(1000, 0);
    int total_profit = 0;

    lp(i, n) {
        int d, j;
        cin >> d >> j;
        jobs.push(job(d, j));
    }

    while (!jobs.empty()) {
        job j = jobs.top(); jobs.pop();
        for (int i = j.deadline; i >= 0 ; i--) {
            if (deadlines[i] == 0) {
                total_profit += j.profit;
                deadlines[i] = j.profit;
            }
        }
    }

    // The total profit is total_profit
}


/* Problem: Greedy Algorithm to find Minimum number of Coins
 * Given V, return the minumum number of coin change for thais value  { 1, 2, 5, 10, 20, 50, 100, 500, 1000}
 */
void solve_coins() {
    int n;
    cin >> n;
    int res[9] = {};
    int coins[] = { 1, 2, 5, 10, 20, 50, 100, 500, 1000};

    int i = 8;
    while (n > 0 ) {
        while (coins[i] <= n) {
            res[i]++;
            n -= coins[i];
        }
        i--;
    }

    // Print the array.
}


/* Problem DP Longest Increasing subsequence.
 *
 *
 */
void lis() {
    int t;
    cin >> t;
    while(t--) {
        int n;
        cin >> n;
        if (n == 0) {
            cout << 0 << endl;
            continue;
        }
        vector<int> nums;
        lp (i, n) {
            int x;
            cin >> x;
            nums.push_back(x);
        }

        vector<int> dp_lis(n, 0);

        for (int i = 0; i < n; i++) {
            int mx = 0;
            for (int j = i - 1; j >= 0; j--) {
                if (nums[j] < nums[i]) {
                    mx = max(mx, dp_lis[j]);
                }
            }
            dp_lis[i] = mx + 1;
        }

//        lp(i, n) {
//            cout << dp_lis[i] << " ";
//        }
//        cout << endl;
        // Print the result the longest increasing sub sequence
        cout << *max_element(dp_lis.begin(), dp_lis.end()) << endl;
    }
}

/*
 * Problem Edit Distance.
 */

int main() {
    lis();
    return 0;
}