#include <algorithm>
#include <bit>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <utility>
#include <vector>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;
using vs = vector<string>;

int n;
vi as;
vb visit;

int bfs() {
	auto q = queue<pii>{};
	q.push({ 0, 0 });
	visit[0] = true;

	while (!q.empty()) {
		auto [p, d] = q.front();
		q.pop();

		if (n - 1 == p) {
			return d;
		}

		for (auto i = as[p]; 0 < i; --i) {
			const auto np = p + i;
			if (n <= np) {
				continue;
			}

			if (visit[np]) {
				continue;
			}

			q.push({ np, d + 1 });
			visit[np] = true;
		}
	}

	return -1;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n;

	as = vi(n);
	for (auto&& a : as) {
		cin >> a;
	}

	visit = vb(n, false);
	cout << bfs();

	return 0;
}