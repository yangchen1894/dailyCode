#include <iostream>
#include <vector>

struct RoadStatus
{
    int index_; // 道路编号
    char status_;

    RoadStatus(int x, char s)
    :index_(x), status_(s)
    {

    }
};

void CompressRoadStatus(std::vector<RoadStatus> &input)
{
    if(input.empty())
    {
        return;
    }

    char curr_status = input.at(0).status_;
    int write_index = 1;
    for(int i = 0; i < input.size(); ++i)
    {
        if(curr_status != input[i].status_)
        {
            curr_status = input[i].status_;
            input[write_index] = input[i];
            ++write_index;
        }
    }

    input.erase(input.begin() + write_index, input.end());
}

int main()
{
    std::vector<RoadStatus> input = {
        RoadStatus(1, 'R'),
        RoadStatus(2, 'R'),
        RoadStatus(3, 'R'),
        RoadStatus(4, 'G'),
        RoadStatus(5, 'G'),
        RoadStatus(6, 'Y')
    };
    
    CompressRoadStatus(input);

    for(const auto &iter : input)
    {
        std::cout << iter.index_ << iter.status_ << std::endl;
    }
    return 0;
}

