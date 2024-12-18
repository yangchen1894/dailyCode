#include <iostream>
#include <string>

void CheckPwd(const std::string &initpwd)
{
    // 检查密码长度
    if ((initpwd.size() > 16) || (initpwd.size() < 8))
    {
        std::cout << "ERR: Invalid length " << initpwd.size() << std::endl;
        return; // 直接返回，不继续检查
    }

    bool bdigit = false;
    bool bchar = false;
    bool bChar = false;
    // 检查密码中的字符
    for (size_t i = 0, n = initpwd.size(); i != n; ++i)
    {
        if ((initpwd[i] >= '0') && (initpwd[i] <= '9'))
        {
            bdigit = true; // 找到数字
        }
        else if ((initpwd[i] >= 'A') && (initpwd[i] <= 'Z'))
        {
            bchar = true; // 找到大写字母
        }
        else if ((initpwd[i] >= 'a') && (initpwd[i] <= 'z'))
        {
            bChar = true; // 找到小写字母
        }
        else
        {
            std::cout << "ERR pwd invalid" << std::endl;
            return;
        }
    }

    // 检查是否同时包含字母和数字
    if (!bdigit || !bchar || !bChar)
    {
        std::cout << "ERR: Password must contain at least one letter and one digit." << std::endl;
        std::cout << "bdigit: " << bdigit << ", bchar: " << bchar << std::endl;
        return; // 直接返回，不继续执行
    }

    // 如果通过所有检查，输出密码
    std::cout << "Password is valid: " << initpwd << std::endl;
}

int main(int argc, char* argv[]) {
    std::string pwd = argv[1];
    CheckPwd(pwd); // 测试用例
    return 0;
}

