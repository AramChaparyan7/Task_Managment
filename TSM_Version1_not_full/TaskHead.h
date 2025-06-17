#ifndef TASK
#define TASK
#include <iostream>
#include <string>

class Task{
private:
	std::string title_;
	std::string description_;
	std::string deadline_;
	std::string category_;
	int priority_;
	bool completed_;
public:
	Task();
	Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int priority);
	Task(const Task& other);
	Task(Task&& other) noexcept;
	~Task();
	void MarkCompleted();
	void editTask(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int priority);
	void displayTask() const;
};

#endif
