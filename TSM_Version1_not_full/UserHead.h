#ifndef USER
#define USER
#include <string>
#include <vector>
#include "TaskHead.h"

class User{
private:
	std::string username_;
	std::string password_;
	std::vector<Task*> tasks_;
public:
	User(const std::string& username, const std::string& password);
	User(const User& other);
	User(User&& other) noexcept
	~User();
	void addTask(Task* task);
	void editTask(const std::string title, const Task* ubdatedTask);
	void listTasks() const;
	Task* searchTask(const std::string& title)
};

#endif
