#include "shapes.h"

// Fill in here
#include <stdio.h>

/* Constructor */
Shape::Shape(int x, int y){
    x_pos = x;
    y_pos = y;
}

Point::Point(int x, int y):Shape(x, y){};
Line::Line(int x, int y):Shape(x, y){};
Triangle::Triangle(int x, int y):Shape(x, y){};
Quadrilateral::Quadrilateral(int x, int y):Shape(x, y){};

Equilateral::Equilateral(int x, int y):Triangle(x, y){};
Isosceles::Isosceles(int x, int y):Triangle(x, y){};
Scalene::Scalene(int x, int y):Triangle(x, y){};

Rectangle::Rectangle(int x, int y):Quadrilateral(x, y){};
Square::Square(int x, int y):Quadrilateral(x, y){};


/* Accessors */
void Shape::DrawSelf(void){    
}
void Point::DrawSelf(void){
    printf("Draw Point at (%i, %i)\n", this->x_pos, this->y_pos);
}
void Line::DrawSelf(void){
    printf("Draw Line at (%i, %i)\n", this->x_pos, this->y_pos);
}
void Triangle::DrawSelf(void){
    printf("Draw Triangle at (%i, %i)\n", this->x_pos, this->y_pos);
}
void Quadrilateral::DrawSelf(void){
    printf("Draw Quadrilateral at (%i, %i)\n", this->x_pos, this->y_pos);
}


void Equilateral::DrawSelf(void){
    printf("Draw Equilateral at (%i, %i)\n", this->x_pos, this->y_pos);
}
void Isosceles::DrawSelf(void){
    printf("Draw Isosceles at (%i, %i)\n", this->x_pos, this->y_pos);
}
void Scalene::DrawSelf(void){
    printf("Draw Scalene at (%i, %i)\n", this->x_pos, this->y_pos);
}

void Rectangle::DrawSelf(void){
    printf("Draw Rectangle at (%i, %i)\n", this->x_pos, this->y_pos);
}

void Square::DrawSelf(void){
    printf("Draw Square at (%i, %i)\n", this->x_pos, this->y_pos);
}