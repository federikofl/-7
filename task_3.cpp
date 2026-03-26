#include <iostream>
#include <vector>
#include <string>
#include <typeinfo>

using namespace std;

class Shape {
public:
    virtual ~Shape() {} 
    virtual double getArea() const = 0;
};

class Circle : public Shape {
private:
    double radius;
    
public:
    Circle(double r) : radius(r) {}
    
    double getRadius() const {
        return radius;
    }
    
    double getArea() const override {
        return 3.14159 * radius * radius;
    }
};

class Rectangle : public Shape {
private:
    double width;
    double height;
    
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double getWidth() const {
        return width;
    }
    
    double getHeight() const {
        return height;
    }
    
    double getArea() const override {
        return width * height;
    }
};

class Triangle : public Shape {
private:
    double base;
    double height;
    
public:
    Triangle(double b, double h) : base(b), height(h) {}
    
    double getArea() const override {
        return 0.5 * base * height;
    }
};

void processShape(Shape* shape) {
    if (!shape) {
        cout << "Ошибка: нулевой указатель" << endl;
        return;
    }
    
    Circle* circle = dynamic_cast<Circle*>(shape);
    if (circle) {
        cout << "Это круг! Радиус: " << circle->getRadius() 
             << ", площадь: " << circle->getArea() << endl;
        return;
    }
    
    Rectangle* rect = dynamic_cast<Rectangle*>(shape);
    if (rect) {
        cout << "Это прямоугольник! Ширина: " << rect->getWidth() 
             << ", высота: " << rect->getHeight()
             << ", площадь: " << rect->getArea() << endl;
        return;
    }
    
    cout << "Неизвестная фигура, площадь: " << shape->getArea() << endl;
}

void processShapeRef(Shape& shape) {
    try {
        Circle& circle = dynamic_cast<Circle&>(shape);
        cout << "Это круг! Радиус: " << circle.getRadius() 
             << ", площадь: " << circle.getArea() << endl;
        return;
    } catch (const bad_cast&) {
    }
    
    try {
        Rectangle& rect = dynamic_cast<Rectangle&>(shape);
        cout << "Это прямоугольник! Ширина: " << rect.getWidth() 
             << ", высота: " << rect.getHeight()
             << ", площадь: " << rect.getArea() << endl;
        return;
    } catch (const bad_cast&) {
        cout << "Неизвестная фигура, площадь: " << shape.getArea() << endl;
    }
}

int main() {
    vector<Shape*> shapes;
    
    shapes.push_back(new Circle(5.0));
    shapes.push_back(new Rectangle(4.0, 6.0));
    shapes.push_back(new Circle(3.5));
    shapes.push_back(new Rectangle(2.5, 8.0));
    shapes.push_back(new Triangle(10.0, 5.0));
    
    cout << "Обработка через указатели" << endl;
    for (int i = 0; i < shapes.size(); i++) {
        cout << i + 1 << ". ";
        processShape(shapes[i]);
    }
    
    cout << "\nОбработка через ссылки (с исключениями)" << endl;
    for (int i = 0; i < shapes.size(); i++) {
        cout << i + 1 << ". ";
        processShapeRef(*shapes[i]);
    }
    
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    
    return 0;
}