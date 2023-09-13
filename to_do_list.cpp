/*
Task 4:TO-DO LIST 
Details: Build a simple console-based to-do list manager that allows users to add, view, and delete tasks

Intern name: Imam Hasan
Intern ID:CS07WX36582
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Task {
    string description;
    bool completed;
};

vector<Task> tasks;

void addTask(string description) {
    Task task;
    task.description = description;
    task.completed = false;
    tasks.push_back(task);
}

// Function to view tasks
void viewTasks() {
    cout << "To-Do List:" << endl;
    for (size_t i = 0; i < tasks.size(); i++) {
        cout << "[" << i + 1 << "] ";
        if (tasks[i].completed) {
            cout << "[Completed] ";
        } else {
            cout << "[Pending]   ";
        }
        cout << tasks[i].description << endl;
    }
}

void markTaskAsCompleted(int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks[index - 1].completed = true;
    } else {
        cout << "Invalid task number. Please enter a valid task number." << endl;
    }
}

void removeTask(int index) {
    if (index >= 1 && index <= static_cast<int>(tasks.size())) {
        tasks.erase(tasks.begin() + index - 1);
    } else {
        cout << "Invalid task number. Please enter a valid task number." << endl;
    }
}

int main() {
    while (true) {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Quit" << endl;

        int choice;
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 1) {
            cin.ignore(); // Clear the newline character
            string description;
            cout << "Enter task description: ";
            getline(cin, description);
            addTask(description);
        } else if (choice == 2) {
            viewTasks();
        } else if (choice == 3) {
            int index;
            cout << "Enter the task number to mark as completed: ";
            cin >> index;
            markTaskAsCompleted(index);
        } else if (choice == 4) {
            int index;
            cout << "Enter the task number to remove: ";
            cin >> index;
            removeTask(index);
        } else if (choice == 5) {
            break;
        } else {
            cout << "Invalid choice. Please enter a valid option." << endl;
        }
    }

    return 0;
}

