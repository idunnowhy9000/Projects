#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <string>
#include <cstdlib>

void loopedFact(int n) {
    int first = 0, second = 1, next;
    for (int i = 0; i < n; i++) {
        if (i <= 1) next = i;
        else {
            next = first + second;
            first = second;
            second = next;
        }

        std::cout << next << " / ";
    }
}

int fib (int n) {
    return (n == 0 || n == 1) ? n : fib(n - 1) + fib(n - 2);
}

void recursionFact(int n) {
    int i = 0;

    for (int c = 0; c < n; c++) {
        std::cout << fib(i) << " / ";
        i++;
    }
}

int main(){
    std::string str_x;
    int x;

    std::cout << "Factorials up to: ";
    std::getline(std::cin, str_x);

    x = atoi(str_x.c_str());

    std::cout << "\nUsing loops:\n";
    loopedFact(x);

    std::cout << "\n\nUsing recursion:\n";
    recursionFact(x);
}

