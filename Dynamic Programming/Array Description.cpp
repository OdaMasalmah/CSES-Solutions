#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;

void solve() {
        int n, m; cin >> n>> m;
        vector<int> v(n);

        for (auto &i: v) cin >> i;
        // dp[i][m]= number of way to reach i with last element = m
        vector<vector<int>> dp(n, vector<int>(m+ 2, 0));

        auto add= [&](int &a, int b) {
                if (a>= mod) a-= mod;
                if (b>= mod) b-= mod;
                a+= b;
                if (a>= mod) a-= mod;
        };
        // base case
        if (v[0]!= 0) add(dp[0][v[0]], 1);

        for (int i= 0; i< n; i++) {
                for (int j= 1; j<= m; j++) {
                        // if the first element = 0
                        if (i== 0) {
                                if (v[i]== 0) add(dp[i][j], 1);
                                continue;
                        }
                        // two or more adjacent zero
                        if (v[i]== 0&& v[i- 1]== 0) {
                                add(dp[i][j], dp[i- 1][j]);
                                add(dp[i][j], dp[i- 1][j- 1]);
                                add(dp[i][j], dp[i- 1][j+ 1]);
                        }
                        // zero after number
                        if (v[i]== 0&& v[i- 1]!= 0&& abs(j- v[i- 1])<= 1) {
                                add(dp[i][j], dp[i- 1][v[i- 1]]);
                        }
                        // zero before number
                        if (v[i]!= 0&& v[i- 1]== 0&& abs(j- v[i])<= 1) {
                                add(dp[i][v[i]], dp[i- 1][j]);
                        }
                        // non zero after non zero
                        if (v[i]!= 0&& v[i- 1]!= 0&& abs(v[i]- v[i- 1])<= 1) {
                                add(dp[i][v[i]], dp[i- 1][j]);
                        }
                }

        }

        int ans= 0;
        for (int i= 1; i<= m; i++) add(ans, dp[n- 1][i]);

        cout << ans<< "\n";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
