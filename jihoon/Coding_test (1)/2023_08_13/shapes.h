#pragma once

// Fill in

class Shape {
    public:
    Shape(int x, int y);
    virtual void DrawSelf(void) = 0; // pure virtual function
    virtual int get_x(void);
    virtual int get_y(void);

    protected:
    int x_pos;
    int y_pos;
};

//////////////////////

class Point : public Shape{
    public:
    Point(int x, int y);
    void DrawSelf(void);
};

class Line : public Shape{
    public:
    Line(int x, int y);
    void DrawSelf(void);
};

class Triangle : public Shape{
    public:
    Triangle(int x, int y);
    void DrawSelf(void);
};

class Quadrilateral : public Shape{
    public:
    Quadrilateral(int x, int y);
    void DrawSelf(void);
};

///////////////////////

class Equilateral : public Triangle{
    public:
    Equilateral(int x, int y);
    void DrawSelf(void);
};

class Isosceles : public Triangle{
    public:
    Isosceles(int x, int y);
    void DrawSelf(void);
};

class Scalene : public Triangle{
    public:
    Scalene(int x, int y);
    void DrawSelf(void);
};

class Rectangle : public Quadrilateral{
    public:
    Rectangle(int x, int y);
    void DrawSelf(void);
};

class Square : public Quadrilateral{
    public:
    Square(int x, int y);
    void DrawSelf(void);
};
