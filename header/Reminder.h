#ifndef REMINDER_H_
#define REMINDER_H_

#include <string>
#include <chrono>

class Reminder {
private:
    std::chrono::system_clock::time_point reminderTime;  // 提醒时间
    std::string notificationMethod;                      // 通知方式
    std::string message;                                 // 提醒消息

public:
    void setReminder(const std::chrono::system_clock::time_point& time, const std::string& method, const std::string& msg);
    bool checkAndTriggerReminder();  // 检查并触发提醒
    std::chrono::system_clock::time_point getReminderTime();
    std::string getMessage() const { return message; }
};

#endif  // REMINDER_H_