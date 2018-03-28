#include "test_framework/generic_test.h"
#include <bitset>
#include <limits>

short CountBits(unsigned int x)
{
    std::bitset<std::numeric_limits<decltype(x)>::digits> s(x);
    return s.count();
}

int main(int argc, char* argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "count_bits.tsv", &CountBits,
                         DefaultComparator{}, param_names);
}
