#include "../include/growCounter.h"

int growCounter(int upSpeed, int downSpeed, int desiredHeight){
    int daysCount = 0, currentHeight = 0;
    if (upSpeed<0 || downSpeed<0 || desiredHeight<0){
        return -1;
    }
    if (upSpeed<=downSpeed){
        return -1;
    }

    while (true){
        ++daysCount;
        currentHeight+=upSpeed;
        if (currentHeight>=desiredHeight){
            return daysCount;
        }
        currentHeight-=downSpeed;
    } 
    
}