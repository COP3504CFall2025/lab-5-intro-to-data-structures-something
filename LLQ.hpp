#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLQ : public QueueInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLQ() {
        list();
    }

    // Insertion
    void enqueue(const T& item) override {
        list.addTail(item);
    }

    // Deletion
    T dequeue() override {
        if (!list.getHead()) {
            throw std::runtime_error("LLQ Pop Failed");
        }
        T temp = list.getHead();
        list.removeHead();
        return temp;
    }

    // Access
    T peek() const override {
        if (!list.getHead()) {
            throw std::runtime_error("LLS Pop Failed");
        }
        return list.getHead();
    }

    // Getter
    std::size_t getSize() const noexcept override {
        return list.getSize();
    }

    ~LLQ() override{
        ~list();
    }

};