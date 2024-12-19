#include "../header/Task.h"
#include <chrono>

bool Task::editTask(const std::string& newTitle, const Tag& newTag, const std::string& newDescription,
	const std::chrono::system_clock::time_point& newDeadline, int newPriority, bool status) {
	title = newTitle;
	tag = newTag;
	description = newDescription;
	deadline = newDeadline;
	priority = newPriority;
	this->status = status;
	return true;
}

void Task::markComplete() {
	status = true;
}

bool Task::createReminder(const std::chrono::system_clock::time_point& reminderTime, const std::string& notificationMethod) {
	Reminder newReminder;
	newReminder.setReminder(reminderTime, notificationMethod, "Reminder for task: " + title);
	reminders.push_back(newReminder);
	return true;
}

std::string Task::getTitle() const { return title; }
std::string Task::getDescription() const { return description; }
std::chrono::system_clock::time_point Task::getDeadline() const { return deadline; }
int Task::getPriority() const { return priority; }
bool Task::getStatus() const { return status; }
Tag Task::getTag() const { return tag; }
std::vector<Reminder> Task::getReminders() const { return reminders; }

bool Task::operator==(const Task& other) const {
	return title == other.title && description == other.description;
}