#include "todo.h"
#include <stdexcept>

void TodoList::init() {
    // TODO: set size to 0 and all task pointers to nullptr
    destroy();
    size = 0;
}

void TodoList::destroy() {
    // TODO: delete all tasks and reset pointers
    for (auto i=0; i<size; i++) {
        delete[] tasks[i];
        tasks[i] = nullptr;
    }
}

int TodoList::string_length(const char* str) const {
    // TODO: return the number of characters before '\0'
    int idx = 0;
    while (str[idx] != '\0') {
        idx++;
    }
    return idx;
}

void TodoList::string_copy(char* dest, const char* src) const {
    // TODO: copy characters from src to dest
    int length = string_length(src);
    for (auto i=0; i<length; i++) {
        dest[i] = src[i];
    }
}

void TodoList::add_task(const char* task) {
    // TODO: if full, throw. otherwise allocate and copy new task
    if (size >= MAX_TASKS) {
        throw std::out_of_range("Full tasks");
    }
    else {
        int length = string_length(task);
        tasks[size] = new char[length+1];
        string_copy(tasks[size], task);
        tasks[size][length] = '\0';
        size++;
    }
}

void TodoList::remove_task(int index) {
    // TODO: check bounds, delete task, shift left
    if (index < 0 || index >= size) {
        throw std::out_of_range("Index out of bound");
    }
    else {
        delete[] tasks[index];
        for (auto i=index; i<size; i++) {
            tasks[i] = tasks[i+1];
        }
        size--;
    }
    
}

const char** TodoList::get_pending_tasks(int& count) const {
    // TODO: set count and return task array
    count = size;
    return const_cast<const char**>(tasks);
}