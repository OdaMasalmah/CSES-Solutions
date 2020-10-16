#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;

vector<ll> v;
ll dp[5001][5001][2];

ll calc(int i, int j, bool pl) {
        if (i> j) {
                return 0;
        }

        ll &ret1= dp[i][j][pl];
        if (ret1!= -1) return ret1;

        if (pl) {
                ret1= -1e18;
                ret1= max(ret1, calc(i+ 1, j, pl^1)+ v[i]);
                ret1= max(ret1, calc(i, j- 1, pl^1)+ v[j]);
                return ret1;
        }else {
                ret1= 1e18;
                ret1= min(ret1, calc(i+ 1, j, pl^1));
                ret1= min(ret1, calc(i, j- 1, pl^1));
                return ret1;
        }
}

void solve() {
        int n; cin >> n;
        v.resize(n);

        for (auto& i: v) cin >> i;

        memset(dp, -1, sizeof(dp));

        cout << calc(0, n- 1, 1);
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
