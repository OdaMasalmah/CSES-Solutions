#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define int long long
#define mod 1000000007
 
int dp[1000011];
 
int calc(int nm) {
        if (nm < 0) return 1e9;
        if (nm == 0) return 0;
        int &ret = dp[nm];
        if (ret != -1) return ret;
        else ret = 1e9;
        int m = nm;
        while (m) {
                int dg = m % 10;
                m /= 10;
                if (dg != 0) ret = min(ret, calc(nm - dg) + 1);
        }
        return ret;
}
 
int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int n; cin >> n;
        lp(i, n + 2) dp[i] = -1;
        cout << calc(n);
return 0;
}
