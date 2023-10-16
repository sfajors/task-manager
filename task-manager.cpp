/* Task Class*/
#include <string>

class Task {
private:
    int id;
    std::string name;
    bool done;

public:
    Task(int id, const std::string& name) : id(id), name(name), done(false) {}

    void markDone() {
        done = true;
    }

    bool isDone() const {
        return done;
    }

    int getId() const {
        return id;
    }

    std::string getName() const {
        return name;
    }
};

/* TaskManager Class */
#include <vector>
#include <algorithm>

class TaskManager {
private:
    std::vector<Task> tasks;
    int nextId = 1;

public:
    void addTask(const std::string& name) {
        tasks.push_back(Task(nextId++, name));
    }

    bool deleteTask(int id) {
        auto it = std::remove_if(tasks.begin(), tasks.end(),
                                 [id](const Task& task) { return task.getId() == id; });
        if(it == tasks.end()) return false;
        tasks.erase(it, tasks.end());
        return true;
    }

    bool markTaskDone(int id) {
        for (auto& task : tasks) {
            if (task.getId() == id) {
                task.markDone();
                return true;
            }
        }
        return false;
    }

    std::vector<Task> listTasks() const {
        return tasks;
    }
};

/* Main Function */
#include <iostream>
#include <limits>

int main() {
    TaskManager taskManager;
    std::string command;

    while (true) {
        std::cout << "Enter command (add, list, delete, done, exit): ";
        std::cin >> command;

        if (command == "add") {
            std::cout << "Enter task name: ";
            std::string taskName;
            std::cin.ignore();  // clear newline left in the buffer
            std::getline(std::cin, taskName);
            if(taskName.empty()) {
                std::cout << "Error: Task name cannot be empty!" << std::endl;
                continue;
            }
            taskManager.addTask(taskName);
        } else if (command == "list") {
            auto tasks = taskManager.listTasks();
            if(tasks.empty()) {
                std::cout << "No tasks available." << std::endl;
                continue;
            }
            for (const auto& task : tasks) {
                std::cout << "[" << task.getId() << "] " << task.getName();
                if (task.isDone()) {
                    std::cout << " (Done)";
                }
                std::cout << std::endl;
            }
        } else if (command == "delete") {
            std::cout << "Enter task ID to delete: ";
            int id;
            if(!(std::cin >> id)) {
                std::cout << "Error: Invalid task ID!" << std::endl;
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                continue;
            }
            if(!taskManager.deleteTask(id)) {
                std::cout << "Error: Task with ID " << id << " not found!" << std::endl;
            }
        } else if (command == "done") {
            std::cout << "Enter task ID to mark as done: ";
            int id;
            if(!(std::cin >> id)) {
                std::cout << "Error: Invalid task ID!" << std::endl;
                std::cin.clear(); // clear the error flag
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
                continue;
            }
            if(!taskManager.markTaskDone(id)) {
                std::cout << "Error: Task with ID " << id << " not found!" << std::endl;
            }
        } else if (command == "exit") {
            break;
        } else {
            std::cout << "Error: Invalid command!" << std::endl;
        }
    }

    return 0;
}
