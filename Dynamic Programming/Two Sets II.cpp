#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;

void solve() {
        int n; cin >> n;
        vector<int> v(n);

        for (int i= 1; i<= n; i++) v[i- 1]= i;

        auto add= [&](int &a, int b) {
                if (a>= mod) a-= mod;
                if (b>= mod) b-= mod;
                a+= b;
                if (a>= mod) a-= mod;
        };

        int sum= n* (n+ 1)/ 2;
        if (sum% 2!= 0) {
                cout << "0\n";
        } else {
                sum/= 2;
                // dp[sum][i]= number of way to get sum from ith element
                vector<vector<int>> dp(sum+ 1, vector<int>(n+ 1, 0));

                for (int i= 1; i<= sum; i++) {
                        for (int j= 0; j< n; j++) {
                                // one element get the sum
                                if (j== 0&& i- v[j]== 0) {
                                        add(dp[i][j], 1);
                                }
                                if (j< 1) continue;
                                // add using this element
                                if (i- v[j]>= 0) {
                                        add(dp[i][j], dp[i- v[j]][j- 1]);
                                }
                                // add without using this element
                                add(dp[i][j], dp[i][j- 1]);
                        }
                }

                cout << dp[sum][n- 1]<< "\n";
        }

}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
