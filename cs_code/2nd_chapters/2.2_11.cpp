#include <iostream>
#include <vector>
#include <algorithm>

#if(0)
int GetMidNum(std::vector<int> &nums1, std::vector<int> &nums2, int &mid_num){
    std::vector<int> temp = (nums1.begin(), nums1.end());
    //std::vector<int> temp = nums1;
    temp.insert(temp.end(),nums2.begin(), nums2.end());
    std::sort(temp.begin(), temp.end(), [](int a, int b){
              return a < b;
              });//默认是升序
    for(int nums : temp){
        std::cout << "num = " <<  nums << std::endl;
    }
    int left = 0;
    int right = temp.size() - 1;
    int mid = left + (right - left) / 2;

    mid_num = temp.at(mid);
    
    return 0;
}
#endif

#if(0)
int GetMidNum(std::vector<int> &nums1, std::vector<int> &nums2, int &median){
    auto it = nums1.begin();
    for (const auto& elem :nums2) {
        // 找到插入位置
        it = std::lower_bound(it, nums1.end(), elem);
        // 插入元素
        nums1.insert(it, elem);
        // 更新迭代器以指向下一个插入位置
        ++it;
    }
}
#endif

int GetMidNum(std::vector<int> &nums1, std::vector<int> &nums2, int &median){
    int total_size = nums1.size() + nums2.size() - 1; //从0开始
    int half_size = total_size / 2;
    size_t nums1_st = 0; //nums1的起始位置
    size_t nums2_st = 0;
    int pre_median = 0;//之前的中位值
    int cur_median = 0;
    for(int k = 0; k <= half_size; ++k){

        pre_median = cur_median;
        //如果nums1已经遍历完了,从nums2中选择中位数
        if(nums1_st == nums1.size()){
            pre_median = cur_median;
            //cur_median = nums2[nums2_st];
            //nums2_st++;
            cur_median = nums2[nums2_st++];
            std::cout << "pre_median = " << pre_median << ",cur_median = " << cur_median << " line " << __LINE__ <<  std::endl;
        }else if(nums2_st == nums2.size()){
            cur_median = nums1[nums1_st++];
            std::cout << "pre_median = " << pre_median << ",cur_median = " << cur_median << " line " <<__LINE__ <<  std::endl;
        }else if(nums1[nums1_st] <= nums2[nums2_st])
        {
            cur_median = nums1[nums1_st++];
            std::cout << "pre_median = " << pre_median << ",cur_median = " << cur_median << " line " <<__LINE__ <<  std::endl;
        }else{
            cur_median = nums2[nums2_st++];
            std::cout << "pre_median = " << pre_median << ",cur_median = " << cur_median << " line " << __LINE__ <<  std::endl;
        }

    }
        //偶数
        //奇数
        if(total_size % 2 == 1)
        {
            median = cur_median;
        }else{
            median = (pre_median + cur_median) / 2;
        }

        std::cout << "pre_median = " << pre_median << ",cur_median = " << cur_median<< " " << __func__ << " "<< __LINE__ <<  std::endl;
    return 0;

}

int main()
{
    std::vector<int> first = {11, 13, 15, 17, 19};
    std::vector<int> second = {2, 4, 6, 8, 20};
    int median;
    int ret = GetMidNum(first, second, median);
    if(ret != 0){
    
        std::cout << "ret = " << ret  << std::endl;
        return ret;
    }
    std::cout << "mid_num = " << median << std::endl;
    return 0;
}

