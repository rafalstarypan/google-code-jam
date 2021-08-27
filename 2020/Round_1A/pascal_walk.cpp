#include <bits/stdc++.h>
using namespace std;

/*
    Contest: Google Code Jam 2020 Round 1A
    Problem name: Pascal walk
    Problem link: https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd74/00000000002b1353
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

int n;

void solve1() {
    cout << "1 1\n";
    cout << "2 1\n";
    cout << "3 2\n";
    int r = 3;
    int c = 3;
    n -= 4;
    while (n) {
        cout << r << " " << c << '\n';
        n--;
        r++; c++;
    }
}

void solve2() {
    cout << "1 1\n";
    n--;
    int rem = 499;
    int r = 2;
    int c = 1;
    int now = 1;

    while (true) {
        cout << r << " " << c << "\n";
        n -= now;
        rem--;
        if (n <= rem) break;
        r++; c++;
        now++;
    }

    c++;
    while (n) {
        cout << r << " " << c << "\n";
        r++; c++;
        n--;
    }
}

void solve() {
    cin >> n;
    if (n == 1) {
        cout << "1 1\n";
        return;
    }
    if (n == 2) {
        cout << "1 1\n";
        cout << "2 1\n";
        return;
    }
    if (n == 3) {
        cout << "1 1\n";
        cout << "2 1\n";
        cout << "2 2\n";
        return;
    }

    if (n <= 501) {
        solve1();
        return;
    }

    if (n <= 1000) {
        solve2();
        return;
    }


}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ":\n";
        solve();
    }


    return 0;
}
