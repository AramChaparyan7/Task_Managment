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
		if(active_user_ != nullptr){
			active_user_->is_loged = false;
		}
		tmp->login();
		active_user_ = tmp;
		return;
	} else {
		std::cout << "wrong password";
	}
}

void TaskManager::logout() {
	active_user_->logout();
	active_user_ = nullptr;
}

void TaskManager::add_task() {
	if(active_user_ == nullptr) {
		std::cout << "no user loged in" << std::endl;
		return;
	}
	Task* tmp = active_user_->add_task();
	if(tmp != nullptr){
		Tasks_.push_back(tmp);
	}
}

void TaskManager::delete_task() {
	if(active_user_ == nullptr) {
		std::cout << "no user loged in" << std::endl;
		return;
	}
	int taskid = 0;
	std::cout << "enter task id: ";
	std::cin >> taskid;
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
	}else{
		std::cout << "this task belong to other user" << std::endl;
	}

}

void TaskManager::edit_task() {
	if(active_user_ == nullptr) {
		std::cout << "no user loged in" << std::endl;
		return;
	}
	int taskid = 0;
	std::cout << "enter task id: ";
	std::cin >> taskid;
	
	Task *tmp = nullptr;
	for(int i = 0; i< Tasks_.size(); ++i) {
		if(Tasks_[i]->get_task_id() == taskid) {
			tmp = Tasks_[i];
		}
	}
	if(tmp == nullptr) {
		std::cout << "NO task found" << std::endl;
		return;
	}
	if(tmp->get_uid() == active_user_->id_) {
		active_user_->edit_task(taskid);
	}else{
		std::cout << "this task belong to other user" << std::endl;
	}
}

void TaskManager::TaskManager::display_all_tasks() {
	for(int i = 0; i < Users_.size(); ++i) {
		Users_[i]->list_tasks();
	}
}
