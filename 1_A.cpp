#include <bits/stdc++.h>
#include <stdio.h>
#include <ctime>
#include <random>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll, ll> pll;
 
#define f first
#define s second
 
const ll INF = 1e18;
 
void acceleration() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}
 
void solve();
 
int main() {
    acceleration();
    solve();
}
 
void solve() {
    ll n, k, x, mx = -INF;
    cin >> n >> k;
    map<ll, ll> m;
 
    if (k == 1) {
        cout << n << endl;
        return;
    }
 
    ll res = 0;
 
    for (int i = 0; i < n; ++i) {
        cin >> x;
        m[x] = 1;
        mx = max(mx, x);
    }
 
    for (auto i = m.begin(); i != m.end(); ++i) {
        ll x = (*i).first;
        ll y = (*i).second;
 
        if (x * k <= mx && m.count(x * k)) {
            //cout << x * k << endl;
            m[x * k] = y + 1;
        } else 
            res += (y + 1) / 2;
    }
    cout << res << endl;
}