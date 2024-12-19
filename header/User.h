#ifndef HEADER_USER_H_
#define HEADER_USER_H_

#include <string>
#include <vector>
#include <chrono>
#include <fstream>
#include "Task.h"
#include "ScheduleManager.h"
#include <algorithm>

class User {
private:
	std::vector<Task> tasks;                        // 用户的任务列表
	ScheduleManager scheduleManager;                 // 用户的任务管理/显示主界面

public:
	User();   // 构造函数
	~User();  // 析构函数

	bool createTask(const std::string& title, const std::string& tagName,
		const std::string& description, const std::chrono::system_clock::time_point& deadline, int priority,
		bool reminder_flag, const std::chrono::system_clock::time_point& reminderTime);
	bool editTask(const Task& task, const std::string& title, const std::string& tagName,
		const std::string& description, const std::chrono::system_clock::time_point& deadline, int priority,
		bool reminder_flag, const std::chrono::system_clock::time_point& reminderTime);
	bool deleteTask(const Task& task);

	bool createTag(const std::string& name);  // 调用 ScheduleManager 类 API
	bool deleteTag(const std::string& name);  // 调用 ScheduleManager 类 API

	std::vector<Task> getTasks(const std::string& order = "创建时间") const;
	std::vector<Tag> getTags() const;

	bool loadTasks(const std::string& filename);  // 加载任务列表
	bool saveTasks(const std::string& filename);  // 保存任务列表

	bool saveTags(const std::string& filename);
	bool loadTags(const std::string& filename);

private:
	void checkTasksAndReminders();  // 定时检查任务和提醒
};

#endif  // HEADER_USER_H_