#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;

void solve() {
        string s1, s2; cin >> s1>> s2;
        int n= s1.size(), m= s2.size();
        // dp[i][j]= Min number of operation to make s1[0... i]== s2[0... j]
        vector<vector<int>> dp(n+ 1, vector<int> (m+ 1, inf));


        for (int i= 0; i<= n; i++) dp[i][0]= i; // empty with s1
        for (int i= 0; i<= m; i++) dp[0][i]= i; // empty with s2
        dp[0][0]= 0; // empty with empty

        for (int i= 1; i<= n; i++) {
                for (int j= 1; j<= m; j++) {
                        if (s1[i- 1]== s2[j- 1]) {
                                // two equal char
                                dp[i][j]= dp[i- 1][j- 1];
                        } else {
                                /*
                                        Three operation
                                        1- ADD -> dp[i][j]= dp[i][j- 1]
                                        2- REMOVE -> dp[i][j]= dp[i- 1][j]
                                        3- REPLACE -> dp[i][j]= dp[i- 1][j- 1]
                                */
                                dp[i][j]= min({dp[i][j], dp[i][j- 1]+ 1, dp[i- 1][j]+ 1, dp[i- 1][j- 1]+ 1});
                        }
                }
        }

        cout << dp[n][m]<< "\n";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
