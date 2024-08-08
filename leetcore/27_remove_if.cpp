#include <iostream>
#include <vector>
#include <algorithm>

class Solution {
public:
#if(1)
    int removeElement(std::vector<int>& nums, int val) {
        //迭代器失效
        /* for(int num : nums){ */
            /* if(num == val){ */
                /* nums.erase(num); */
            /* } */
        /* } */

        for(auto it = nums.begin(); it != nums.end(); ){
            if(*it == val){
                it = nums.erase(it); // erase 返回下一个有效的迭代器
            }else{
                ++it; //只有在不删除的时候才递增迭代器
            }
        }
        return nums.size();
     }

#endif


#if(0)
    // 不是真正的删除
    int removeElement(std::vector<int>& nums, int val) {
        int slowIndex = 0;
        for(int fastIndex = 0; fastIndex < nums.size(); ++fastIndex){
            if(val != nums[fastIndex]){
                nums[slowIndex++] = nums[fastIndex];
            }
        }
    return slowIndex;
    }
#endif
#if(0)
    //  lambda
    int removeElement(std::vector<int>& nums, int val){
        auto new_end = std::remove_if(nums.begin(), nums.end(), [val](int num){
            return num == val;                           
        });
        nums.erase(new_end, nums.end());
        return nums.size();
    }
#endif    
};

int main()
{
    std::vector<int> nums = {3,2,2,3};
    int val = 3;
    Solution solut;
    int ret = solut.removeElement(nums, val);
    for(int num : nums ){
        
        std::cout << "num " << num  << std::endl;
    }
        return 0;
}

