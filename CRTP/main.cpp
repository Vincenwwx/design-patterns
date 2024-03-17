#include "DynamicVector.h"
#include "StaticVector.h"

#include <iostream>

bool testDynamicVector()
{
    using namespace crtp;
    DynamicVector<uint8_t> dym_vec{1, 2, 3, 4};
    bool all_pass{true};
    if (dym_vec.size() != 4)
    {
        std::cerr << "Wrong size\n";
        all_pass = false;
    }
    return all_pass;
}

bool testStaticVector()
{
    using namespace crtp;
    StaticVector<uint8_t, 4> dym_vec{1, 2, 3, 4};
    bool all_pass{true};
    if (dym_vec.size() != 4)
    {
        std::cerr << "Wrong size\n";
        all_pass = false;
    }
    if (dym_vec[0] != 1)
    {
        std::cerr << "Wrong value (0)";
        all_pass = false;
    }
    return all_pass;
}

int main()
{
    bool all_pass{true};
    all_pass |= testDynamicVector();
    all_pass |= testStaticVector();

    if (all_pass)
    {
        std::cout << "[CRTP] All tests passed!" << std::endl;
    }

    return 0;
}