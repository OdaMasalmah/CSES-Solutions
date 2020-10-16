#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int N= 1e5+ 5;
const int inf= 1e9+ 9;

void solve() {
        int n; cin >> n;
        vector<int> v(n);

        for (auto &i: v) cin >> i;
        // dp[x][i]= if can get sum x using first ith element
        vector<vector<bool>> dp(N, vector<bool>(n, 0));

        // 0 sum from any element
        for (int i= 0; i< n; i++) dp[0][i]= 1;

        sort(all(v));

        for (int i= 1; i< N; i++) {
                for (int j= 0; j< n; j++) {
                        if (j== 0&& i- v[j]== 0) {
                                dp[i][j]= 1;
                        }
                        if (j== 0) continue;
                        // take the coin and show the i- coin using j- 1 element
                        if (i- v[j]>= 0) dp[i][j]= (dp[i- v[j]][j- 1]| dp[i][j]);
                        // if i get this sum using j- 1 element i can get using j
                        dp[i][j]= (dp[i][j]| dp[i][j- 1]);
                }
        }

        set<int> st;
        for (int i= 1; i< N; i++) {
                if (dp[i][n- 1]) st.insert(i);
        }

        cout << st.size()<< "\n";
        for (auto X: st) cout << X<< " ";
        cout << "\n";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
