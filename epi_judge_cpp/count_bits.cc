#include "test_framework/generic_test.h"
#include <bitset>
#include <limits>

namespace HO
{
    template <typename T>
    short CountBits(T x)
    {
        std::bitset<std::numeric_limits<T>::digits> s(x);
        return s.count();
    }
}

short CountBits(unsigned int x)
{
    short n = 0;
    while (x) {
        if (x & 0b1) n++;
        x = x >> 1;
    }
    return n;
}

int main(int argc, char* argv[])
{
  std::vector<std::string> args{argv + 1, argv + argc};
  std::vector<std::string> param_names{"x"};
  return GenericTestMain(args, "count_bits.cc", "count_bits.tsv", &CountBits,
                         DefaultComparator{}, param_names);
}
