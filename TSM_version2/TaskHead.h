#include "headers.h"

enum Priority {
	LOW,
	MEDIUM,
	HIGH,
	URGENT
};

enum State {
	NOT_STATED,
	IN_PROGRESS,
	COMPLETED
};

class Task{
private:
	std::string title_;
	std::string description_;
	std::string deadline_;
	std::string category_;
	int priority_;
	int state_;
	int uid_;
	int id_;
	static int ID_;
public:
	Task();
	Task(int uid);
	Task(int uid, const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, Priority priority, State state);
	Task(const Task& other);
	Task(Task&& other) noexcept;
	Task& operator=(const Task& other);
	Task& operator=(Task&& other) noexcept;
	~Task();
	bool operator==(const Task& other) const;
	bool operator!=(const Task& other) const;
	Task& operator++();
	const Task operator++(int);
	Task& operator--();
	const Task operator--(int);
	friend std::ostream& operator<<(std::ostream& os, const Task&);
	friend std::istream& operator>>(std::istream& is, Task&);
	void set_prio(Priority prio);
	void set_state(State state);
	void editTask(const std::string& title, const std::string& description, const std::string& deadline, const std::string& category, Priority priority, State state);
	void displayTask() const;
	int get_task_id() const;
	int get_uid() const;
	std::string get_title() const;
};
