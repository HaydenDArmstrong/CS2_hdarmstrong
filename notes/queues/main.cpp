#include <iostream>
#include <cmath> // for abs in size()
using namespace std;

template <class T1>
class Queue {
private:
    static const int maxQueue = 100;
    T1 _queueArr[maxQueue];
    int _beg, _end;

public:
    Queue();
    void enqueue(T1);
    T1 dequeue();
    bool empty();
    bool full();
    int size();
    T1 front();
    T1 end();
};

int main() {
    Queue<int> myQueue;
    int inData;

    cout << "Enter -99999 to quit" << endl;
    while (true) {
        cout << "Enter a number: ";
        cin >> inData;
        if (inData == -99999) break;  // Exit condition added
        myQueue.enqueue(inData);
    }

    cout << "Queue Size: " << myQueue.size() << endl;
    cout <<  "Queue Front: " << myQueue.front() << endl;
    cout <<  "Queue end: " << myQueue.end() << endl;

    while (myQueue.size() > 0)
    {
        cout << "data: " << myQueue.dequeue() << " ";
    }
    return 0;
}

template <class T1>
Queue<T1>::Queue() {
    _beg = -1;
    _end = -1;
}

template <class T1>
void Queue<T1>::enqueue(T1 data) {
    if (full()) {
        cout << "Queue is full" << endl;
        return;
    }
    if (empty()) {
        _beg = 0;
    }
    _end = (_end + 1) % maxQueue;
    _queueArr[_end] = data;
}

template <class T1>
T1 Queue<T1>::dequeue() {
    if (empty()) {
        cout << "Queue is empty" << endl;
        return -1;  // Default return value for empty queue
    }
    T1 tmpData = _queueArr[_beg];
     if (_beg == _end) {  // Queue becomes empty after dequeue
         _beg = -1;
         _end = -1;
     } else 
     {
         _beg = (_beg + 1) % maxQueue;
     }
    return tmpData;
}

template <class T1>
bool Queue<T1>::empty() {
    return _beg == -1;
}

template <class T1>
bool Queue<T1>::full() {
    return (_end + 1) % maxQueue == _beg;
}

template <class T1>
int Queue<T1>::size() {
    if (empty()) return 0;
    if (_end >= _beg)
        return _end - _beg + 1;
    return maxQueue - _beg + _end + 1;
}

template <class T1>
T1 Queue<T1>::front() {
    if (!empty()) {
        return _queueArr[_beg];
    } else {
        cout << "Queue is empty" << endl;
        return -1;
    }
}

template <class T1>
T1 Queue<T1>::end() {
    if (!empty()) {
        return _queueArr[_end];
    } else {
        cout << "Queue is empty" << endl;
        return -1;
    }
}
