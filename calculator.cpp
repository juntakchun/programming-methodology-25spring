#include "calculator.h"
#include <stdexcept>
#include <limits>

int Calculator::add(int a, int b) {
    // TODO
    if ((b > 0 && a > std::numeric_limits<int>::max() - b) || (b < 0 && a < std::numeric_limits<int>::min() - b)) {
        throw std::overflow_error("add overflow");
    }
    return a + b;
}

int Calculator::sub(int a, int b) {
    // TODO
    if ((b < 0 && a > std::numeric_limits<int>::max() + b) || (b > 0 && a < std::numeric_limits<int>::min() + b)) {
        throw std::overflow_error("sub overflow");
    }
    return a - b;
}

int Calculator::mul(int a, int b) {
    // TODO
    if (a > 0) {
        if (b > 0 && a > std::numeric_limits<int>::max() / b || b < 0 && b < std::numeric_limits<int>::min() / a) {
            throw std::overflow_error("mul overflow");
        }
    } else if (a < 0) {
        if (b > 0 && a < std::numeric_limits<int>::min() / b || b < 0 && a < std::numeric_limits<int>::max() / b) {
            throw std::overflow_error("mul overflow");
        }
    }
    return a * b;
}

int Calculator::div(int a, int b) {
    // TODO
    if (b == 0) {
        throw std::invalid_argument("Division by zero");
    }
    if (a == std::numeric_limits<int>::min() && b == -1) {
        throw std::overflow_error("div overflow");
    }
    return a / b;
}