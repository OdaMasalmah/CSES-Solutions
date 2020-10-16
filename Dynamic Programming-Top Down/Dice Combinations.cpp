#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define int long long
#define mod 1000000007
 
int n, dp[1000011];
 
int calc(int s) {
        if (s > n) return 0;
        if (s == n) return 1;
        int &ret = dp[s];
        if (ret != -1) return ret;
        else ret = 0;
        lp(i, 6) ret += calc(s + i + 1)%mod;
        return ret%mod;
}
 
int32_t main(){
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        cin >> n;
        lp(i, n + 2) dp[i] = -1;
        cout << calc(0);
return 0;
}
