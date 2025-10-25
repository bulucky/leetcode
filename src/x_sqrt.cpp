#include <cmath>
#include <iostream>

class Solution {
public:
    /**
    * 求解sqrt(n) 即求解x^2 - n = 0
    * xk+1 = (xk + xk/n) / 2    k >= 0, x0 > 0
    */ 
    int mySqrt(int x) {
        double x_k = x;
        while(x_k*x_k > x) {
            x_k = (x_k + (x/x_k)) / 2; 
        }
        return int(x_k);
    }
};

int main(int argc, char const* argv[]) 
{
    Solution sol;

    int res = sol.mySqrt(9);

    std::cout << res << std::endl;

    return 0;
}