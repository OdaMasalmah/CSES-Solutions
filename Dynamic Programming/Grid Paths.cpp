#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;

void solve() {
        int n; cin >> n;
        vector<string> v(n);

        for (auto &i: v) cin >> i;

        auto add= [&](int &a, int b) {
                if (a>= mod) a-= mod;
                if (b>= mod) b-= mod;
                a+= b;
                if (a>= mod) a-= mod;
        };
        // dp[r][c] number of way to reach r, c cell
        vector<vector<int>> dp(n, vector<int>(n, 0));
        dp[0][0]= 1; // only one path from the start

        for (int i= 0; i< n; i++) {
                for (int j= 0; j< n; j++) {
                        if (v[i][j]== '*') {
                                dp[i][j]= 0;// no way to come from it
                                continue;
                        }
                        if (i- 1>= 0) add(dp[i][j], dp[i- 1][j]);
                        if (j- 1>= 0) add(dp[i][j], dp[i][j- 1]);
                }
        }

        cout << dp[n- 1][n- 1]<< "\n";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
