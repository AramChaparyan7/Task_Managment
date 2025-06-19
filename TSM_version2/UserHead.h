#include "headers.h"

class User{
friend class TaskManager;
private:
	static int ID_;
	int id_;
	std::string name_;
	std::string password_;
	std::vector<Task*> tasks_;
	bool is_loged;
public:
	User();
	User(std::string name, std::string password);
	User(const User&);
	User(User&&) noexcept;
	User& operator=(const User&);
	User& operator=(User&&) noexcept;
	~User();
	Task* add_task();
	void delete_task(int);
	void edit_task(int);
	void list_tasks();
	Task* search_tasks(std::string);
	void login();
	void logout();
};
