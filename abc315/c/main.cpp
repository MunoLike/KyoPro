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

template <class S, class T>
inline S prevent_oor(S a, const T b) {
  a %= b;
  if (a < 0) {
    a += b;
  }
  return a;
}

template <class S, class T>
inline S chmax(S &a, T b) {
  if (a < b) {
    a = b;
  }
  return a;
}

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
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  i32 N;
  cin >> N;
  vector<pair<i32, i32>> flavor;

  rep(i, N) {
    i32 f, s;
    cin >> f >> s;
    flavor.emplace_back(s, f);
  }

  sort(all(flavor));

  i32 first_tasty = flavor.back().first;
  i32 ans = 0;
  i32 first_flavor = flavor.back().second;

  for (i32 i = 0; i < N - 1; ++i) {
    if (flavor[i].second == first_flavor) {
      ans = max(ans, flavor[i].first / 2 + first_tasty);
    } else {
      ans = max(ans, flavor[i].first + first_tasty);
    }
  }

  cout << ans << endl;
}