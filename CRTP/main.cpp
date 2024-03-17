#include "DynamicVector.h"
#include "StaticVector.h"

#include <iostream>

template <typename T>
void printSize(crtp::DenseVector<T> const &vector)
{
    auto const sz = vector.size();
    std::cout << "Vector (" << sz << "): ";
    for (size_t i = 0; i < sz; i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}

int main()
{
    std::cout << "--- CRTP showcase ---\n";
    crtp::DynamicVector<int> dv{1, 2, 3, 4};
    crtp::StaticVector<int, 4> sv{5, 6, 7, 8};

    printSize(dv);
    printSize(sv);

    return 0;
}