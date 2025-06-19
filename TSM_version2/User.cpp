#include "headers.h"

int User::ID_ = 0;

User::User() : id_{++ID_}, name_{" "}, password_{" "}, is_loged{false} {}

User::User(const User& other) : id_{++ID_}, name_{other.name_}, password_{other.password_}, is_loged{other.is_loged} {
	int size = other.tasks_.size();
	tasks_ = std::vector<Task*>(size);
	for(int i = 0; i < size; ++i) {
		tasks_[i] = new Task(*other.tasks_[i]);
	}
}

User::User(User&& other) noexcept  : id_{++ID_}{
	name_ = std::move(other.name_);
	password_ = std::move(other.password_);
	is_loged = other.is_loged;
	int size = other.tasks_.size();
	tasks_ = std::vector<Task*>(size);
	for(int i = 0; i < size; ++i) {
		tasks_[i] = other.tasks_[i];
	}
}

User& User::operator=(const User& other) {
	if(this == &other){
		return *this;
	}
	name_ = other.name_;
	password_ = other.password_;
	is_loged = other.is_loged;
	for(int i = 0; i < tasks_.size(); ++i) {
		delete tasks_[i];
	}
	tasks_.clear();
	int size = other.tasks_.size();
	tasks_.resize(size);
	for(int i = 0; i < size; ++i) {
		tasks_[i] = new Task(*other.tasks_[i]);
	}
	return *this;
}

User& User::operator=(User&& other) noexcept {
	name_ = std::move(other.name_);
	password_ = std::move(other.password_);
	is_loged = other.is_loged;
	for(int i = 0; i < tasks_.size(); ++i) {
		delete tasks_[i];
	}
	int size = other.tasks_.size();
	tasks_.resize(size);
	for(int i = 0; i < size; ++i) {
		tasks_[i] = other.tasks_[i];
		other.tasks_[i] = nullptr;
	}
	return *this;	
}

User::~User() {
	for(int i = 0; i < tasks_.size(); ++i) {
		delete tasks_[i];
	}
	tasks_.clear();
}

Task* User::add_task() {
	std::string title;
	std::string description;
	std::string deadline;
	std::string category;
	int priority;
	int state;
	std::cout << "title: ";
	std::cin >> title;
	std::cout << "description: ";
	std::cin >> description;
	std::cout << "deadline: ";
	std::cin >> deadline;
	std::cout << "category: ";
	std::cin >> category;
	std::cout << "priority: ";
	std::cin >> priority;
	std::cout << "state: ";
	std::cin >> state;
	Task *newtask = new Task(id_, title, description, deadline, category, static_cast<Priority>(priority), static_cast<State>(state));
	tasks_.push_back(newtask);
	return newtask;
}

void User::delete_task(int id) {
	for(int i = 0; i< tasks_.size(); ++i) {
		if(tasks_[i]->get_task_id() == id) {
			delete tasks_[i];
			tasks_.erase(tasks_.begin() + i);
		}
	}
}

void User::edit_task(int id) {
	Task* tmp = nullptr;
	for(int i = 0; i< tasks_.size(); ++i) {
		if(tasks_[i]->get_task_id() == id) {
			tmp = tasks_[i];
		}
	}
	std::string title;
	std::string description;
	std::string deadline;
	std::string category;
	int priority;
	int state;
	std::cout << "title: ";
	std::cin >> title;
	std::cout << "description: ";
	std::cin >> description;
	std::cout << "deadline: ";
	std::cin >> deadline;
	std::cout << "category: ";
	std::cin >> category;
	std::cout << "priority: ";
	std::cin >> priority;
	std::cout << "state: ";
	std::cin >> state;
	if(tmp == nullptr){
		std::cout << "no task found";
		return;
	}
	tmp->editTask(title, description, deadline, category, static_cast<Priority>(priority), static_cast<State>(state));
}

void User::list_tasks() {
	for(int i = 0; i < tasks_.size(); ++i) {
		tasks_[i]->displayTask();
	}
}

Task* User::search_tasks(std::string title) {
	for(int i = 0; i< tasks_.size(); ++i) {
		if(tasks_[i]->get_title() == title) {
			return tasks_[i];
		}
	}
	return nullptr;
}

void User::login() {
	is_loged = true;
//	std::string name;
//	std::string password;
//	std::cout << "enter name ";
//	std::cin >> name;
//	for(int i = 0; i< tasks_.size(); ++i) {
	//	if(tasks_[i]- == id) {
	//		tasks_[i].edittask();
	//	}
	//}
}

void User::logout() {
	is_loged = false;
}
