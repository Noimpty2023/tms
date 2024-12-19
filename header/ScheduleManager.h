#ifndef SCHEDULEMANAGER_H_
#define SCHEDULEMANAGER_H_

#include <string>
#include <vector>
#include "Tag.h"
#include "Task.h"

class ScheduleManager {
private:
    std::vector<Tag> tags;  // 标签列表

public:
    ScheduleManager();  // 构造函数
    ~ScheduleManager();  // 析构函数

    bool createTag(const std::string& name);
    bool deleteTag(const std::string& name);
    std::vector<Tag> getTags() const;
    std::vector<Task> filterTasksByTag(const Tag& tag, const std::vector<Task>& tasks) const;
    std::vector<Task> displayTasks(const std::string& order, const std::vector<Task>& tasks) const;

    bool saveTags(const std::string& filename);  // 保存标签列表到文件
    bool loadTags(const std::string& filename);  // 从文件加载标签列表
};

#endif  // SCHEDULEMANAGER_H_