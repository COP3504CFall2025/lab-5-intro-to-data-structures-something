#pragma once

#include <cstddef>
#include <stdexcept>
#include "Interfaces.hpp"
#include "LinkedList.hpp"
#include <utility>



template <typename T>
class LLDQ : public DequeInterface<T> {
private:
    LinkedList<T> list;

public:
    // Constructor
    LLDQ() = default;

    // Core Insertion Operations
    void pushFront(const T& item) override {
        list.addHead(item);
    }
    void pushBack(const T& item) override {
        list.addHead(item);
    }

    // Core Removal Operations
    T popFront() override {
        if (!list.getHead()) {
            throw std::runtime_error("LLDQ popFront Failed");
        }
        T temp = list.getHead()->data;
        list.removeHead();
        return temp;
    }
    T popBack() override {
        if (!list.getTail()) {
            throw std::runtime_error("LLDQ popBack Failed");
        }
        T temp = list.getTail()->data;
        list.removeTail();
        return temp;
    }

    // Element Accessors
    const T& front() const override {
        if (!list.getHead()) {
            throw std::runtime_error("LLDQ front Failed");
        }
        return list.getHead()->data;
    }
    const T& back() const override {
        if (!list.getTail()) {
            throw std::runtime_error("LLDQ back Failed");
        }
        return list.getTail()->data;
    }

    // Getter
    std::size_t getSize() const noexcept override {
        return list.getCount();
    }


};






