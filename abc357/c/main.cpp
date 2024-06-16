#include <bits/stdc++.h>

#include <atcoder/all>
using namespace std;
using i32 = int32_t;
using i64 = int64_t;
using u32 = uint32_t;
using u64 = uint64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (i32 i = 1; i <= (n); (i)++)
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
inline S chmax(S& a, T b) {
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
  i32 N;
  cin >> N;

  i32 gsize = 1;
  rep(i, N) gsize *= 3;

  vector<string> area(gsize, string(gsize, '#'));
  i32 cur = N;
  while (cur >= 1) {
    i32 c = static_cast<i32>(pow(3, cur - 1));

    i32 n = gsize / c / 3;

    for (i32 y = 0; y < n; y++) {
      for (i32 x = 0; x < n; x++) {
        for (i32 i = 0; i < c; i++) {
          for (i32 j = 0; j < c; j++) {
            i32 ad = static_cast<i32>(pow(3, cur));
            area[ad * y + c + i][ad * x + c + j] = '.';
          }
        }
      }
    }
    --cur;
  }

  for (auto&& s : area) {
    cout << s << endl;
  }
  return 0;
}