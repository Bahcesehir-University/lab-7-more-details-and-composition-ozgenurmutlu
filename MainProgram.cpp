// ============================================================
// Lab: More Details about Classes
// Course: Object-Oriented Programming (C++)
// Level: 2nd Year Engineering
// Duration: 60 minutes
// ============================================================
 
#include <iostream>
#include <string>
 
// ============================================================
// CLASS DEFINITIONS
// ============================================================
 
class Point {
private:
    double x;
    double y;
public:
    // TODO 1: Constructor with member initializer list (double x, double y)
    Point(double x, double y) : x(x), y(y) {}  // stub — fix initializer
 
    // TODO 2: const getter for x
    double getX() const { return x; }   // stub — add const
 
    // TODO 3: const getter for y
    double getY() const { return y; }   // stub — add const
 
    // TODO 4: const display()
    void display() const { std::cout << "(x , y )"; }
 
    // TODO 5: declare Rectangle as friend class
    friend class Rectangle;
};
 
 
class Rectangle {
private:
    Point topLeft;
    Point bottomRight;
public:
    // TODO 6: constructor with member initializer list
    Rectangle(double x1, double y1, double x2, double y2)
        : topLeft(x1,y1), bottomRight(x2,y2) {}  // stub — fix initializer
 
    // TODO 7: const getWidth()
    double getWidth() const { return std::abs (bottomRight.x - topLeft.x) ; }  // stub
 
    // TODO 8: const getHeight()
    double getHeight() const { return std ::abs (topLeft.y - bottomRight.y); }  // stub
 
    // TODO 9: const getArea()
    double getArea() const { return getWidth() * getHeight(); }  // stub
 
    // TODO 10: const display()
    void display() const {
        std::cout << "Top Left: ";
        topLeft.display();
        std::cout << " \nBottomRight: ";
        bottomRight.display();
        std::cout << "\nWidth:" << getWidth() << " Height:" << getHeight() << " Area:" << getArea() << std::endl;
    }
 
    friend bool isSameSize(const Rectangle& r1, const Rectangle& r2);
 
    // TODO 11: declare isSameSize as friend function
};
 
 
// TODO 12: implement isSameSize
bool isSameSize(const Rectangle& r1, const Rectangle& r2) {
    return r1.getArea() == r2.getArea() ;
}
 
 
class ConstDemo {
private:
    int value;
public:
    // TODO 13: constructor with member initializer list
    ConstDemo(int v) : value(v) {}  // stub — fix initializer
 
    // TODO 14: const getValue()
    int getValue() const { return value; }  // stub — add const
 
    // TODO 15: NON-const doubleValue() — multiplies value by 2
    void doubleValue() {
        value *= 2 ;
    }  // stub
 
    // TODO 16: const constGetDouble() — returns value * 2 without modifying
    int constGetDouble() const{ return value * 2; }  // stub — add const + fix body
};
 
 
// ============================================================
// MAIN
// ============================================================
int main() {
    // TODO 17-21: demo code
    std::cout << "Complete the TODOs above!" << std::endl;
   
    Rectangle rect1(0, 0, 4, 3);
    Rectangle rect2(1, 1, 4, 4);
 
    std::cout << "Rectangle 1: " << std::endl;
    rect1.display();  
    std::cout << "Rectangle 2: " << std::endl;
    rect2.display();
    std::cout << "Are the rectangles the same size? " << (isSameSize(rect1, rect2) ? "Yes" : "No") << std::endl;
    
     const ConstDemo cd1(7);
    std::cout << "ConstDemo value: " << cd1.getValue() << std::endl;
    std::cout << "ConstDemo constGetDouble: " << cd1.constGetDouble() << std::endl;
    ConstDemo cd2(5);
    std::cout << "Before doubleValue: " << cd2.getValue() << std::endl;
    cd2.doubleValue();
    std::cout << "non-const object after doublevalue : " << cd2.getValue() << std::endl;  
 
    return 0;
}
 
