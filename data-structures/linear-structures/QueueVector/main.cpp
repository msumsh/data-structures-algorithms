#include "QueueVector.h"
#include <iostream>

int main() {
    QueueVector<int> queue1;
    //-----------enQueue----------
    queue1.enQueue(1);
    queue1.enQueue(2);
    queue1.enQueue(3);
    queue1.enQueue(4);
    std::cout << "Queue status: ";
    queue1.print();

    //----------deQueue----------
    queue1.deQueue();
    std::cout << "Queue status: ";
    queue1.print();

    //---------resize()---------------
    QueueVector<int> queue2(3);
    queue2.enQueue(1);
    queue2.enQueue(2);
    queue2.enQueue(3);
    queue2.enQueue(4); // OK

    //-------WrongQueueSize-------------
    try {
        int capacity = -100;
        QueueVector<int> queue3(capacity);
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    //---------QueueUnderflow-------------
    try {
        QueueVector<int> queue4;
        queue4.deQueue();
    }
    catch (std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}