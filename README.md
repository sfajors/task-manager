# Task Manager

## Overview
Task Manager is a simple C++ console application that helps users manage their tasks. It provides functionalities such as adding a task, deleting a task, marking a task as done, and listing all tasks.

## Features
- **Add Task**: Add a new task with a unique name.
- **Delete Task**: Delete a task by its ID.
- **Mark Task as Done**: Mark any task as done by its ID.
- **List Tasks**: List all the existing tasks with their status.

## Prerequisites
- A C++ compiler (like g++, clang, or Visual C++).
- Basic knowledge of using the command line.

## Compilation
1. Open a terminal (Command Prompt, PowerShell, or any Unix-based terminal).
2. Navigate to the directory containing the `task-manager.cpp` file.
3. Run the following command to compile the code:
    ```sh
    g++ -o task-manager task-manager.cpp
    ```
    This will create an executable file named `task-manager` in the same directory.

## Running the Application
1. In the terminal, run the application by entering:
    ```sh
    ./task-manager
    ```
   (or `task-manager.exe` on Windows)
2. Once the application starts, you will be prompted to enter commands to manage tasks. The available commands are:
    - `add`: Add a new task.
    - `delete`: Delete an existing task by its ID.
    - `done`: Mark a task as done.
    - `list`: List all tasks.
    - `exit`: Exit the application.

## Usage Example
```
Enter command (add, list, delete, done, exit): add
Enter task name: Buy groceries
Task added successfully
```
```
Enter command (add, list, delete, done, exit): list
ID: 1 | Name: Buy groceries | Status: Pending
```
```
Enter command (add, list, delete, done, exit): done
Enter task ID: 1
Task marked as done.
```
```
Enter command (add, list, delete, done, exit): list
ID: 1 | Name: Buy groceries | Status: Done
```
```
Enter command (add, list, delete, done, exit): exit
Exiting the application.
```

## License
MIT License
