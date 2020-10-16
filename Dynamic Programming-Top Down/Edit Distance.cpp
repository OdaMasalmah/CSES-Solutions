#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;
string a, b;
int n, m;
ll dp[5001][5001];

ll calc(int i, int j) {

        if (i>= n) return m- j;
        if (j>= m) return n- i;

        ll &ret= dp[i][j];
        if (ret!= -1) return ret;
        else ret= 1e18;

        if (i< n&& j< m&& a[i]== b[j]) {
                ret= min(ret, calc(i+ 1, j+ 1));
        } else {
                ret= min(ret, calc(i+ 1, j)+ 1);
                ret= min(ret, calc(i, j+ 1)+ 1);
                ret= min(ret, calc(i+ 1, j+ 1)+ 1);
        }
        return ret;
}

void solve() {
        cin >> a>> b;
        n= a.size(), m= b.size();
        int mx= max(n, m);

        lp(i, mx+ 1)lp(j, mx+ 1) dp[i][j]= -1;

        cout << calc(0, 0)<< "\n";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
