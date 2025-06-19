#include "headers.h"

class TaskManager{
private:
	User* active_user_;
	std::vector<Task*> Tasks_;
	std::vector<User*> Users_;
public:
	void register_user();
	void login();
	void logout();
	void add_task();
	void delete_task(int);
	void edit_task(int);
	void display_all_tasks();
};
