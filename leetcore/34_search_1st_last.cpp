#include <iostream>
#include <vector>
#if(1)
class SearchFirstLast{
public:
    std::vector<int> SearchRange(std::vector<int>& nums, int target){
        int leftBorder = GetLeftBorder(nums, target);
        int rightBorder = GetRightBorder(nums,target);
        
        if(leftBorder == -2 || rightBorder == -2){
            return {-1, -1};
        }

        if(rightBorder - leftBorder > 1){
            return {leftBorder + 1, rightBorder - 1};
        }

        return {-1, -1};
    }

private:
    int GetLeftBorder(std::vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int leftBorder = -2;
        while (left <= right){
            int mid = left + ((right - left) / 2);
            if(nums[mid] < target){
                left = mid + 1;
            }else{
                right = mid -1;
                leftBorder = right;
            }
        }
        std::cout <<"leftBorder"<< leftBorder << std::endl;
        return leftBorder; // 下坐标，从0开始
    }
    int GetRightBorder(std::vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        int rightBorder = -2;
        while(left <= right)
        {
            int mid = left + ((right - left) / 2);
            if(nums[mid] <= target){
                left = mid + 1;
                rightBorder = left;
            }else{
                right = mid - 1;
            }
        }
        std::cout <<"rightBorder"<< rightBorder << std::endl;
        return rightBorder;
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
    SearchFirstLast search_first_last;
    std::vector<int> nums = {5, 7, 7, 8, 8, 10};

    std::vector <int> mid_site = search_first_last.SearchRange(nums, target);
    for (const auto &item : mid_site)
    {
         std::cout << "target num is: " << item << std::endl;
    }
    
}
#endif
