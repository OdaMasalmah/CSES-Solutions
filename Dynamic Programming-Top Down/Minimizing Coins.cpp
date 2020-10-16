#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define mod 1000000007
#define int long long

int n, m, ca[1000000];
vector<int> v;

int dp(int k) {
        if (k== m) return 0;
        if (k> m) return 1e18;
        int &ret= ca[k];
        if (ret!= -1) return ret;
        else ret= 1e18;
        lp(i, n) {
               ret= min( dp(k+ v[i])+ 1, ret );
        }
        return ret;
}

void solve() {
        cin >> n>> m;
        v.resize(n);
        lp(i, 1000000) ca[i]= -1;
        lp(i, n) cin >> v[i];
        cout << (dp(0)== 1e18? -1: dp(0));
}

int32_t main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
