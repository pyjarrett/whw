#include <iomanip>
#include <iostream>

#define EVALUATE(a, op1, b, op2, c) \
    std::cout << std::setw(5) << #a << ' ' << #op1 << ' ' << std::setw(5) << #b << ' ' << #op2 << ' ' << std::setw(5) << #c << " == " << ((a op1 b op2 c) > 0 ? "true" : "false") << '\n';

#define ATTEMPT_ALL(op1, op2)                \
    EVALUATE(false, op1, false, op2, false); \
    EVALUATE(false, op1, false, op2, true);  \
    EVALUATE(false, op1, true, op2, false);  \
    EVALUATE(false, op1, true, op2, true);   \
    EVALUATE(true, op1, false, op2, false);  \
    EVALUATE(true, op1, false, op2, true);   \
    EVALUATE(true, op1, true, op2, false);   \
    EVALUATE(true, op1, true, op2, true)     \
    std::cout << std::endl;

int main()
{
    ATTEMPT_ALL(||, &&);
    ATTEMPT_ALL(&&, ||);
    ATTEMPT_ALL(&&, &&);
    ATTEMPT_ALL(||, ||);

    return 0;
}