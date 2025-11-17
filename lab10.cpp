#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

// Template class definition
template <typename T>
class List {
private:
    T *elements;
    int capacity;
    int currentSize;

    void resize(int newCapacity) {
        T *newArray = new T[newCapacity];
        for (int i = 0; i < currentSize; ++i) {
            newArray[i] = elements[i];
        }
        delete[] elements;
        elements = newArray;
        capacity = newCapacity;
    }

public:
    List() : elements(nullptr), capacity(0), currentSize(0) {}
    ~List() { delete[] elements; }

    T *begin() { return elements; }
    T *end() { return &elements[currentSize]; }

    void add(const T &element) {
        if (currentSize == capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            resize(newCapacity);
        }
        elements[currentSize++] = element;
    }

    int size() const { return currentSize; }

    T &operator[](int index) {
        if (index >= currentSize) {
            throw out_of_range("Index out of range");
        }
        return elements[index];
    }

    void remove(int index) {
        if (index >= currentSize) {
            throw out_of_range("Index out of range");
        }
        for (int i = index; i < currentSize - 1; i++) {
            elements[i] = elements[i + 1];
        }
        currentSize--;
    }

    void insert(const T &element, int index) {
        if (currentSize == capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            resize(newCapacity);
        }
        currentSize++;
        for (int i = currentSize; i > index; i--) {
            elements[i] = elements[i - 1];
        }
        elements[index] = element;
    }
};

class shape {
protected:
    char *name;
public:
    shape(const char *n) {
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    virtual ~shape() {
    }

    virtual float calculate_area() const = 0;

    virtual void show() const {
        cout << "Shape: " << name << endl;
    }
};

class _2Dshape : public shape {
protected:
    float area;
public:
    _2Dshape() : shape("N/A") {}
    _2Dshape(const char *n) : shape(n) {}
    virtual ~_2Dshape() {}

    float calculate_area() const override {
        return 0;
    }

    void show() const override {
        shape::show();
        cout << "Area: " << calculate_area() << endl;
    }
};

class Circle : public _2Dshape {
protected:
    float radius;
public:
    Circle(const char *n, float r) : _2Dshape(n), radius(r) {}

    void show() const override {
        _2Dshape::show();
        cout << "Type: Circle\n";
        cout << "Radius = " << radius << endl;
    }

    float calculate_area() const override {
        return radius * radius * 3.14;
    }
};

class Square : public _2Dshape {
protected:
    float a;
public:
    Square(const char *n, float side) : _2Dshape(n), a(side) {}

    void show() const override {
        _2Dshape::show();
        cout << "Type: Square\n";
        cout << "Side = " << a << endl;
    }

    float calculate_area() const override {
        return a * a;
    }
};

class Triangle : public _2Dshape {
protected:
    float a;
public:
    Triangle(const char *n, float side) : _2Dshape(n), a(side) {}

    void show() const override {
        _2Dshape::show();
        cout << "Type: Triangle\n";
        cout << "Side = " << a << endl;
    }

    float calculate_area() const override {
        return (a * a * 0.5);
    }
};

bool compareByArea(shape *a, shape *b) {
    return a->calculate_area() < b->calculate_area();
}

int main() {
    srand(time(0));

    List<_2Dshape *> a;

    for (int i = 0; i < 20; i++) {
        int k = (rand() % 3) + 1;
        float c = rand() % 20;

        if (k == 1) {
            a.add(new Circle("Circle", c));
        } else if (k == 2) {
            a.add(new Triangle("Triangle", c));
        } else if (k == 3) {
            a.add(new Square("Square", c));
        }

        a[a.size() - 1]->calculate_area();
    }

    cout << "Unsorted:\n";
    for (int i = 0; i < 20; i++) {
        a[i]->show();
        cout << "---------------------------\n";
    }

    sort(a.begin(), a.end(), compareByArea);

    cout << "Sorted:\n";
    for (int i = 0; i < 20; i++) {
        a[i]->show();
        cout << "---------------------------\n";
    }
}
