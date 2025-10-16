#include <iostream>
#include "include/growCounter.h"

int main(int argc, char* argv[]){
    int upSpeed, downSpeed, desiredHeight;
    int result;
    std::cout<<"Up speed: ";
    std::cin>>upSpeed;
    std::cout<<"Down Speed: ";
    std::cin>>downSpeed;
    std::cout<<"Desired Height: ";
    std::cin>>desiredHeight;
    result = growCounter(upSpeed, downSpeed, desiredHeight);
    std::cout<<"Days to achieve: "<<result<<std::endl;
    return 0;
}