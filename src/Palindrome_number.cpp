#include <iostream>
#include <vector>
#include <cmath>

class Solution {
public:
    bool isPalindrome(int x) {
        bool is_palindrome = false;
        
        std::vector<int> f_num;
        std::vector<int> i_num;
        
        long long int x_num = 1;
        long long int x_bit_num = 0;
        if(x < 0) {
            return is_palindrome;
        }
        if(x == 0) {
            is_palindrome = true;
            return is_palindrome;
        }
        while(x / x_num != 0) {
            x_num *= 10;
            x_bit_num++;
        }
        f_num.resize(x_bit_num);
        i_num.resize(x_bit_num);

        long long int f_num_bits = static_cast<long long>(std::pow(10, x_bit_num));
        long long int i_num_bits = 1;

        int x_reminder = x; 
        for(size_t i = 0; i < x_bit_num; ++i) {
            x_reminder %= f_num_bits;
            f_num_bits /= 10;
            f_num[i] = x_reminder / f_num_bits;
            x_reminder = x;
        }
        for(size_t i = x_bit_num-1; i >= 0; --i) {
            size_t j = i;
            while(j) {
                i_num_bits = static_cast<int>(std::pow(10, j));
                x_reminder %= i_num_bits;
                j--;
            }
            i_num[x_bit_num-1-i] = x_reminder;
            x_reminder = static_cast<int>(x) / static_cast<long long>(std::pow(10, x_bit_num-i));
            if(i == 0) break;
        }
        // for(size_t i = 0; i < f_num.size(); ++i) {
        //     std::cout << f_num[i] << std::endl;
        // }
        // for(size_t i = 0; i < i_num.size(); ++i) {
        //     std::cout << i_num[i] << std::endl;
        // }
        std::vector<bool> bits_bool; 
        for(size_t i = 0; i < x_bit_num; ++i) {
            bits_bool.emplace_back(f_num[i] == i_num[i]);
        }
        is_palindrome = true;
        for(size_t i = 0; i < bits_bool.size(); ++i) {
            if(bits_bool[i] == false) {
                is_palindrome = false;
            }
        }
        return is_palindrome;
    }
};

int main(int argc, char const* argv[]) 
{   
    Solution sol;
    std::cout << sol.isPalindrome(1234567899) << std::endl;

    return 0;
}