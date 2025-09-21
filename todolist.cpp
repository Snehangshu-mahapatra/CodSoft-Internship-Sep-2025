#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

void addTask(vector<Task> &tasks) {
    cin.ignore();
    string desc;
    cout << "\n Enter a new task: ";
    getline(cin, desc);
    tasks.push_back({desc, false});
    cout << "Task added to your list.\n";
}

void viewTasks(const vector<Task> &tasks) {
    if (tasks.empty()) {
        cout << "\n No tasks in list.\n";
        return;
    }
    cout << "\nTo-Do List:\n";
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << i + 1 << ". " << tasks[i].description
             << " [" << (tasks[i].completed ? "Completed" : "Pending") << "]\n";
    }
}

void markTaskCompleted(vector<Task> &tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;
    int index;
    cout << "\nEnter the task number to mark as completed: ";
    cin >> index;
    if (index > 0 && index <= (int)tasks.size()) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed!\n";
    } else {
        cout << " Invalid task number!\n";
    }
}

void removeTask(vector<Task> &tasks) {
    viewTasks(tasks);
    if (tasks.empty()) return;
    int index;
    cout << "\nEnter the task number to remove: ";
    cin >> index;
    if (index > 0 && index <= (int)tasks.size()) {
        cout << " Task \"" << tasks[index - 1].description << "\"Task removed.\n";
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task number!\n";
    }
}

int main() {
    vector<Task> tasks;
    int choice;

    cout << " Create to Your To-Do List\n";

    do {
        cout << "\nChoose an option:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addTask(tasks); break;
            case 2: viewTasks(tasks); break;
            case 3: markTaskCompleted(tasks); break;
            case 4: removeTask(tasks); break;
            case 5: cout << "\nKeep grinding and smashing your tasks!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);

    return 0;
}

