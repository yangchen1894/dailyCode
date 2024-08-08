#include <iostream>
#include <vector>

class Solution {
public:
    int removeDuplicates(std::vector<int>& nums) {
        int slowIndex = 1;
        for (int fastIndex = 1; fastIndex < static_cast<int>(nums.size()); fastIndex++) {
            if (nums[slowIndex - 1] != nums[fastIndex]) {
                nums[slowIndex] = nums[fastIndex];
                ++slowIndex;
            }
        }
        return slowIndex;
    }
};

int main()
{
    std::cout << "Hello world" << std::endl;
    return 0;
}

