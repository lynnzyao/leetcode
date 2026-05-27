#include <string>
#include <bitset>


// http://leetcode.com/problems/count-the-number-of-special-characters-ii/description/
// int num_of_special_chars(std::string word) {
//   uint64_t bs = 0, d = 0;
//   for (char& c : word) {
//     d = c - 'A';
//     if (d > 25) {
//       if (bs >> (d - 32) & 1ULL) bs &= ~(1ULL << d);
//       else bs |= (1ULL << d);
//     } else bs |= (1ULL << d);
//   }
//   return __builtin_popcountll(bs & (bs >> 32));
//   std::bitset<64> lc, uc; int d;
//   for (char& c : word) {
//     d = c - 'A';
//     if (d > 25) {
//       if (uc.test(d-32)) lc[d-32] = 0;
//       else lc[d-32] = 1;
//     } else uc.set(d);
//   }
//   return (lc & uc).count();
// }

