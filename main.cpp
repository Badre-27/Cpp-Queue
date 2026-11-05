#include <iostream>
#include <cstddef>
#include <stdexcept>
#include <string>

template<typename T, std::size_t Capacity>
class Queue {

private:
    T m_data[Capacity];
    std::size_t m_front;
    std::size_t m_size;

public:
    Queue() : m_front{0}, m_size{0} {}

    std::size_t size() const {
        return m_size;
    }

    bool empty() const {
        return m_size == 0;
    }

    bool full() const {
        return m_size == Capacity;
    }

    constexpr std::size_t capacity() const {
        return Capacity;
    }

    void enqueue(const T& value) {
        if (m_size == Capacity) {
            throw std::overflow_error{"Queue is full"};
        }
        std::size_t rear{(m_front + m_size) % Capacity};
        m_data[rear] = value;
        ++m_size;
    }

    T dequeue() {
        if (m_size == 0) {
            throw std::underflow_error{"Queue is empty"};
        }
        T value{m_data[m_front]};
        m_front = (m_front + 1) % Capacity;
        --m_size;
        return value;
    }

    T& front() {
        if (m_size == 0) {
            throw std::underflow_error{"Queue is empty"};
        }
        return m_data[m_front];
    }

    const T& front() const {
        if (m_size == 0) {
            throw std::underflow_error{"Queue is empty"};
        }
        return m_data[m_front];
    }

    T& back() {
        if (m_size == 0) {
            throw std::underflow_error{"Queue is empty"};
        }
        std::size_t rear{(m_front + m_size - 1) % Capacity};
        return m_data[rear];
    }

    const T& back() const {
        if (m_size == 0) {
            throw std::underflow_error{"Queue is empty"};
        }
        std::size_t rear{(m_front + m_size - 1) % Capacity};
        return m_data[rear];
    }

    void clear() {
        m_front = 0;
        m_size = 0;
    }
};

struct Task {
    int id;
    std::string name;
};

int main() {
    Queue<int, 5> queue;

    std::cout << "Queue capacity: " << queue.capacity() << '\n';
    std::cout << "Queue size: " << queue.size() << '\n';
    std::cout << "Queue is empty: " << (queue.empty() ? "true" : "false") << '\n';

    std::cout << "Enqueuing: 10 20 30" << '\n';
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);

    std::cout << "Front: " << queue.front() << ", Back: " << queue.back() << '\n';
    std::cout << "Size: " << queue.size() << '\n';

    std::cout << "Dequeued: " << queue.dequeue() << '\n';
    std::cout << "Dequeued: " << queue.dequeue() << '\n';

    std::cout << "Front after dequeues: " << queue.front() << '\n';
    std::cout << "Size: " << queue.size() << '\n';

    std::cout << '\n';
    std::cout << "=== Task Scheduling ===" << '\n';

    Queue<Task, 10> taskQueue;

    taskQueue.enqueue(Task{1, "Compile code"});
    taskQueue.enqueue(Task{2, "Run tests"});
    taskQueue.enqueue(Task{3, "Deploy app"});

    while (!taskQueue.empty()) {
        Task task{taskQueue.dequeue()};
        std::cout << "Processing: Task " << task.id << " - " << task.name << '\n';
    }

    std::cout << "All tasks completed!" << '\n';

    std::cout << '\n';
    std::cout << "=== Queue Operations ===" << '\n';

    queue.clear();
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);
    std::cout << "After enqueue 1,2,3,4,5: size=" << queue.size()
              << ", full=" << (queue.full() ? "true" : "false") << '\n';

    queue.clear();
    std::cout << "After clear: size=" << queue.size()
              << ", empty=" << (queue.empty() ? "true" : "false") << '\n';

    std::cout << '\n';
    std::cout << "=== Wraparound Demo ===" << '\n';

    Queue<int, 3> small;
    small.enqueue(1);
    small.enqueue(2);
    small.enqueue(3);
    std::cout << "Dequeued: " << small.dequeue() << '\n';
    std::cout << "Dequeued: " << small.dequeue() << '\n';
    small.enqueue(4);
    small.enqueue(5);
    std::cout << "After wraparound - Front: " << small.front()
              << ", Back: " << small.back() << '\n';
    std::cout << "Dequeued: " << small.dequeue() << '\n';
    std::cout << "Dequeued: " << small.dequeue() << '\n';
    std::cout << "Dequeued: " << small.dequeue() << '\n';

    std::cout << '\n';
    std::cout << "=== Error Handling ===" << '\n';

    try {
        small.dequeue();
    } catch (const std::underflow_error& e) {
        std::cout << "Caught underflow: " << e.what() << '\n';
    }

    small.enqueue(1);
    small.enqueue(2);
    small.enqueue(3);
    try {
        small.enqueue(4);
    } catch (const std::overflow_error& e) {
        std::cout << "Caught overflow: " << e.what() << '\n';
    }

    return 0;
}
