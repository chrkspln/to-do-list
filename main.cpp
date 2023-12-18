#include <iostream>
#include <map>
#include <string>

void add_task();
void delete_task();
void mark_as_done();
void edit_task();
void display_all_tasks();

int main()
{
	std::cout << "welcome to a to-do list program!"
		" here you can add, delete, edit and display"
		" all of your tasks! don't forget to mark them"
		" as done when you complete them ;)\n";
	choices:
	std::cout << "available commands:\n"
		"A - add new task\t D - delete a task\n"
		"E - edit a task\t V - view all tasks\n"
		"M - mark a task as done\t Q - quit the program\n";
	std::cout << "enter your choice: ";
	char answer{};
	std::cin >> answer;
	//i'll need to check the input here
	switch (std::tolower(answer))
	{
	case 'a':
		add_task();
		goto choices;
	case 'd':
		delete_task();
		goto choices;
	case 'e':
		edit_task();
		goto choices;
	case 'v':
		display_all_tasks();
		goto choices;
	case 'm':
		mark_as_done();
		goto choices;
	case 'q':
		return 0;
	default:
		std::cout << "input is not one of the choices. try again.\n";
		goto choices;
	}
	return 0;
}

std::map<std::string, bool> task_list{};
void add_task()
{
	std::cout << "enter task to add here (first word wont be read): ";
	std::string task;
	std::cin.clear();
	while (!(std::cin >> task) and (std::cin.peek() != '\n'));
	std::getline(std::cin, task, '\n');
	task_list.insert(std::pair<std::string, bool>(task, false));
	std::cout << task << '\n';
	std::cout << "the task has been added to the list.\n";
}

  void delete_task()
  {
	std::cout << "enter task to delete here: ";
	std::string task;
	while (!(std::cin >> task) and (std::cin.peek() != '\n'));
	std::getline(std::cin, task);
	if (task_list.at(task)) {
		task_list.erase(task);
		std::cout << "the task has been deleted!\n";
	}
	else
	{
		std::cout << "no such task on the list.\n";
	}
}

  void mark_as_done()
{
	std::cout << "enter task to mark as done here: ";
	std::string task;
	while (!(std::cin >> task) and (std::cin.peek() != '\n'));
	std::getline(std::cin, task);
	const auto found_task = task_list.find(task);
	if (found_task != task_list.end())
	{
		if (found_task->second)
		{
			std::cout << "task is already marked as done.\n";
		}
		found_task->second = true;
	}
	std::cout << "task is marked as done. good job!\n";
}

  void edit_task()
{
	std::cout << "enter task to edit here: ";
	std::string task;
	while (!(std::cin >> task) and (std::cin.peek() != '\n'));
	std::getline(std::cin, task);
	const auto task_to_edit = task_list.find(task);
	if (task_to_edit != task_list.end())
	{
		std::string edited_task;
		std::cout << "enter edited task's text: ";
		std::cin.clear();
		std::getline(std::cin, edited_task);
		task_list.insert(std::pair<std::string, bool>(edited_task, task_to_edit->second));
		task_list.erase(task_to_edit);
	}
}

void display_all_tasks()
{
	std::string is_done{};
	for (auto it = task_list.begin(); it != task_list.end(); ++it) {
		it->second ? is_done = "done!" : is_done = "in progress";
		std::cout << it->first << " is " << is_done << '\n';
	}
}
