#include "shiz/shiz.hpp"

int shiz(const std::string& weekday,const int num){
    if (weekday == "Monday" and num == 12){
        return 1;
    }
    if (weekday == "Tuesday" and num > 95){
        return 1;
    }
    if (weekday == "Wednesday" and num == 34){
        return 1;
    }
    if (weekday == "Thursday" and num == 0){
        return 1;
    }
    if (weekday == "Friday" and num%2 == 0){
        return 1;
    }
    if (weekday == "Saturday" and num == 56){
        return 1;
    }
    if (weekday == "Sunday" and abs(num) == 666){
        return 1;
    }
    return 0;
}