#include "TaskHead.h"
#include <iostream>
#include <utility>

Task::Task() : title_(""), description_(""), deadline_(""), category_(""), priority_{0} ,completed_{0} {}

Task::Task(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int priority) : title_{title}, description_{description}, deadline_{deadline}, category_{category}, priority_{priority}, completed_{0} {}

Task::Task(const Task& other) :  title_{other.title_}, description_{other.description_}, deadline_{other.deadline_}, category_{other.category_}, priority_{other.priority_}, completed_{other.completed_} {}

Task::Task(Task&& other) noexcept :  title_{std::move(other.title_)}, description_{std::move(other.description_)}, deadline_{std::move(other.deadline_)}, category_{std::move(other.category_)}, priority_{other.priority_}, completed_{other.completed_} {}

Task::~Task() = default;

void Task::MarkCompleted(){
	completed_ = true;
}

void Task::editTask(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, int priority){
    title_ = title;
	description_ = description;
	deadline_ = deadline;
	category_ = category;
	priority_ = priority;
}

void Task::displayTask() const {
	std::cout << "title: " << title_ << std::endl;
	std::cout << "description: " << description_ << std::endl;
	std::cout << "deadline: " << deadline_ << std::endl;
	std::cout << "category: " << category_ << std::endl;
	std::cout << "priority: " << priority_ << std::endl;
	std::cout << "completed: " << completed_ << std::endl;
}
