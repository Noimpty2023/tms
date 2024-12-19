#include "../header/User.h"
#include <chrono>
#include <iostream>

User::User() {
	// Setup reminder checking
}

User::~User() {
	// Cleanup any resources if necessary
}

bool User::createTask(const std::string& title, const std::string& tagName,
	const std::string& description, const std::chrono::system_clock::time_point& deadline, int priority,
	bool reminder_flag, const std::chrono::system_clock::time_point& reminderTime) {
	Task newTask;
	Tag tag;
	tag.setName(tagName);
	newTask.editTask(title, tag, description, deadline, priority, false);

	if (reminder_flag) {
		newTask.createReminder(reminderTime, "popup");
	}

	tasks.push_back(newTask);
	return true;
}

bool User::editTask(const Task& task, const std::string& title, const std::string& tagName,
	const std::string& description, const std::chrono::system_clock::time_point& deadline, int priority,
	bool reminder_flag, const std::chrono::system_clock::time_point& reminderTime) {
	Task editedTask = task;
	Tag tag;
	tag.setName(tagName);
	editedTask.editTask(title, tag, description, deadline, priority, false);

	if (reminder_flag) {
		editedTask.createReminder(reminderTime, "popup");
	}

	return true;
}

bool User::deleteTask(const Task& task) {
	// TODO: Implement task deletion
	return true;
}

bool User::createTag(const std::string& name) {
	return scheduleManager.createTag(name);
}

bool User::deleteTag(const std::string& name) {
	return scheduleManager.deleteTag(name);
}

bool compareByDueDate(const Task& task1, const Task& task2) {
	return task1.getDeadline() < task2.getDeadline();  // 按照 QDateTime 升序排序
}

std::vector<Task> User::getTasks(const std::string& order) const {
	if (order == "截止时间") {
		std::vector<Task> sortedTasks = tasks;  // 创建任务的副本
		std::sort(sortedTasks.begin(), sortedTasks.end(), compareByDueDate);  // 排序
		return sortedTasks;
	}
	else if (order == "创建时间") {
		return tasks;  // 按创建时间顺序返回原始任务列表
	}
	else {
		return {};  // 防止未返回值
	}
}

std::vector<Tag> User::getTags() const {
	return scheduleManager.getTags();
}