#include "figure.h"
#define M_PI 3.14159265358979323846
#include <cmath>
#include <iostream>

template <typename T>
class Pentagon final: public Figure<T>
{ 
public:
   Pentagon();
   Pentagon(Point<T> a, Point<T> b, Point<T> c, Point<T> d, Point<T> e) : _a(a), _b(b), _c(c), _d(d), _e(e){};
   
   virtual Pentagon& operator =(const Pentagon& other){
      _a = other._a;
      _b = other._b;
      _c = other._c;
      _d = other._d;
      _e = other._e;
      return *this;
   };

   virtual bool operator ==(const Pentagon& other) const{
      return (_a == other._a and _b == other._b and _c == other._c and _d == other._d and _e == other._e);
   };

   virtual void Print_cords(std::ostream& os){
      os << "Pentagon coordinates: A(" << _a  << "), B(" << _b << "), C( "<< _c << "), D(" << _d << "), E(" << _e << ")." << std::endl;
   };

   virtual void Read_cords(std::istream& os){
      os >> _a >> _b >> _c >> _d >> _e;
   };

   virtual double area() const{
      double dst = _a.dist(_b);
      return (5 * dst * dst)/(4 * std::tan(M_PI/5));
   };

   virtual Point<double> centre() const{
      double x0 = _a._x + _b._x + _c._x + _d._x + _e._x;
      double y0 = _a._y + _b._y + _c._y + _d._y + _e._y;
      x0 /= 5;
      y0 /= 5;
      return Point(x0, y0);
   };

private:
   Point<T> _a;
   Point<T> _b;
   Point<T> _c;
   Point<T> _d;
   Point<T> _e;
};