#include <algorithm>
#include <vector>
#include <unordered_map>
#include "test_framework/generic_test.h"

using std::vector;

bool HasTwoSum(vector<int> A, int t)
{
  std::sort(begin(A),end(A));
  int i = 0;
  int j = A.size() - 1;
  while (i <= j) {
    int s = A[i] + A[j];
    if (s < t) { i++; }
    if (s > t) { j--; }
    if (s == t) return true;
  }
  return false;
}

bool HasThreeSum(vector<int> A, int t)
{
  std::unordered_map<int,int> m;
  for (auto e : A) {
    m.emplace(e,t-e);
  }
  return std::any_of(begin(m), end(m), [A](auto e){ return HasTwoSum(A,e.second); });
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
