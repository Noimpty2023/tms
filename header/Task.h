#ifndef TASK_H_
#define TASK_H_

#include <string>
#include <chrono>
#include <vector>
#include "Tag.h"
#include "Reminder.h"

class Task {
private:
	std::string title;              // 任务标题
	std::string description;        // 任务描述
	std::chrono::system_clock::time_point deadline;  // 截止日期
	int priority;                   // 优先级
	bool status;                    // 任务状态
	Tag tag;                        // 标签
	std::vector<Reminder> reminders;  // 提醒列表

public:
	// 编辑任务
	bool editTask(const std::string& newTitle, const Tag& newTag, const std::string& newDescription,
		const std::chrono::system_clock::time_point& newDeadline, int newPriority, bool status);
	void markComplete();
	bool createReminder(const std::chrono::system_clock::time_point& reminderTime, const std::string& notificationMethod);

	// Getter functions
	std::string getTitle() const;
	std::string getDescription() const;
	std::chrono::system_clock::time_point getDeadline() const;
	int getPriority() const;
	bool getStatus() const;
	Tag getTag() const;
	std::vector<Reminder> getReminders() const;
	bool deleteReminder(Reminder* reminder);

	bool operator==(const Task& other) const;
};

#endif  // TASK_H_