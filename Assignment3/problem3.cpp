#include <iostream>
#include <cstring>

using namespace std;

class LogBuffer {
private:
    char* buffer;
    int capacity;
    int size;
    static int instanceCount;

public:

    LogBuffer(int capacity) : capacity(capacity), size(0) {
        buffer = new char[this->capacity];
        buffer[0] = '\0';
        instanceCount++;
        cout << "[LogBuffer Created] capacity=" << this->capacity << endl;
    }


    LogBuffer(const LogBuffer& other) : capacity(other.capacity), size(other.size) {
        buffer = new char[capacity];
        memcpy(buffer, other.buffer, size + 1); 
        instanceCount++;
        cout << "[LogBuffer Deep Copied] capacity=" << capacity << endl;
    }


    LogBuffer& operator=(const LogBuffer& other) {
        if (this == &other) {
            cout << "[Self-assignment detected — no operation]" << endl;
            return *this;
        }

       
        delete[] buffer;

        capacity = other.capacity;
        size = other.size;
        buffer = new char[capacity];
        memcpy(buffer, other.buffer, size + 1);

        cout << "[LogBuffer Assigned]" << endl;
        return *this;
    }


    ~LogBuffer() {
        delete[] buffer;
        instanceCount--;
        cout << "[LogBuffer Destroyed]" << endl;
    }


    void append(const char* msg) {
        if (!msg) return;

        int msgLen = strlen(msg);
        int available = capacity - 1 - size; 

        if (available <= 0) return;

        int toCopy = (msgLen < available) ? msgLen : available;
        memcpy(buffer + size, msg, toCopy);
        size += toCopy;
        buffer[size] = '\0';
    }


    void print() const {
        cout << buffer << endl;
    }


    void clear() {
        size = 0;
        if (capacity > 0) {
            buffer[0] = '\0';
        }
    }


    static int getInstanceCount() {
        return instanceCount;
    }
};


int LogBuffer::instanceCount = 0;

int main() {
    
    LogBuffer log1(256);
    log1.append("Server started on port 8080");
    log1.append(" | Request received from 192.168.1.10");
    log1.print();

  
    LogBuffer log2 = log1; 
    log2.append(" | Cached response sent");
    cout << "log1 : "; log1.print(); 
    cout << "log2 : "; log2.print();

  
    LogBuffer log3(128);
    log3 = log1; 
    cout << "log3 : "; log3.print();


    log1 = log1;
    log1.print();

    cout << "Live LogBuffer objects : " << LogBuffer::getInstanceCount() << endl;

    return 0;
   
}