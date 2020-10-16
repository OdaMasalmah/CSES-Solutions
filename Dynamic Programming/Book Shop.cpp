#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;

void solve() {
        int n, x; cin >> n>> x;
        vector<pair<int, int>> vp(n);

        for (int i= 0; i< n; i++) cin>> vp[i].first;
        for (int i= 0; i< n; i++) cin>> vp[i].second;

        sort(all(vp));
        // dp[x][i]= max num to get x using first 0 to i
        vector<vector<int>> dp(x+ 1, vector<int> (n, 0));

        for (int i= 1; i<= x; i++) {
                for (int j= 0; j< n; j++) {
                        if (i- vp[j].first< 0) break; // any this after this can't take
                        // take first element if can
                        if (i- vp[j].first>= 0&& j== 0)
                                dp[i][j]= max(dp[i][j], dp[i][j]+ vp[j].second);
                        // take j and max from j- 1 and x- price[j]
                        if (i- vp[j].first>= 0&& j- 1>= 0)
                                dp[i][j]= max(dp[i][j], dp[i- vp[j].first][j- 1]+ vp[j].second);
                        // max from previous j
                        if (j- 1>= 0) dp[i][j]= max(dp[i][j], dp[i][j- 1]);
                }
        }

        cout << dp[x][n- 1]<< "\n";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
