#include <iostream>
#include <vector>
#include <string>

class Task {
public:
    std::string description;
    bool completed;

    Task(const std::string& desc) : description(desc), completed(false) {}
};

class ToDoList {
private:
    std::vector<Task> tasks;

public:
    void addTask(const std::string& description) {
        tasks.emplace_back(description);
        std::cout << "Task added: " << description << std::endl;
    }

    void markTaskCompleted(int index) {
        if (index < 0 || index >= tasks.size()) {
            std::cout << "Invalid task index." << std::endl;
            return;
        }
        tasks[index].completed = true;
        std::cout << "Task marked as completed: " << tasks[index].description << std::endl;
    }

    void viewTasks() const {
        if (tasks.empty()) {
            std::cout << "No tasks available." << std::endl;
            return;
        }
        std::cout << "Current Tasks:" << std::endl;
        for (size_t i = 0; i < tasks.size(); ++i) {
            std::cout << i + 1 << ". " << tasks[i].description 
                      << (tasks[i].completed ? " [Completed]" : " [Pending]") << std::endl;
        }
    }
};

int main() {
    ToDoList todoList;
    int choice;
    std::string taskDescription;

    do {
        std::cout << "\nTo-Do List Application" << std::endl;
        std::cout << "1. Add Task" << std::endl;
        std::cout << "2. Mark Task as Completed" << std::endl;
        std::cout << "3. View Tasks" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore(); // To ignore the newline character after the choice input

        switch (choice) {
            case 1:
                std::cout << "Enter task description: ";
                std::getline(std::cin, taskDescription);
                todoList.addTask(taskDescription);
                break;
            case 2:
                int taskIndex;
                std::cout << "Enter task number to mark as completed: ";
                std::cin >> taskIndex;
                todoList.markTaskCompleted(taskIndex - 1); // Convert to zero-based index
                break;
            case 3:
                todoList.viewTasks();
                break;
            case 4:
                std::cout << "Exiting the application." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    return 0;
}
