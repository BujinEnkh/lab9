#include <iostream>    // оролт/гаралт
#include <cstring>     // char array үйлдэл
#include <algorithm>   // sort ашиглана
#include <vector>
#include <cstdlib>     // rand, srand
#include <ctime>       // time()
using namespace std;

// Template List class
template <typename T>
class List {
private:
    T *elements;       // динамик array
    int capacity;      // одоогийн багтаамж
    int currentSize;   // одоогийн хэмжээ

    void resize(int newCapacity) {      // хэмжээ өсгөх функц
        T *newArray = new T[newCapacity];   // шинээр array авах
        for (int i = 0; i < currentSize; ++i) {
            newArray[i] = elements[i];      // хуучин элементүүдийг шинэ array-д хуулна
        }
        delete[] elements;          // хуучныг устгана
        elements = newArray;        // шинэ array-г заана
        capacity = newCapacity;     // шинэ багтаамж хадгална
    }

public:
    List() : elements(nullptr), capacity(0), currentSize(0) {}  // байгуулагч функц
    ~List() { delete[] elements; }   // устгагч функц

    T *begin() { return elements; }          // эхлэл pointer
    T *end() { return &elements[currentSize]; }   // төгсгөл pointer 

    void add(const T &element) {     // нэмэх функц
        if (currentSize == capacity) {   // дүүрсэн бол
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;  // багтаамж 0-тэй тэнцүү бол 1, үгүй бол 2 дахин томруулна
            resize(newCapacity);
        }
        elements[currentSize++] = element;    // элемент нэмээд size өсгөнө
    }

    int size() const { return currentSize; }   // одоогийн хэмжээ

    T &operator[](int index) {      // аль элементирүү индексаар хандахыг харуулах
        if (index >= currentSize) throw out_of_range("Index out of range");
        return elements[index];
    }

    void remove(int index) {         // устгах
        if (index >= currentSize) throw out_of_range("Index out of range");
        for (int i = index; i < currentSize - 1; i++) {
            elements[i] = elements[i + 1];     // элементүүдийг урагш шилжүүлэх
        }
        currentSize--;       // size бууруулах
    }

    void insert(const T &element, int index) {   // оруулах
        if (currentSize == capacity) {
            int newCapacity = (capacity == 0) ? 1 : capacity * 2;
            resize(newCapacity);
        }
        currentSize++;        // size нэмэх
        for (int i = currentSize; i > index; i--) {
            elements[i] = elements[i - 1];      // арын элементүүдийг зөөх
        }
        elements[index] = element;              // шинэ элементийг байрлуулах
    }
};

class shape {
protected:
    char *name;         // дүрсний нэр
public:
    shape(const char *n) {
        name = new char[strlen(n) + 1];     // нэрт зай авах
        strcpy(name, n);                     // нэр хуулах
    }

    virtual ~shape() { }    // виртуал destructor

    virtual float calculate_area() const = 0;    // талбай тооцох жинхэнэ хийсвэр функц 

    virtual void show() const {         // хэвлэх функц
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

    float calculate_area() const override { return 0; }

    void show() const override {
        shape::show();
        cout << "Area: " << calculate_area() << endl;   // талбай хэвлэх
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

    List<_2Dshape *> a;   // shape pointer-үүдийн лист

    for (int i = 0; i < 20; i++) {        // 20 shape үүсгэнэ
        int k = (rand() % 3) + 1;         // 1–3 төрөл
        float c = rand() % 20;            // санамсаргүй хэмжээ

        if (k == 1) a.add(new Circle("Circle", c));
        else if (k == 2) a.add(new Triangle("Triangle", c));
        else if (k == 3) a.add(new Square("Square", c));

        a[a.size() - 1]->calculate_area(); // талбайг дуудаж авна
    }

    cout << "Unsorted:\n";
    for (int i = 0; i < 20; i++) {      // эрэмблээгүй хэвлэх
        a[i]->show();
        cout << "---------------------------\n";
    }

    sort(a.begin(), a.end(), compareByArea);  // талбайгаар эрэмблэх

    cout << "\nSorted:\n";
    for (int i = 0; i < 20; i++) {      // эрэмбэлсэн хувилбар хэвлэх
        a[i]->show();
        cout << "---------------------------\n";
    }
}
