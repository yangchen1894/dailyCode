#include <iostream>
#include <vector>

#if(0)
class Dichotomy
{
public:
    int Search(std::vector<int> &nums, int target)
    {
        int left = 0;
        int right = nums.size() - 1;
        while(left <= right) {
            int mid = left + ((right - left) / 2); 
            if(nums[mid] < target){
                left = mid + 1;
            }
            else if(nums[mid] > target){
                right = mid - 1;
            } else {
                return mid;
            }
        }
        return -1000001;
    }
};

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("usage:%s fileName uin\n", argv[0]);
        return -1;
    }
    int target = std::stoi(argv[1]);
    Dichotomy dichotomy;
    std::vector<int> nums = {-1, 0, 3, 5, 9, 12};
    int target_num = dichotomy.Search(nums, target);
    std::cout << "target num is: " << target_num << std::endl;
}
#endif

