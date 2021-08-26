#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Qualification Round
	Problem name: Median sort
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d1284
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

int T, N, Q;

vector<int> findCand(vector<int> a) {
	while (a.size() > 2) {
		int x = a.back();
		a.pop_back();
		int y = a.back();
		a.pop_back();
		int z = a.back();
		a.pop_back();
		
		cout << x << ' ' << y << ' ' << z << endl;
		int res; cin >> res;
		
		if (x == res) {
			a.push_back(y);
			a.push_back(z);
		}
		
		if (y == res) {
			a.push_back(x);
			a.push_back(z);
		}
		
		if (z == res) {
			a.push_back(x);
			a.push_back(y);
		}
	}
	return a;
}

vector<int> shrinkArr(vector<int> a, int x, int y) {
	vector<int> res;
	for (int i: a) {
		if (i == x || i == y) continue;
		res.push_back(i);
	}
	return res;
}

void solve() {
	vector<int> a;
	for (int i = 1; i <= N; i++) {
		a.push_back(i);
	}
	deque<int> ans(N);
	int L = 0;
	int R = N-1;
	
	vector<int> cand = findCand(a);
	a = shrinkArr(a, cand[0], cand[1]);
	ans[L] = cand[0];
	ans[R] = cand[1];
	L++; R--;
	
	while (!a.empty()) {
		cand = findCand(a);
		a = shrinkArr(a, cand[0], cand[1]);
		cout << ans[0] << ' ' << cand[0] << ' ' << cand[1] << endl;
		int res; cin >> res;
		assert(res != -1);
		ans[L] = res;
		if (res == cand[0]) {
			ans[R] = cand[1];
		} else {
			ans[R] = cand[0];
		}
		L++; R--;
	}
	
	for (int i = 0; i < N; i++) {
		cout << ans[i] << ' ';
	}
	cout << endl;
	int res; cin >> res;
	assert(res != -1);
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
	
	cin >> T >> N >> Q;
	for (int tt = 1; tt <= T; tt++) {
		solve();
	}
	
	
    return 0;
}
