#include <iostream>
#include <string>
#include <algorithm>

int main(){
    std::string str;

    std::cout << "Enter string: ";
    std::getline(std::cin, str);

    std::string reversed(str);
    std::reverse(reversed.begin(), reversed.end());

    if (reversed.length() && str == reversed) {
        std::cout << "\n" << str << " is a palindrome.";
    }
    else std::cout << "\n" << str << " isn't a palindrome";
}
