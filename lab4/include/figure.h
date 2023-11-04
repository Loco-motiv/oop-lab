#pragma once

#include <iostream>
#include "point.h"

template <typename T>
class Figure
{ 
public:
   virtual void Print_cords(std::ostream& os) = 0;
   virtual void Read_cords(std::istream& os) = 0;
   friend std::ostream& operator <<(std::ostream& os, Figure<T>& other){
      other.Print_cords(os);
      return os;
   };
   friend std::istream& operator >>(std::istream& os, Figure<T>& other){   
      other.Read_cords(os);
      return os;
   };
   virtual double area() const = 0;
   explicit operator double() const {
        return area();
   };
   virtual Point<double> centre() const = 0;
   virtual ~Figure() noexcept = default;
};