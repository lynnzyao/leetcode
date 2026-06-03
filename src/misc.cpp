#include <string>
#include <bitset>
#include <vector>
#include <queue>


// 2026.05.27
// http://leetcode.com/problems/count-the-number-of-special-characters-ii
int num_of_special_chars(std::string word) {
  uint64_t bs = 0, d = 0;
  for (char& c : word) {
    d = c - 'A';
    if (d > 25) {
      if (bs >> (d - 32) & 1ULL) bs &= ~(1ULL << d);
      else bs |= (1ULL << d);
    } else bs |= (1ULL << d);
  }
  return __builtin_popcountll(bs & (bs >> 32));
  std::bitset<64> lc, uc; int d;
  for (char& c : word) {
    d = c - 'A';
    if (d > 25) {
      if (uc.test(d-32)) lc[d-32] = 0;
      else lc[d-32] = 1;
    } else uc.set(d);
  }
  return (lc & uc).count();
}


// 2026.05.29
// https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum
int digit_sum(int n) {
  int r = 0;
  while (n > 9) {
    r += n % 10;
    n /= 10;
  }
  return r + n;
}
int minElement(std::vector<int>& nums) {
  std::priority_queue<int, std::vector<int>, std::greater<int>> q{};
  for (int& n : nums) {
    q.push(digit_sum(n));
  }
  return q.top();
}