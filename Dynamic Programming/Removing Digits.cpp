#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;

void solve() {
        int n; cin >> n;
        vector<int> dp(n+ 1, inf); // dp[i]= Min number to get i using its digits

        auto get= [](int nm)->vector<int>{
                vector<int> d;
                while (nm> 0) {
                        int rem= nm% 10;
                        d.push_back(rem);
                        nm/= 10;
                }
                return d;
        };

        dp[0]= 0;
        for (int i= 1; i<= n; i++) {
                vector<int> val= get(i);
                for (auto x: val) {
                        dp[i]= min(dp[i], dp[i- x]+ 1);
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
