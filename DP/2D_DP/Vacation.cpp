// Problem Link:- https://atcoder.jp/contests/dp/tasks/dp_c
// YT Link:- https://www.youtube.com/watch?v=AE39gJYuRog
#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
//By-Ashutosh Kumar Pathak
#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
using namespace std;

mt19937  rng(chrono::steady_clock::now().time_since_epoch().count());

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> oset;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

#define ll long long
#define mod 1000000007
#define all(x) (x).begin(), (x).end()
#define ff first
#define ss second
#define sz(x) ((int)(x).size())
#define pb push_back

int main() {
#ifndef ONLINE_JUDGE
    freopen("errorf.in", "w", stderr);
#endif
    ios::sync_with_stdio(0);
    cin.tie(0);
    int t = 1;
    //cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int points[n + 1][4];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 3; j++)
                cin >> points[i][j];

// dp(i,j)-> maximum happiness that can be earnt from days[i....n] if i performed the task j on the previous day
// final answer -> dp[1][4]
// dp[i][j] = task[i][j]+dp[i+1][j],max over all valid j's
// a valid j means that a task performed on the previous day cannot be perfomed on the current day
        // tabulation code
        int dp[n + 1][5];
        // base case that is the day n
        dp[n][1] = max(points[n][2], points[n][3]);
        dp[n][2] = max(points[n][1], points[n][3]);
        dp[n][3] = max(points[n][1], points[n][2]);
        dp[n][4] = max(points[n][1], max(points[n][2], points[n][3]));
        // compute for all the days from n-1 to 1
        for (int day = n - 1; day >= 1; day--) {
            // performed the task whose number is last on the previous day
            for (int last = 1; last <= 4; last++) {
                int point = 0, maxi = 0;
                // check before doing a task on the current day if it is not done on the previous day
                for (int task = 1; task <= 3; task++) {
                    // if not done the same task on the previous day then do this task on the current day(valid task)
                    if (task != last)
                        // calculate the point for the current day with the given task and then calculate the remaining point for the day[day+1...n]
                        point = points[day][task] + dp[day + 1][task];
                    // take the maximum over all such valid task
                    maxi = max(maxi, point);
                }
                // store the answer for the current day with the given task number last done on the previous day
                dp[day][last] = maxi;
            }
        }
        // output the final answer stored at (1,4) -> max happiness that can be earnt from days[1...n] if i did the task 4(no task) on the previous day
        cout << dp[1][4] << '\n';
    }
    return 0;
}
