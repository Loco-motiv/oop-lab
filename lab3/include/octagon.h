#include <iostream>
#include "figure.h"


class Octagon final: public Figure
{ 
public:
   Octagon();
   Octagon(std::vector<Point> cords);
   
   virtual Octagon& operator =(const Octagon& other);
   virtual Octagon& operator = (Octagon&& other);
   virtual bool operator ==(const Octagon& other) const;
   virtual void Print_cords(std::ostream& os);
   virtual void Read_cords(std::istream& os);
   virtual double area() const;
   virtual Point centre() const;

   virtual ~Octagon() noexcept;
private:
   std::vector<Point> _cords;
};