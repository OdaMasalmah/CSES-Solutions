#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;

void solve() {
        int n; cin >> n;
        vector<int> dp(n+ 1); // dp[i]= number of way to get i from throwing {1,... 6}

        auto add= [&](int &a, int b) {
                if (a>= mod) a-= mod;
                if (b>= mod) b-= mod;
                a+= b;
                if (a>= mod) a-= mod;
        };

        dp[0]= 1;
        for (int i= 1; i<= n; i++) {
                for (int x= 1; x<= 6; x++) {
                        if (i- x>= 0) add(dp[i], dp[i- x]);
                }
        }

        cout << dp[n]<< "\n";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
