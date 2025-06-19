#include "headers.h"

void register_user();
void login();
void logout();
void add_task() {
	Tasks_.push_back(active_user_.add_task());
}

void delete_task() {}
void edit_task();
void display_task();
