#include <iostream>
#include <vector>
#if(0)
class InsertSearch{
public:
    int Search(std::vector<int> &nums, int target){
        int left = 0;
        int right = nums.size() -1;
        while(left <= right){
            int mid = left + ((right - left) / 2);
            if(nums[mid] < target){
                left = mid + 1;
            }else if(nums[mid] > target){
                right = mid - 1;
            }else{
                return mid;
            }
        }
        //return right + 1;
        return left; // left 为指向第一个大于target的元素
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
    InsertSearch insert_search;
    std::vector<int> nums = {1, 3, 5, 6};
    int target_num = insert_search.Search(nums, target);
    std::cout << "target num is: " << target_num << std::endl;
}
#endif