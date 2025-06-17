#ifndef TASK
#define TASK
#include <iostream>
#include <string>
#include <vector>
#include "UserHead.h"

class TaskManager{
public:
	std::vector<User*> users_;
	User* loggedInUser_;
private:
	TaskManager();
	TaskManager(const TaskManager& other);
	TaskManager(TaskManager&&) noexcept;
	~TaskManager();
	void registerUser(const std::string& username, const std::string& password);
	bool login(const std::string& username, const std::string& password);
	void logout();
	void addTaskForUser(const Task& task);
	void deleteTaskForUser(const std::string& title);
	void editTaskForUser(const std::string& title, const Task& task);
	void displayTaskForUser() const;
};

#endif
