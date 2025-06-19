#include "headers.h"

void TaskManager::register_user() {
	std::string name, password;
	std::cout << "enter name :";
	std::cin >> name;
	std::cout << "enter password :";
	std::cin >> password;
	User* newuser = new User(name, password);
	Users_.push_back(newuser);
}

void TaskManager::login() {
	std::string name, password;
	std::cout << "enter name :";
	std::cin >> name;
	User *tmp = nullptr;
	for(int i = 0; i< Users_.size(); ++i) {
		if(Users_[i]->name_ == name) {
			tmp = Users_[i];
		}
	}
	if(tmp == nullptr) {
		std::cout << "no user found" << std::endl;
		return;
	}
	std::cout << "enter password :";
	std::cin >> password;
	if(tmp->password_ == password){
		tmp->login();
		active_user_ = tmp;
		return;
	}
	std::cout << "wrong password";
}

void TaskManager::logout() {
	active_user_->logout();
	active_user_ = nullptr;
}

void TaskManager::add_task() {
	Task* tmp = active_user_->add_task();
	if(tmp != nullptr){
		Tasks_.push_back(tmp);
	}
}

void TaskManager::delete_task(int taskid) {
	Task *tmp = nullptr;
	for(int i = 0; i< Tasks_.size(); ++i) {
		if(Tasks_[i]->get_task_id() == taskid) {
			tmp = Tasks_[i];
		}
	}
	if(tmp == nullptr) {
		std::cout << "no task found" << std::endl;
		return;
	}
	if(tmp->get_uid() == active_user_->id_) {
		active_user_->delete_task(taskid);
	}
}

void TaskManager::edit_task(int taskid) {
	Task *tmp = nullptr;
	for(int i = 0; i< Tasks_.size(); ++i) {
		if(Tasks_[i]->get_task_id() == taskid) {
			tmp = Tasks_[i];
		}
	}
	if(tmp->get_uid() == active_user_->id_) {
		active_user_->edit_task(taskid);
	}
}

void TaskManager::TaskManager::display_all_tasks() {
	for(int i = 0; i < Users_.size(); ++i) {
		Users_[i]->list_tasks();
	}
}
