#include <bits/stdc++.h>
using namespace std;
#define all(v) (v).begin(), (v).end()
#define lp(i, n) for (int i = 0; i < (n) ; ++i)
#define sz(v) (int)(v).size()
#define mod 1000000007

using ll= long long;
const int inf= 1e9+ 9;
int n, dp[101][100011];
vector<int> v;
set<int> st;

int calc(int ind, int sm) {
        if (ind== n) {
                if (sm== 0) return 0;
                else { st.insert(sm); return 1; }
        }

        int &ret= dp[ind][sm];
        if (ret!= -1) return ret;
        else ret= 0;

        ret+= calc(ind+ 1, sm+ v[ind]);
        ret+= calc(ind+ 1, sm);
        return ret;
}

void solve() {
        cin >> n;
        v.resize(n);
        lp(i, n+ 1) lp(j, 100011) dp[i][j]= -1;
        lp(i, n) cin >> v[i];

        calc(0, 0);
        cout << st.size()<< "\n";
        for (auto x: st) cout << x<< " ";
}

int main() {
ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
        int T= 1;
        while ( T-- ) solve();
        return 0;
}
