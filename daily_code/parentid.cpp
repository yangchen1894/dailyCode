#include <unordered_map>
#include <string>
#include <iostream>

// 假设 pbItem 和 party 是某些类的实例
class PbItem {
public:
    void set_parentid(const std::string& id) {
        parentid_ = id;
    }
    const std::string& parentid() const {
        return parentid_;
    }
private:
    std::string parentid_;
};

class Party {
public:
    const std::string& parentid() const {
        return parentid_;
    }
    void set_parentid(const std::string& id) {
        parentid_ = id;
    }
private:
    std::string parentid_;
};

int main() {
    bool bflter_parent_partyid = false;
    PbItem* pbItem = new PbItem();
    Party party;
    party.set_parentid("123");

    std::unordered_map<std::string, std::string> mapId2OpenId = {
        {"123", "openId_123"}
    };

    // 检查 bflter_parent_partyid 并设置 pbItem 的 parentid 属性
    if (!bflter_parent_partyid) {
        auto it = mapId2OpenId.find(party.parentid());
        if (it != mapId2OpenId.end()) {
            pbItem->set_parentid(it->second);
        } else {
            std::cerr << "Error: parentid not found in mapId2OpenId" << std::endl;
        }
    }

    // 输出结果
    std::cout << "pbItem parentid: " << pbItem->parentid() << std::endl;

    delete pbItem;
    return 0;
}
