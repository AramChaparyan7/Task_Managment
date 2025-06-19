#include "headers.h"

int Task::ID = 0;

Task::Task() = delete;

Task::Task(int uid) : id_{++ID}, uid_{uid}, title_(""), description_(""), deadline_(""), category_(""), priority_{0} ,state_{NOT_STATED} {}

Task::Task(int uid, const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, Priority priority, State) : id_{++ID}, uid_{uid}, title_{title}, description_{description}, deadline_{deadline}, category_{category}, priority_{priority}, state_{State::NOT_STATED} {}

Task::Task(const Task& other) :  id_{++ID}, uid_{other.uid_}, title_{other.title_}, description_{other.description_}, deadline_{other.deadline_}, category_{other.category_}, priority_{other.priority_}, state_{other.state_} {}

Task::Task(Task&& other) noexcept : id_{++ID}, uid_{uid_}, title_{std::move(other.title_)}, description_{std::move(other.description_)}, deadline_{std::move(other.deadline_)}, category_{std::move(other.category_)}, priority_{other.priority_}, state_{other.state_} {}


Task& Task::operator=(const Task& other) {
	uid_ = other.uid_;
	title_ = other.title_;
	deadline_ = other.deadline_;
	description_ = other.description_;
	category_ = other.category_;
	priority_ = other.priority_;
	state_ = other.state_;
	return *this;
}

Task& Task::operator=(Task&& other) noexcept{
	uid_ = other.uid_;
	title_ = std::move(other.title_);
	deadline_ = ostd::move(ther.deadline_);
	description_ = ostd::move(ther.description_);
	category_ = ostd::move(ther.category_);
	priority_ = other.priority_;
	state_ = other.state_;
	return *this;
}

Task::~Task() = default;

void Task::set_prio(Priority prio){
	priority_ = prio;
}

void Task::set_state(State state){
	state_ = state;
}

void Task::editTask(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, Priority
priority, State state){
    title_ = title;
	description_ = description;
	deadline_ = deadline;
	category_ = category;
	priority_ = priority;
	state_ = state;
}

void Task::displayTask() const {
	std::cout << "uid: " << uid_ << std::endl;
	std::cout << "id: " << id_ << std::endl;
	std::cout << "title: " << title_ << std::endl;
	std::cout << "description: " << description_ << std::endl;
	std::cout << "deadline: " << deadline_ << std::endl;
	std::cout << "category: " << category_ << std::endl;
	std::cout << "priority: " << priority_ << std::endl;
	std::cout << "state: " << state_ << std::endl;
}

bool Task::operator==(const Task& other) const{
	return id_ == other.id_;
}

bool Task::operator!=(const Task& other) const{
	return !(*this == other);
}

Task& Task::operator++(){
	switch(state_){
		case State::NOT_STATED:
			state_ = IN_PROGRESS;
			break;
		case State::IN_PROGRESS:
			state_ = COMPLETED;
			break;
		case State::COMPLETED:
			state_ = NOT_STATED;
			break;
	}
	return *this;
}

const Task Task::operator++(int) {
	Task tmp(*this);
	++*this;
	return tmp;
}
	
Task& Task::operator--() {
	switch(state_){
		case State::NOT_STATED:
			state_ = COMPLETED;
			break;
		case State::IN_PROGRESS:
			state_ = NOT_STATED;
			break;
		case State::COMPLETED:
			state_ = IN_PROGRESS;
			break;
	}
	return *this;
}

const Task Task::operator--(int){
	Task tmp(*this);
	--*this;
	return tmp;
}

std::ostream& operator<<(std::ostream& os, const Task& t){
	t.displayTask();
	return os;
}

std::istream& operator>>(std::istream& is, Task& t){
	std::cout << "title: ";
	std::cin >> t.title_;
	std::cout << "description: ";
	std::cin >> t.description_;
	std::cout << "deadline: ";
	std::cin >> t.deadline_;
	std::cout << "category: ";
	std::cin >> t.category_;
	std::cout << "priority: ";
	std::cin >> t.priority_;
	std::cout << "state: ";
	std::cin >> t.state_;
	return is;
}

int Task::get_task_id() const{
	return id_;
}

std::string get_title() {
	return title_;
}
