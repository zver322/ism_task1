#include <iostream>
#include <memory>
#include <cstdint>
#include <iomanip>
#include "array_types.hpp"

#include <functional>
#include <chrono>

using intptr_t = std::intptr_t;

template <class T>
struct benchresult {
    T result;
    double btime;
};

template <class T, class input_type>
auto benchmark(std::function<T(input_type)> fn, input_type input, intptr_t nrepeat){
    T result;
    auto start = std::chrono::steady_clock::now();
    for (intptr_t i = 0; i < nrepeat; i++) {
        result = fn(input);
    }
    auto end = std::chrono::steady_clock::now();
    std::chrono::duration<double> duration_s = end - start;
    double ms_per_run = duration_s.count() * 1000 / nrepeat;
    return benchresult<T> {result, ms_per_run};
}

template <class T>
T quadratic_form(matrix<T> A, vec<T> x)
{   
    T result = 0;
    for (int i = 0; i < x.length(); ++i) {
      for (int j = 0; j < x.length(); ++j) {
        result += A(i, j) * x(i) * x(j);
      }
    }
    return result;
}

int main(int argc, char* argv[])
{
    intptr_t n;

    std::cin >> n;
    matrix<double> a(n, n);
    vec<double> x(n);
    
    for (intptr_t k = 0; k < n * n; k++) {
        std::cin >> a(k);
    }

    for (intptr_t k = 0; k < n; k++) {
        std::cin >> x(k);
    }

    std::function<double(int)> test_quadratic = [=](int idx) {return quadratic_form(a, x);};

    auto benchresult = benchmark(test_quadratic, 0, 1000);

    std::cout << std::setprecision(std::numeric_limits<double>::digits10 + 1)
              << "Dimension: " << n << "\n"
              << "Timing: " << benchresult.btime << " ms\n"
              << "Answer = " << benchresult.result
              << std::endl;
    return 0;
}
