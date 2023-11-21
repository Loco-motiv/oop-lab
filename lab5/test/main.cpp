#include <map>
#include <allocator.h>
#include <forwardlist.h>
#include <iostream>

int fact(int i){
    if (!i) return 1;
    return i*fact(i-1);
}

int main(){

    std::map<int, int, std::less<int>, Allocator<std::pair<const int, int>>> MapAllo;
     for (int i = 0; i < 10; ++i) {
        MapAllo.emplace(i, fact(i));
    }

    for (const auto& pair : MapAllo) {
        std::cout << pair.first << " " << pair.second << std::endl;
    }

    ForwardList<int, Allocator<int>> n;

    n.push_front(1);
    n.push_front(2);
    n.push_front(3);
    n.push_front(4);
    n.push_front(5);
    n.push_front(6);
    
    for (int i = 0; i < 6; ++i){
        std::cout << n[i] << std::endl;
    }

    return 0;
}