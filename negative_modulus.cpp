#include <iomanip>
#include <iostream>

/// What happens with a negative modulus?
///
/// Use Case: Wrapping around negative indices when dealing with arrays.
///
int main()
{
    const char* example = "abcdefg";
    int exampleLength = 7;
    const int lowerBounds = -17;
    const int upperBounds = 17;

    for (int i = lowerBounds; i < upperBounds; ++i) {
        const auto justModWrapped = i % exampleLength;
        const auto justModWrappedPlusLength = justModWrapped + exampleLength;
        const auto modAddLengthMod = ((i % exampleLength) + exampleLength) % exampleLength;

        std::cout
            << std::setw(4) << i
            << std::setw(4) << justModWrapped
            << std::setw(4) << justModWrappedPlusLength
            << std::setw(3) << char(example[justModWrappedPlusLength])
            << std::setw(4) << modAddLengthMod
            << std::setw(3) << char(example[modAddLengthMod])
            << '\n';
    }

    return 0;
}