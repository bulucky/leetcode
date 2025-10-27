#include <vector>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) { 
        std::vector<int> memo(n+1, 0);

        return recursion_process(n, memo);
    }

    int recursion_process(int n, std::vector<int>& memo) {
        if(memo[n]) return memo[n]; 
        if(n == 0 || n == 1) {
            return 1;
            memo[n] = 1;
        }
        
        if(!memo[n-1]) memo[n-1] = recursion_process(n-1, memo);
        if(!memo[n-2]) memo[n-2] = recursion_process(n-2, memo);
         
        memo[n] = memo[n-1] + memo[n-2];
        
        return memo[n];
    }
};

int main(int argc, char const* argv[])
{
    Solution sol;

    int res = sol.climbStairs(6);

    std::cout << res << std::endl;

    return 0;
}