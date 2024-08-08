#include <iostream>

class Solution {
public:
    int mySqrt(uint64_t &x) {
        if(x == 1){
            x = 1;
            return 0;
        }
        int left = 0;
        uint64_t right = x / 2;
        uint64_t mid = 0;
        uint64_t result = 0;
        while(left <= right){
            mid = left + ((right - left) / 2);
            uint64_t tmp = mid * mid;
            if(tmp < x){
                left = mid + 1;
                result = mid;
                std::cout << "left: " << left << ",result: " << result << std::endl;
            }else if(tmp > x){
                right = mid - 1;
                std::cout << "left: " << right << std::endl;
            }else{
                x = mid;
                std::cout << "left: " << mid << std::endl;
                return 0;
            }
        }

        x = result;
        return 0;
    }
};

int main(int argc, char* argv[]){
    uint64_t target = std::stoi(argv[1]);
    Solution sqrt;
    int ret = sqrt.mySqrt(target);
    if(ret != 0){
        printf("error%d",ret);
    }

    std::cout << "sqrt: " << target << std::endl;
    return 0;
}
