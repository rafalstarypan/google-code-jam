#include <bits/stdc++.h>
using namespace std;

/*
	Contest: Google Code Jam 2021 Qualification Round
	Problem name: Reversort
	Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000043580a/00000000006d0a5c
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
int a[105];

int findMini(int start) {
	int res = start;
	int mini = a[start];
	for (int i = start+1; i <= n; i++) {
		if (a[i] < mini) {
			mini = a[i];
			res = i;
		}
	}
	return res;
}

void reverseArr(int l, int r) {
	while (l < r) {
		swap(a[l], a[r]);
		l++; r--;
	}
}

void solve() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	int ans = 0;
	for (int i = 1; i < n; i++) {
		int pos = findMini(i);
		ans += pos - i + 1;
		reverseArr(i, pos);
	}
	
	cout << ans << '\n';
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
