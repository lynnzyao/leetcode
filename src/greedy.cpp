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