#include <vector>
#include <iostream>
class MyCircularDeque {
private:
    std::vector<int> deque;
    int front;
    int rear;
    int size;
    int capacity;

public:
    MyCircularDeque(int k) {
        capacity = k;
        deque.resize(k);
        front = 0;
        rear = 0;
        size = 0;
    }

    bool insertFront(int value) {
        if (isFull())
            return false;

        front = (front - 1 + capacity) % capacity;
        deque[front] = value;
        size++;
        return true;
    }

    bool insertLast(int value) {
        if (isFull())
            return false;

        deque[rear] = value;
        rear = (rear + 1) % capacity;
        size++;
        return true;
    }

    bool deleteFront() {
        if (isEmpty())
            return false;

        front = (front + 1) % capacity;
        size--;
        return true;
    }

    bool deleteLast() {
        if (isEmpty())
            return false;

        rear = (rear - 1 + capacity) % capacity;
        size--;
        return true;
    }

    int getFront() {
        if (isEmpty())
            return -1;

        return deque[front];
    }

    int getRear() {
        if (isEmpty())
            return -1;

        return deque[(rear - 1 + capacity) % capacity];
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == capacity;
    }
};

int main() {
    MyCircularDeque circularDeque(3);
    std::vector<std::string> output;

    output.push_back("null");

    if (circularDeque.insertLast(1))
        output.push_back("true");
    else
        output.push_back("false");

    if (circularDeque.insertLast(2))
        output.push_back("true");
    else
        output.push_back("false");

    if (circularDeque.insertFront(3))
        output.push_back("true");
    else
        output.push_back("false");

    if (circularDeque.insertFront(4))
        output.push_back("true");
    else
        output.push_back("false");

    output.push_back(std::to_string(circularDeque.getRear()));

    if (circularDeque.isFull())
        output.push_back("true");
    else
        output.push_back("false");

    if (circularDeque.deleteLast())
        output.push_back("true");
    else
        output.push_back("false");

    if (circularDeque.insertFront(4))
        output.push_back("true");
    else
        output.push_back("false");

    output.push_back(std::to_string(circularDeque.getFront()));

    // Print the output
    for (const std::string& str : output) {
        std::cout << str << " ";
    }
    std::cout << std::endl;

    return 0;
}
