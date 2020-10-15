#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 10;

void solve() {
        int n, sum; cin >> n>> sum;
        vector<int> v(n);
        vector<int> dp(sum+ 1, inf); // dp[i]= Min way to get sum = i

        for (auto &i: v) cin >> i;

        dp[0]= 0;
        for (int i= 1; i<= sum; i++) {
                for (auto x: v) {
                        if (i- x>= 0) dp[i]= min(dp[i], dp[i- x]+ 1);
                }
        }

        if (dp[sum]>= inf) cout << "-1\n";
        else cout << dp[sum]<< "\n";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
