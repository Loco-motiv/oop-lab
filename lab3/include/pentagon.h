#include <iostream>
#include "figure.h"


class Pentagon final: public Figure
{ 
public:
   Pentagon();
   Pentagon(std::vector<Point> cords);
   
   virtual Pentagon& operator =(const Pentagon& other);
   virtual Pentagon& operator = (Pentagon&& other);
   virtual bool operator ==(const Pentagon& other) const;
   virtual void Print_cords(std::ostream& os);
   virtual void Read_cords(std::istream& os);
   virtual double area() const;
   virtual Point centre() const;

   virtual ~Pentagon() noexcept;
private:
   std::vector<Point> _cords;
};