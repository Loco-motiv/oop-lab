#include <iostream>
#include "figure.h"


class Hexagon final: public Figure
{ 
public:
   Hexagon();
   Hexagon(std::vector<Point> cords);
   
   virtual Hexagon& operator =(const Hexagon& other);
   virtual Hexagon& operator = (Hexagon&& other);
   virtual bool operator ==(const Hexagon& other) const;
   virtual void Print_cords(std::ostream& os);
   virtual void Read_cords(std::istream& os);
   virtual double area() const;
   virtual Point centre() const;

   virtual ~Hexagon() noexcept;
private:
   std::vector<Point> _cords;
};