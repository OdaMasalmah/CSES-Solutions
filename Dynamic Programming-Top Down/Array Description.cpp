#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define mod 1000000007
#define int long long

const int inf= 1e9+ 9;
int n, m, dp[555][100001];
vector<int> v;

bool df(int a, int b) {
        return (max(a, b)- min(a, b)<= 1? 1: 0);
}

int calc(int idx, int p) {
        if (idx== n) {
                return 1;
        }
        if (v[idx]!= 0&&!df(v[idx], p)) return 0;

        int &ret= dp[p][idx];
        if (ret!= -1) return ret;
        else ret= 0;

        if (v[idx]!= 0) {
                ret+= ( calc(idx+ 1, v[idx])%mod );
        } else {
                if (idx== 0) {
                        lp(i, m) {
                                ret+= ( calc(idx+ 1, i+ 1)% mod );
                        }
                } else
                        lp(i, m) {
                                if (df(p, i+ 1))
                                        ret+= ( calc(idx+ 1, i+ 1)% mod );
                        }

        }
        return ret% mod;
}

void solve() {
        cin >> n>> m;
        v.resize(n);
        lp(i, n) cin >> v[i];
        lp(i, n+ 1) lp(j, 501) dp[j][i]= -1;
        cout << calc(0, v[0])% mod;
}

int32_t main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
