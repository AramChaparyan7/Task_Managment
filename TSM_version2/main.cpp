#include "headers.h"
#include <gtest/gtest.h>

int main(int argv, char** argc) {
	char c=0;
	TaskManager TSM;
	while(c != 'q') {
		std::cout << std::endl;
		std::cout << "1:Register User" << std::endl;
		std::cout << "2:Login" << std::endl;
		std::cout << "3:Logout" << std::endl;
		std::cout << "4:Add Task" << std::endl;
		std::cout << "5:Delet Task" << std::endl;
		std::cout << "6:Edit Task" << std::endl;
		std::cout << "7:Display Tasks" << std::endl;
		std::cout << "(q for exit)" << std::endl;
		std::cin >> c;
		switch(c) {
			case '1':
				TSM.register_user();
				break;
			case '2':
				TSM.login();
				break;
			case '3':
				TSM.logout();
				break;
			case '4':
				TSM.add_task();
				break;
			case '5':
				TSM.delete_task();
				break;
			case '6':
				TSM.edit_task();
				break;
			case '7':
				TSM.display_all_tasks();
				break;
		}
	}
	::testing::InitGoogleTest(&argv, argc);
	return RUN_ALL_TESTS();
}

TEST(Task_Manager, makeUser) {
	User u("name", "password");
	EXPECT_EQ(u.name_,"name");	
	EXPECT_EQ(u.password_, "password");	
	EXPECT_EQ(u.is_loged, false);
	User u1(u);
	EXPECT_EQ(u1.name_, "name");	
	User u2;
	u2 = u;
	EXPECT_EQ(u2.name_, "name");	
}

TEST(tasktest, task_functions) {
	Task t(1, "title", "description" , "deadline", "category", static_cast<Priority>(1), static_cast<State>(1));
	EXPECT_EQ(t.uid_, 1);
	EXPECT_EQ(t.title_, "title");
	EXPECT_EQ(t.description_, "description");
	EXPECT_EQ(t.category_, "category");
	EXPECT_EQ(t.deadline_, "deadline");
	EXPECT_EQ(t.state_, State::IN_PROGRESS);
	EXPECT_EQ(t.priority_, Priority::MEDIUM);
}

TEST(Task_Manager, TaskManagerTest) {
	TaskManager tsm;
	EXPECT_EQ(tsm.Users_.size(), 0);
	EXPECT_EQ(tsm.Tasks_.size(), 0);
}
