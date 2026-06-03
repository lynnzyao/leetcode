#include <string>
#include <bitset>
#include <vector>
#include <queue>


// 2026.05.31
// https://leetcode.com/problems/destroying-asteroids
bool asteroids_destroyed(int mass, std::vector<int>& asteroids) {
  std::sort(asteroids.begin(), asteroids.end());
  unsigned long long m = mass;
  for (int i = 0; i < asteroids.size(); ++i) {
    if (asteroids[i] > m) return false;
    m += asteroids[i];
  }
  return true;
}


// 2025.06.02-2025.06.03
// https://leetcode.com/problems/earliest-finish-time-for-land-and-water-rides-ii/
int earliest_finish_time(
  std::vector<int>& lst, std::vector<int>& ld, 
  std::vector<int>& wst, std::vector<int>& wd
) {
  int le = INT_MAX, we = INT_MAX, lsm = INT_MAX, wsm = INT_MAX;
  for (int i = 0; i < lst.size(); ++i) {
    le = std::min(le, lst[i] + ld[i]);
  }
  for (int i = 0; i < wst.size(); ++i) {
    we = std::min(we, wst[i] + wd[i]);
  }
  for (int i = 0; i < wst.size(); ++i) {
    if (wst[i] < le) {
      lsm = std::min(lsm, le + wd[i]);
    } else {
      lsm = std::min(lsm, wst[i] + wd[i]);
    }
  }
  for (int i = 0; i < lst.size(); ++i) {
    if (lst[i] < we) {
      wsm = std::min(wsm, we + ld[i]);
    } else {
      wsm = std::min(wsm, lst[i] + ld[i]);
    }
  }
  return std::min(lsm, wsm);
}