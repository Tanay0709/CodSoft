//to-do list
//To-Do List
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Task {
    string description;
    bool completed;

    Task(const string& desc) : description(desc), completed(false) {}
};

void addTask(vector<Task>& tasks, const string& description) {
    tasks.push_back(Task(description));
    cout << "Task added: " << description << endl;
}

void viewTasks(const vector<Task>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
        return;
    }
    cout << "Tasks:" << endl;
    for (size_t i = 0; i < tasks.size(); ++i) {
        cout << i + 1 << ". ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending]   ";
        }
        cout << tasks[i].description << endl;
    }
}

void markCompleted(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
        cout << "Task marked as completed: " << tasks[index - 1].description << endl;
    } else {
        cout << "Invalid task index." << endl;
    }
}

void removeTask(vector<Task>& tasks, int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        cout << "Task removed: " << tasks[index - 1].description << endl;
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task index." << endl;
    }
}

int main() {
    vector<Task> tasks;
    char choice;
    string description;
    int index;

    do {
        cout << "\nMenu:\n";
        cout << "1. Add Task\n";
        cout << "2. View Tasks\n";
        cout << "3. Mark Task as Completed\n";
        cout << "4. Remove Task\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                cin.ignore(); 
                cout << "Enter task description: ";
                getline(cin, description);
                addTask(tasks, description);
                break;
            case '2':
                viewTasks(tasks);
                break;
            case '3':
                cout << "Enter task index to mark as completed: ";
                cin >> index;
                markCompleted(tasks, index);
                break;
            case '4':
                cout << "Enter task index to remove: ";
                cin >> index;
                removeTask(tasks, index);
                break;
            case '5':
                cout << "Exiting program." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter again." << endl;
        }
    } while (choice != '5');

    return 0;
}
