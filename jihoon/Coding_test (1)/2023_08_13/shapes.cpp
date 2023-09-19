#include "shapes.h"

// Fill in here
#include <stdio.h>

Shape::Shape(int x, int y) {
    x_pos = x;
    y_pos = y;
}

int Shape::get_x(void) {
    return x_pos;
}

int Shape::get_y(void) {
    return y_pos;
}

/////////////
Point::Point(int x, int y) : Shape(x, y) {

}

void Point::DrawSelf(void) {
    printf("Draw Point at (%d, %d)\n", get_x(), get_y());
}

Line::Line(int x, int y) : Shape(x, y) {

}

void Line::DrawSelf(void) {
    printf("Draw Line at (%d, %d)\n", get_x(), get_y());
}

Triangle::Triangle(int x, int y) : Shape(x, y) {

}

void Triangle::DrawSelf(void) {
    printf("Draw Triangle at (%d, %d)\n", get_x(), get_y());
}

Quadrilateral::Quadrilateral(int x, int y) : Shape(x, y) {

}
void Quadrilateral::DrawSelf(void) {
    printf("Draw Quadrilateral at (%d, %d)\n", get_x(), get_y());
}
///////////////////////////////

Equilateral::Equilateral(int x, int y) : Triangle(x, y) {

}
void Equilateral::DrawSelf(void) {
    printf("Draw Equilateral at (%d, %d)\n", get_x(), get_y());
}

Isosceles::Isosceles(int x, int y) : Triangle(x, y) {

}
void Isosceles::DrawSelf(void) {
    printf("Draw Isosceles at (%d, %d)\n", get_x(), get_y());
}

Scalene::Scalene(int x, int y) : Triangle(x, y) {

}
void Scalene::DrawSelf(void) {
    printf("Draw Scalene at (%d, %d)\n", get_x(), get_y());
}


Rectangle::Rectangle(int x, int y) : Quadrilateral(x, y) {

}
void Rectangle::DrawSelf(void) {
    printf("Draw Rectangle at (%d, %d)\n", get_x(), get_y());
}

Square::Square(int x, int y) : Quadrilateral(x, y) {

}
void Square::DrawSelf(void) {
    printf("Draw Square at (%d, %d)\n", this->x_pos, this->y_pos);
}
// OR Shape::x_pos, Shape::y_pos