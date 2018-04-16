#include "test_framework/generic_test.h"

long long gcd(long long x, long long y)
{
    return y == 0 ? x : gcd(y, x%y);
}

int main(int argc, char* argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x", "y"};
  return GenericTestMain(args, "gcd.tsv", &gcd, DefaultComparator{}, param_names);
}

