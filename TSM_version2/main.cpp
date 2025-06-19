#include "headers.h"

int main() {
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
				{
				int id = 0;
				std::cout << "enter task id: ";
				std::cin >> id;
				TSM.delete_task(id);
				break;
				}
			case '6':
				{
				int id = 0;
				std::cout << "enter task id: ";
				std::cin >> id;
				TSM.edit_task(id);
				break;
				}
			case '7':
				TSM.display_all_tasks();
		}
	}
	return 0;
}
