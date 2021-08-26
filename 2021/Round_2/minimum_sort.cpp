#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Round 2
	Problem name: Minimum sort
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/0000000000435915/00000000007dc51c
*/

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> PII;
typedef pair<ll, int> PILL;
typedef pair<ll, ll> PLL;

const int MAX_N = 1e5+5;
const int M = 1e6;
const ll INF = (ll)(1e18);
const int inf = 2e9;
const ll MOD = 1000000007LL;

int n;

void solve() {
	for (int i = 1; i < n; i++) {
		cout << "M " << i << " " << n << endl;
		int pos; cin >> pos;
		if (pos != i) {
			cout << "S " << i << " " << pos << endl;
			int res; cin >> res;
		}
	}
	cout << "D" << endl;
	int res; cin >> res;
	assert(res == 1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	int T; cin >> T >> n;
	for (int tt = 1; tt <= T; tt++) {
		solve();
	}
	
	
	
    return 0;
}
