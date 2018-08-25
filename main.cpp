
#include<iostream>
#include"src/string_to_integer.cpp"

int main(){
    Solution so;
//    std::cout << so.myAtoi("2147483648") << std::endl;
//    std::cout << so.myAtoi("-91283472332") << std::endl;

//    std::cout << so.myAtoi("+-1") << std::endl;

//    std::cout << so.myAtoi("   +0 123") << std::endl;
    std::cout << so.myAtoi("-     234") << std::endl;
    return 0;
}
