#pragma once

#include <iostream>

class Point
{
public:
   Point() : _x(0), _y(0) {} 
   Point(double x, double y);
   bool operator ==(const Point& other) const;
   friend std::ostream& operator <<(std::ostream& os, const Point& other);
   friend std::istream& operator >>(std::istream& os, Point& other);
   double dist(const Point &other) const;
   double _x;
   double _y;
   ~Point() noexcept;
};
