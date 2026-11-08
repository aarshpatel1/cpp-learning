
#include <iomanip>
#include <iostream>
#include <vector>
#define PI 3.14
using namespace std;

class Shape {
  public:
    virtual void calculateArea() = 0;
    virtual void displayType() { cout << "Category: Shape" << endl; }
    virtual ~Shape() { cout << "Shape destructor" << endl; }
};

class Circle : public Shape {
  public:
    double radius;
    Circle(double r) { radius = r; }
    void calculateArea() {
        cout << "Area: " << fixed << setprecision(2) << (PI * radius * radius)
             << endl;
    }
    ~Circle() { cout << "Circle destructor" << endl; }
};

class Rectangle : public Shape {
  public:
    double length, breadth;
    Rectangle(double l, double b) {
        length = l;
        breadth = b;
    }
    void calculateArea() {
        cout << "Area: " << fixed << setprecision(2) << (length * breadth)
             << endl;
    }
    ~Rectangle() { cout << "Rectangle destructor" << endl; }
};

class Triangle : public Shape {
  public:
    double base, height;
    Triangle(double b, double h) {
        base = b;
        height = h;
    }
    void calculateArea() {
        cout << "Area: " << fixed << setprecision(2) << (base * height * 0.5)
             << endl;
    }
    ~Triangle() { cout << "Triangle destructor" << endl; }
};

int main() {
    int n;
    cin >> n;
    vector<Shape *> arr;
    for (int i = 0; i < n; i++) {
        char type;
        cin >> type;
        if (type == 'C') {
            double radius;
            cin >> radius;
            arr.push_back(new Circle(radius));
        } else if (type == 'R') {
            double length, breadth;
            cin >> length;
            cin >> breadth;
            arr.push_back(new Rectangle(length, breadth));
        } else if (type == 'T') {
            double base, height;
            cin >> base;
            cin >> height;
            arr.push_back(new Triangle(base, height));
        }
    }

    for (Shape *s : arr) {
        s->displayType();
        s->calculateArea();
    }

    for (Shape *s : arr) {
        delete s;
    }

    return 0;
}