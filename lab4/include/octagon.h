#include <iostream>
#include "figure.h"
#include <cmath>

template <typename T>
class Octagon final: public Figure<T>
{ 
public:
   Octagon();
   Octagon(Point<T> a, Point<T> b, Point<T> c, Point<T> d, Point<T> e, Point<T> f, Point<T> g, Point<T> h) : _a(a), _b(b), _c(c), _d(d), _e(e), _f(f), _g(g), _h(h){};
   
   virtual Octagon& operator =(const Octagon& other){_a = other._a;
        _b = other._b;
        _c = other._c;
        _d = other._d;
        _e = other._e;
        _f = other._f;
        _g = other._g;
        _h = other._h;
        return *this;
    };

   virtual bool operator ==(const Octagon& other) const{
        return (_a == other._a and _b == other._b and _c == other._c and _d == other._d and _e == other._e and _f == other._f and _g == other._g and _h == other._h);
   };

   virtual void Print_cords(std::ostream& os){
        os << "Octagon coordinates: A(" << _a  << "), B(" << _b << "), C( "<< _c << "), D(" << _d << "), E(" << _e << "), F(" << _f << "), G(" << _g << "), H(" << _h << ")." << std::endl;
   };

   virtual void Read_cords(std::istream& os){
        os >> _a >> _b >> _c >> _d >> _e >> _f >> _g >> _h;
   };

   virtual double area() const{
        double dst = _a.dist(_b);
        return 2 * dst * dst * (1 + std::sqrt(2));
   };

   virtual Point<double> centre() const{
        double x0 = _a._x + _b._x + _c._x + _d._x + _e._x + _f._x + _g._x + _h._x;
        double y0 = _a._y + _b._y + _c._y + _d._y + _e._y + _f._y + _g._y + _h._y;
        x0 /= 8;
        y0 /= 8;
        return Point(x0, y0);
   };

private:
   Point<T> _a;
   Point<T> _b;
   Point<T> _c;
   Point<T> _d;
   Point<T> _e;
   Point<T> _f;
   Point<T> _g;
   Point<T> _h; 
};