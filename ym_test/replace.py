#!/usr/bin/env python
# coding=utf-8
import json

data = {
    "userid": "zhangsans",
    "name": "张三",
    "english_name": "jackzhang",
    "mobile": "15913215421",
    "department": [1, 2],
    "order": [10, 40],
    "positions": ["产品经理1", "产品经理2"],
    "gender": "1",
    "email": "zhangsans@gzdev.com",
    "biz_mail": "zhangsans@gzdev.com",
    "biz_mail_alias": ["zhangsans_1@gzdev.com", "zhangsans_2@gzdev.com"],
    "is_leader_in_dept": [1, 0],
    "direct_leader": ["zhangsans"],
    "enable": 1,
    "initpwd": "1234abcdE",
    "isnotify": 1,
    "avatar_mediaid": "Get(WwOpenUploadMedia_media_id)",
    "telephone": "020-123456",
    "extattr": {
        "attrs": [{
            "type": 0,
            "name": "文本名称",
            "value": "文本"
        }, {
            "type": 1,
            "name": "网页名称",
            "web": {
                "url": "http://www.test.com",
                "title": "标题"
            }
        }]
    },
    "external_profile": {
        "external_corp_name": "单位简称"
    }
}

{
    "userid": "zhangsan",
    "name": "张三",
    "english_name": "jackzhang",
    "mobile": "15913215421",
    "department": [1, 2],
    "order":[10,40],
    "positions": ["产品经理1","产品经理2"],
    "gender": "1",
    "email": "zhangsan@gzdev.com",
    "biz_mail": "zhangsan@t6490.wwltest.com",
    "biz_mail_alias": ["zhangsan_1@t6490.wwltest.com","zhangsan_2@t6490.wwltest.com"],
    "is_leader_in_dept": [1, 0],
    "direct_leader": ["autotest_wwllogic_2"],
    "enable":1,
    "initpwd":"1234abcdE",
    "isnotify":1,
    "avatar_mediaid": "Get(WwOpenUploadMedia_media_id)",
    "telephone": "020-123456",
    "extattr": {
        "attrs":[{
            "type": 0,
            "name": "文本名称",
            "value": "文本"
        }, {
            "type": 1,
            "name": "网页名称",
            "web": {
               "url": "http://www.test.com",
               "title": "标题"
            }
        }]
    },
    "external_profile": {
        "external_corp_name": "t6490"
    }
}

def modify_field(data, field, new_value):
    if field in data:
        data[field] = new_value
        print(f"字段 '{field}' 更新为: {new_value}")
    else:
        print(f"字段 '{field}' 不在数据中。")

def main():
    field = input("输入要修改的字段名: ")
    new_value = input("输入新的值: ")
    
    # 尝试将 new_value 转换为 JSON，如果是复杂数据类型
    try:
        new_value = json.loads(new_value)
    except json.JSONDecodeError:
        pass  # 如果不是 JSON，则保持为字符串

    modify_field(data, field, new_value)

    with open("updated_data.json", "w", encoding="utf-8") as file:
        json.dump(data, file, ensure_ascii=False, indent=4)
    
    print("\n更新后的数据已保存到 'updated_data.json' 文件中。")

if __name__ == "__main__":
    main()
