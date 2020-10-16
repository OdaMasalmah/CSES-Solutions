#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define mod 1000000007
#define int long long

const int inf= 1e9+ 9;
int n, dp[1001][1001];
string str[1001];

int calc(int x, int y) {
        if(x>= n|| y>= n) return 0;
        if (x== n-1&& y== n-1&& str[x][y]== '.') return 1;
        if (str[x][y]== '*') return 0;
        int &ret= dp[x][y];
        if (ret!= -1) return ret;
        else ret= 0;
        ret+= calc(x+ 1, y)% mod;
        ret+= calc(x, y+ 1)% mod;
        return ret;
}

void solve() {
        cin >> n;
        lp(i, n) lp(j, n) dp[i][j]= -1;
        lp(i, n) cin >> str[i];

        cout << calc(0, 0)% mod;
}

int32_t main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
