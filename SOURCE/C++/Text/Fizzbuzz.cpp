#include <iostream>
#include <string>

int main(){
    for(int i = 0; i < 100; i++) {
        std::string str = "";
        if (i%3) str += "Fizz";
        if (i%5) str += "Buzz";
        
        std::cout << str << "\n";
    }
}
