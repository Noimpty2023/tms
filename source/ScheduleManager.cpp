#include "../header/ScheduleManager.h"
#include <vector>
#include <iostream>
#include <fstream>

ScheduleManager::ScheduleManager() {
	// TODO: Initialize tags or load from file
}

ScheduleManager::~ScheduleManager() {
	// TODO: Clean up any allocated resources if needed
}

bool ScheduleManager::createTag(const std::string& name) {
	Tag newTag;
	newTag.setName(name);
	tags.push_back(newTag);
	return true;
}

bool ScheduleManager::deleteTag(const std::string& name) {
	for (size_t i = 0; i < tags.size(); ++i) {
		if (tags[i].getTagInfo() == name) {
			tags.erase(tags.begin() + i);
			return true;
		}
	}
	return false;
}

std::vector<Tag> ScheduleManager::getTags() const {
	return tags;
}

std::vector<Task> ScheduleManager::filterTasksByTag(const Tag& tag, const std::vector<Task>& tasks) const {
	std::vector<Task> filteredTasks;
	for (const auto& task : tasks) {
		if (task.getTag() == tag) {
			filteredTasks.push_back(task);
		}
	}
	return filteredTasks;
}

std::vector<Task> ScheduleManager::displayTasks(const std::string& order, const std::vector<Task>& tasks) const {
	// TODO: Implement task ordering logic
	return tasks;
}