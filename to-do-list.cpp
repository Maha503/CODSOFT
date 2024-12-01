#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\nTo-Do List Menu:\n";
    cout << "1. Add Task\n";
    cout << "2. View Tasks\n";
    cout << "3. Delete Task\n";
    cout << "4. Exit\n";
    cout << "Enter your choice: ";
}

// Function to add a task
void addTask(vector<string>& tasks) {
    string task;
    cout << "Enter the task: ";
    cin.ignore(); // To ignore the newline character left by the previous input
    getline(cin, task); // Read a full line including spaces
    tasks.push_back(task);
    cout << "Task added successfully!" << endl;
}

// Function to view all tasks
void viewTasks(const vector<string>& tasks) {
    if (tasks.empty()) {
        cout << "No tasks to display." << endl;
    } else {
        cout << "\nYour To-Do List:\n";
        for (int i = 0; i < tasks.size(); ++i) {
            cout << i + 1 << ". " << tasks[i] << endl;
        }
    }
}

// Function to delete a task
void deleteTask(vector<string>& tasks) {
    int taskNumber;
    cout << "Enter the task number to delete: ";
    cin >> taskNumber;
    
    // Check if the task number is valid
    if (taskNumber > 0 && taskNumber <= tasks.size()) {
        tasks.erase(tasks.begin() + taskNumber - 1); // Delete the task from the vector
        cout << "Task deleted successfully!" << endl;
    } else {
        cout << "Invalid task number!" << endl;
    }
}

int main() {
    vector<string> tasks; // Vector to store tasks
    int choice;

    do {
        displayMenu(); // Show the menu
        cin >> choice; // User input

        switch (choice) {
            case 1:
                addTask(tasks); // Add a new task
                break;
            case 2:
                viewTasks(tasks); // Display all tasks
                break;
            case 3:
                deleteTask(tasks); // Delete a task
                break;
            case 4:
                cout << "Exiting the program. Goodbye!" << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 4); // Keep running until the user chooses to exit

    return 0;
}



