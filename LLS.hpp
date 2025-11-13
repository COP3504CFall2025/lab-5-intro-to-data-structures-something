#pragma once

#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <stdlib.h>
#include <stdexcept>

template <typename T>
class LLS : public StackInterface<T> {
private:
    LinkedList<T> list;
public:
    // Constructor
    LLS() {
        list();
    }

    // Insertion
    void push(const T& item) override {
        list.addHead(item);
    }

    // Deletion
    T pop() override {
        if (!list.getHead()) {
            throw std::runtime_error("LLS Pop Failed");
        }
        T temp = list.getHead();
        list.removeHead();
        return temp;
    }

    // Access
    T peek() const override {
        if (list.getHead()) {
            return list.getHead();
        }
        throw std::runtime_error("LLS Peek Failed");
    }

    //Getters
    std::size_t getSize() const noexcept override {
        return list.getSize();
    }

    ~LLS() override{
        ~list();
    }
};