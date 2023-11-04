#include <iostream>
#include "figure.h"
#include <cmath>

template <typename T>
class Hexagon final: public Figure<T>
{ 
public:
   Hexagon();
   Hexagon(Point<T> a, Point<T> b, Point<T> c, Point<T> d, Point<T> e, Point<T> f) : _a(a), _b(b), _c(c), _d(d), _e(e), _f(f){};
   
   virtual Hexagon& operator =(const Hexagon& other){
      _a = other._a;
      _b = other._b;
      _c = other._c;
      _d = other._d;
      _e = other._e;
      _f = other._f;
      return *this;
   };

   virtual bool operator ==(const Hexagon& other) const{
      return (_a == other._a and _b == other._b and _c == other._c and _d == other._d and _e == other._e and _f == other._f);
   };

   virtual void Print_cords(std::ostream& os){
      os << "Hexagon coordinates: A(" << _a  << "), B(" << _b << "), C( "<< _c << "), D(" << _d << "), E(" << _e << "), F(" << _f << ")." << std::endl;
   };

   virtual void Read_cords(std::istream& os){
      os >> _a >> _b >> _c >> _d >> _e >> _f;
   };

   virtual double area() const{
      double dis = _a.dist(_b);
      return (3 * std::sqrt(3) * dis * dis)/2;
   };
   
   virtual Point<double> centre() const{
      double x0 = _a._x + _b._x + _c._x + _d._x + _e._x + _f._x;
      double y0 = _a._y + _b._y + _c._y + _d._y + _e._y + _f._y;
      x0 /= 6;
      y0 /= 6;
      return Point(x0, y0);
   };

private:
   Point<T> _a;
   Point<T> _b;
   Point<T> _c;
   Point<T> _d;
   Point<T> _e;
   Point<T> _f;
};