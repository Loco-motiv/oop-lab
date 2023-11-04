#pragma once

#include <iostream>
#include <cmath>

template <typename T>
class Point
{
public:
   Point() : _x(0), _y(0) {} 
   Point(T x, T y) : _x(x), _y(y) {}

   friend std::ostream& operator <<(std::ostream& os, const Point& other){
      os << "x: " << other._x << ", y: " << other._y;
      return os;
   }

   friend std::istream& operator >>(std::istream& os, Point& other){
      os >> other._x >> other._y;
      return os;
   }
   
   bool operator ==(const Point& other) const{
      return (_x == other._x and _y == other._y);
   };
   double dist(const Point &other) const{
      double xx = this->_x - other._x;
      double yy = this->_y - other._y;
      return std::sqrt(xx * xx + yy * yy);
};
   T _x;
   T _y;
};
