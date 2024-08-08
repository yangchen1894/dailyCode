#include <iostream>

int IsValidPerSpureNum(int target, bool &is_valid_per_spure_num)
{
    if(target == 1){
        is_valid_per_spure_num = true;
        return 0;
    }
    uint32_t left = 0;
    uint32_t right = target / 2 -1;
    while(left <= right){
        uint32_t mid = left + ((right - left) / 2);
        uint32_t tmp = mid * mid;
        std::cout << "mid, "<< mid << "tmp, " << tmp << "left, " << left << "right, " << right << std::endl;
        if(target < tmp)
        {
            right = mid -1;
        }else if(target > tmp){
            left = mid + 1;
        }else{
            is_valid_per_spure_num = true;
            return 0;
        }
    }
    return 0;
}

int main(int argc, char* argv[])
{
    uint32_t target = std::stoll(argv[1]);
    bool is_valid_per_spure_num = false;
    int ret = 0;
    ret = IsValidPerSpureNum(target, is_valid_per_spure_num);
    if(ret != 0){
        std::cout << "IsValidPerSpureNum failed" << std::endl;
    }
    if(is_valid_per_spure_num){
        std::cout << "is valid perfert spure num" << std::endl;
    }else{
        std::cout << "no valid perfert spure num" << std::endl;
    }
    return 0;
}

