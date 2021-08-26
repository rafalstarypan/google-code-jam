#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Qualification Round
	Problem name: Reversort engineering
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d12d7
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
const int inf = 1e9;
const ll MOD = 1000000007LL;

int n, C;

void reverseArr(vector<int>& a, int l, int r) {
	while (l < r) {
		swap(a[l], a[r]);
		l++; r--;
	}
}

void solve() {
	cin >> n >> C;
	if (C < n-1 || C >= (n*(n+1))/2) {
		cout << "IMPOSSIBLE\n";
		return;
	}
	
	vector<int> ans(n+1, -1);
	int last = 0;
	C -= n-1;
	int now = n-1;
	bool where = true;
	int l = 1;
	int r = n;
	int toPut = 1;
	
	while (C > 0) {
		if (C >= now) {
			C -= now;
			if (where) {
				ans[r] = toPut;
				last = r;
				r--;
			} else {
				ans[l] = toPut;
				last = l;
				l++;
			}
			toPut++;
			where ^= 1;
			now--;
			continue;
		}
		
		int xd = now - C;
		C = 0;
		if (where) {
			ans[r-xd] = toPut;
			last = r-xd;
		} else {
			ans[l+xd] = toPut;
			last = l+xd;
		}
		toPut++;
		where ^= 1;
	}
	
	if (where) {
		for (int i = last+1; i <= n; i++) {
			if (ans[i] != -1) continue;
			ans[i] = toPut;
			toPut++;
		}
		for (int i = last-1; i >= 1; i--) {
			if (ans[i] != -1) continue;
			ans[i] = toPut;
			toPut++;
		}
	} else {
		for (int i = last-1; i >= 1; i--) {
			if (ans[i] != -1) continue;
			ans[i] = toPut;
			toPut++;
		}
		for (int i = last+1; i <= n; i++) {
			if (ans[i] != -1) continue;
			ans[i] = toPut;
			toPut++;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
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
