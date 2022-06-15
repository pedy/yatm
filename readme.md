# Yet Another Task Manager

## What
### Requirements
The CLI should be a simple way of managing a list of tasks/todos.

* It must be able to compile on both Linux and macOS using CMake.
* You can use all of the features from C++17 and below.
* The tasks should be persisted on disk between execution of the CLI application. Binary, plaintext, encrypted, ... -- that's up to you.
* Single user -- no login required.

### Functionality
As a user, you should be able to:

* Add a task.
* Edit a task.
* List tasks.
* Search for a task.
* Mark a task as completed.

## Why
It's an interview process assignment.

## Build and Usage
```
$ cd build
$ cmake ..
$ cmake --build .
$ ./yatm
```
*(You can use `.\yatm.exe` in Windows)*


## Some Techincal Debts
- Search is case insensitive
- Data file loading has bare minimum error handling
- Data file sits just next to the execution path
- Used `cout` at many places which is better to use `cerr`
- Not tested on macOS

## Potential Improvements
- Unmark item
- Delete item
- Clear marked items
- Due date for each item
- Improve search speed