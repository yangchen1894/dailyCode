#include <iostream>
#include <vector>
#include <set>

#if(0)
int MinPonum(std::vector<int> &nums1,  int &min_num){
    std::set<int> nums2;
    for(int &num : nums1){
        std::cout << "num1 " << num << std::endl;
        if(num > 0){
            if(nums2.insert(num).second){
                std::cout << "num2 " << num << std::endl;
            }
        }
    }
    
    int count = 1;
    for(int it : nums2){
                std::cout << "it " << it  << std::endl;
        if(it != count){
            min_num = count;
            return 0;
        }else{
            min_num = count + 1;
        }
        count++;
    }
    
    return 0;
}
#endif

void Swap(int &num1, int &num2){
    int temp = num1;
    num1 = num2;
    num2 = temp;
}

int MinPonum(const std::vector<int> &nums, int &min_num){
    int n = nums.size();
    for(int i = 0; i < n; i++){
        while(nums[i] > 0 && nums[nums[i] - 1] != nums[i]){
            Swap(nums[i], nums[nums[i] - 1]);
        }
    }
}

int main(int argc, char *argv[])
{
    int ret = 0;
    int min_num = 0;
    std::vector<int> nums1 = {-5, 3, 2, 3};
    std::vector<int> nums2 = {3, 4, -1 , 1};
    std::vector<int> nums3 = {1, 2, 0};
    MinPonum(nums1, min_num);
    std::cout << "min_num1 = " << min_num  << std::endl;
    MinPonum(nums2, min_num);
    std::cout << "min_num2 = " << min_num  << std::endl;
    MinPonum(nums3, min_num);
    std::cout << "min_num3 = " << min_num  << std::endl;
    return 0;
}

