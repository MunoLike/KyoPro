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
  vector<vector<bool>> play_pair(N, vector<bool>(N));

  rep(i, M) {
    i32 k;
    cin >> k;
    vector<i32> p(k);
    rep(j, k) {
      cin >> p[j];
      p[j]--;
    }

    rep(l, k) {
      for (i32 m = l + 1; m < k; m++) {
        play_pair[p[l]][p[m]] = true;
        play_pair[p[m]][p[l]] = true;
      }
    }
  }

  rep(i, N) {
    for (i32 j = i + 1; j < N; j++) {
      if (!play_pair[i][j]) {
        cout << "No\n";
        return 0;
      }
    }
  }

  cout << "Yes\n";
}