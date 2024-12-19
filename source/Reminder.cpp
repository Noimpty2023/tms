#include "../header/Reminder.h"
#include <chrono>
#include <iostream>

void Reminder::setReminder(const std::chrono::system_clock::time_point& time, const std::string& method, const std::string& msg) {
	reminderTime = time;
	notificationMethod = method;
	message = msg;
}

bool Reminder::checkAndTriggerReminder() {
	auto now = std::chrono::system_clock::now();
	printf("Reminder:Please complete your task!!!\n");
	return now >= reminderTime;
}

std::chrono::system_clock::time_point Reminder::getReminderTime() {
	return reminderTime;
}