
#include<iostream>
#include"src/letter_combinations_of_a_phone_number.cpp"

int main(){
    Solution so;

    auto tmp = so.letterCombinations("9756393");
    for(int i = 0; i < tmp.size(); i++){
        std::cout << tmp[i] << std::endl;
    }
    return 0;
}
