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
  i32 R, C;
  cin >> R >> C;

  vector<string> area(R);
  rep(i, R) {
    cin >> area[i];
  }
  vector<string> m_area(area);

  rep(i, R) rep(j, C) {
    i32 num = area[i][j] - '0';
    if (0 < num && num <= 9) {
      m_area.at(i).at(j) = '.';
      rep(k, R) rep(l, C) {
        if (abs(i - k) + abs(j - l) <= num) {
          m_area.at(k).at(l) = '.';
        }
      }
    }
  }

  for (auto&& s : m_area) cout << s << endl;
}