#pragma once

#include <iostream>
#include <vector>
#include "point.h"

class Figure
{ 
public:
   Figure();
   Figure(std::vector<Point> cords);
   
   virtual Figure& operator =(const Figure& other);
   virtual Figure& operator = (Figure&& other);
   virtual bool operator ==(const Figure& other) const;
   virtual void Print_cords(std::ostream& os) = 0;
   virtual void Read_cords(std::istream& os) = 0;
   friend std::ostream& operator <<(std::ostream& os, Figure& other);
   friend std::ostream& operator >>(std::istream& os, Figure& other);
   virtual double area() const = 0;
   virtual Point centre() const = 0;
   explicit operator double() const {
        return area();
   }

   virtual ~Figure() noexcept;
private:
   std::vector<Point> _cords;   
};