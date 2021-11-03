#include <iostream>
#include <chrono>

#define clik_spawn
#define clik_sync

std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();


// fib

int fibwithcilk(int n) {
    if (n < 2) return n;
    else {
	int x, y;
	x = cilk_spawn fibwithcilk(n-1);
	y = fibwithcilk(n-2);
	cilk_sync;
	return (x + y);
    }
}

int fib(int n) {
    if (n < 2) return n;
    else {
	return fib(n-1) + fib(n-2);
    }
}



int main() {
    // Regular
    std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
    fib(40);
    std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
    std::cout << "Regular time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;


    // Cilk
    std::chrono::steady_clock::time_point cbegin = std::chrono::steady_clock::now();
    fib(40);
    std::chrono::steady_clock::time_point cend = std::chrono::steady_clock::now();
    std::cout << "Cilk time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(cend - cbegin).count() << "[µs]" << std::endl;
}
