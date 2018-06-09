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
    if      (s < t) { i++; }
    else if (s > t) { j--; }
    else return true;
  }
  return false;
}

bool HasThreeSum(vector<int> A, int t)
{
  return std::any_of(begin(A), end(A), [A,t](auto e){ return HasTwoSum(A,t-e); });
}

int main(int argc, char* argv[]) {
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"A", "t"};
  return GenericTestMain(args, "three_sum.cc", "three_sum.tsv", &HasThreeSum,
                         DefaultComparator{}, param_names);
}
