#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Round 1B
	Problem name: Broken Clock
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/0000000000435baf/00000000007ae694
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const ll M = (ll)(1e9);
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

ll getHour(ll x) {
	ll res = x / M;
	res /= 3600;
	return res;
}

ll getMinute(ll x) {
	ll res = x / 12;
	res /= M;
	res /= 60;
	return res;
}

ll getSecond(ll x) {
	ll res = x / 720;
	res /= M;
	return res;
}

bool validHour(ll h) {
	return h >= 0 && h < 12;
}

bool validMinute(ll m) {
	return m >= 0 && m < 60;
}

bool validSecond(ll s) {
	return s >= 0 && s < 60;
}

bool validNano(ll n) {
	return n >= 0 && n < M;
}

void solve() {
	vector<ll> a(3);
	cin >> a[0] >> a[1] >> a[2];
	
	for (ll sto = 0LL; sto < 360; sto += 30) {
		
		ll toAdd = sto * 12 * M * 10;
		
		for (ll h = 0LL; h < 12; h++) {
			for (ll m = 0LL; m < 60; m++) {
				for (ll s = 0LL; s < 60; s++) {
					
					map<ll, int> mp;
					for (ll i: a) mp[i]++;
					
					ll nano = h*3600*M + m*60*M + s*M;
					ll H = nano + toAdd;
					
					nano = m*60*M + s*M;
					ll Mi = 12 * nano + toAdd;
					
					nano = s*M;
					ll S = 720 * nano + toAdd;
					
					bool ok = true;
					if (mp[H] > 0) mp[H]--;
					else ok = false;
					
					if (mp[Mi] > 0) mp[Mi]--;
					else ok = false;
					
					if (mp[S] > 0) mp[S]--;
					else ok = false;
					
					if (ok) {
						cout << h << " " << m << " " << s << " 0\n";
						return;
					}
				}
			}
		}
		
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int T; cin >> T;
	for (int tt = 1; tt <= T; tt++) {
		cout << "Case #" << tt << ": ";
		solve();
	}
	
	
    return 0;
}
