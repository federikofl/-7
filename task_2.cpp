#include <iostream>
#include <vector>
using namespace std;

class Shape {
public:
    virtual ~Shape() {}
    virtual double area() const = 0;
    virtual void print() const = 0;
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double area() const override {
        return 3.1415 * radius * radius;
    }
    
    void print() const override {
        cout << "Круг: радиус = " << radius << ", площадь = " << area();
    }
    
    double getRadius() const { return radius; }
};

class Rectangle : public Shape {
private:
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    double area() const override {
        return width * height;
    }
    
    void print() const override {
        cout << "Прямоугольник: " << width << " * " << height << ", площадь = " << area();
    }
    
    double getWidth() const { return width; }
    double getHeight() const { return height; }
};

int main() {

    vector<Shape*> shapes;
    shapes.push_back(new Circle(5));
    shapes.push_back(new Rectangle(4, 6));
    shapes.push_back(new Circle(3));
    
    cout << "Все фигуры:\n";
    for (int i = 0; i < shapes.size(); i++) {
        shapes[i]->print();
        cout << endl;
    }
    cout << endl;
    
    Circle* c = static_cast<Circle*>(shapes[0]);
    cout << "Первый элемент - круг, радиус = " << c->getRadius() << endl;
    
    Rectangle* r = static_cast<Rectangle*>(shapes[1]);
    cout << "Второй элемент - прямоугольник, ширина = " << r->getWidth() 
         << ", высота = " << r->getHeight() << endl;
    
    Circle* dangerous = static_cast<Circle*>(shapes[1]);
    cout << "\nОпасное приведение: прямоугольник как круг\n";
    cout << "Считаем 'радиус' = " << dangerous->getRadius();
    
    for (int i = 0; i < shapes.size(); i++) {
        delete shapes[i];
    }
    
    return 0;
}