#include <string>
#include <iostream>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        if(!a.size()) return b;
        else if(!b.size()) return a;

        std::string sum_str;
        std::string added_temp, summand_temp;
        if(a.size() <= b.size()) {
            added_temp = a;
            summand_temp = b;
        }else {
            added_temp = b;
            summand_temp = a;
        }
        summand_temp.resize((summand_temp.size()+1));
        for(int i = 1; i < summand_temp.size(); ++i) {
            summand_temp[summand_temp.size()-i] = summand_temp[summand_temp.size()-i-1];
        }
        summand_temp[0] = '0';
        
        int carry_flag = 0;
        for(int i = 0; i < summand_temp.size(); ++i) {
            if(i < added_temp.size()) {
                int sum = ((summand_temp[summand_temp.size()-1-i]-48) + (added_temp[added_temp.size()-1-i]-48)) + carry_flag;
                
                int this_bit = sum % 2;
                
                summand_temp[summand_temp.size()-1-i] = (this_bit+48);
                
                carry_flag = sum / 2;
            }else {
                int sum = (summand_temp[summand_temp.size()-1-i]-48) + carry_flag;
        
                int this_bit = sum % 2;

                summand_temp[summand_temp.size()-1-i] = (this_bit+48);

                carry_flag = sum / 2;
            }
        }

        if(summand_temp[0] == '0') {
            for(int i = 1; i < summand_temp.size(); ++i) {
                summand_temp[i-1] = summand_temp[i];
            }
            summand_temp.resize(summand_temp.size()-1);
        }
        return summand_temp;
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;
    std::string a = "1010";
    std::string b = "1011";
    
    std::string str_sum = sol.addBinary(a, b);
    std::cout << str_sum << std::endl;

    // bool b_1 = true, b_2 = true;
    // bool b_3 = b_1 + b_2;
    // std::cout << b_3 << std::endl;

    return 0;
}

