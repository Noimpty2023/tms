#include <iostream>
#include <chrono>
#include <thread>
#include "../header/User.h"

int main() {
	// 创建用户
	User user;

	// 创建标签
	std::cout << "Creating tag 'Important'...\n";
	user.createTag("Important");

	// 创建任务
	std::cout << "Creating task 'Finish Homework'...\n";
	Tag taskTag;
	taskTag.setName("Important");

	std::chrono::system_clock::time_point deadline = std::chrono::system_clock::now() + std::chrono::hours(5);  // 任务截止时间为5小时后
	std::chrono::system_clock::time_point reminderTime = std::chrono::system_clock::now() + std::chrono::hours(4);  // 提醒时间为4小时后

	user.createTask("Finish Homework", "Important", "Complete the math homework", deadline, 1, true, reminderTime);

	// 设置任务提醒
	Task task = user.getTasks()[0];  // 获取刚刚创建的任务
	Reminder reminder;
	reminder.setReminder(reminderTime, "Email", "Reminder to finish the homework.");
	task.createReminder(reminderTime, "Email");

	// 模拟提醒触发
	std::this_thread::sleep_for(std::chrono::seconds(1));  // 等待1秒
	reminder.checkAndTriggerReminder();  // 触发提醒（检查当前时间是否已到）

	// 显示用户任务列表
	std::cout << "User's tasks:\n";
	for (const Task& t : user.getTasks()) {
		std::cout << "Title: " << t.getTitle() << ", Description: " << t.getDescription() << "\n";
	}

	return 0;
}