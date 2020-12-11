#include <unordered_map>
#include <iostream>

class Solution {
public:
    int climbStairs(int n) {
        
        std::unordered_map<int, int> combs;
        for (int i = 0; i <= n; i++) {
            if (i <= 0) {
                combs.insert(std::make_pair(i, 1));
            } else if (i == 1) {
                combs.insert(std::make_pair(i, 1));
            } else if (combs.find(i) == combs.end()) {
                combs.insert(std::make_pair(i, combs.at(i-1) + combs.at(i-2)));
            }
        }
        std::cout << combs.at(n) << std::endl;
        
        return combs.at(n);
    }
};