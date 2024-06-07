#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(a) (a).begin(), (a).end()
const i32 dy[] = {-1, 0, 1, 0, -1, -1, 1, 1};
const i32 dx[] = {0, 1, 0, -1, -1, 1, 1, -1};

inline int64_t div_floor(int64_t a, int64_t b) {
  if (b < 0) {
    a *= -1;
    b *= -1;
  }
  if (a < 0) {
    return (a + 1) / b - 1;
  } else {
    return a / b;
  }
}

inline int64_t div_ceil(int64_t a, int64_t b) {
  return div_floor(a + b - 1, b);
}

int main() {
  i32 N, M;
  cin >> N >> M;

  vector<vector<i32>> linked(N, vector<i32>());
  rep(j, M) {
    i32 p1, p2;
    cin >> p1 >> p2;
    p1--;
    p2--;
    linked[p1].push_back(p2);
    linked[p2].push_back(p1);
  }

  rep(i, N) {
    sort(all(linked[i]));
    cout << linked[i].size();
    for (auto&& x : linked[i]) {
      cout << ' ' << x + 1;
    }
    cout << endl;
  }
}