#include "../include/six.h"
#include <cstddef>
#include <iostream>
#include <stdexcept>



Six::Six() : arraySize(0), dataArray(nullptr){}

Six::Six(const size_t& arraySize, unsigned char defaultValue){
    this->arraySize = arraySize;
    this->dataArray = new unsigned char[arraySize];
    for (size_t i = 0; i < arraySize; ++i){
        this->dataArray[i] = defaultValue;
    }
}

Six::Six(const std::initializer_list<unsigned char>& initialValues){
    arraySize = initialValues.size();
    dataArray = new unsigned char[arraySize];
    size_t index = 0;
    for (const auto& value : initialValues){
         if (!(value >= '0' && value <= '5')){
            delete[] dataArray;
            throw std::logic_error("error: invalid number\n");
        }
        dataArray[index++] = value;
    }
}

Six::Six(const std::string& sourceString){
    arraySize = sourceString.size();
    dataArray = new unsigned char[arraySize];
    for (size_t i = 0; i < arraySize; ++i){
        if (!(sourceString[i] >= '0' && sourceString[i] <= '5')){
            delete[] dataArray;
            throw std::logic_error("error: invalid number\n");
        }
        dataArray[arraySize - i - 1] = static_cast<unsigned char>(sourceString[i]);
    }
}

Six::Six(const Six& other){
    arraySize = other.arraySize;
    dataArray = new unsigned char[arraySize];
    for (size_t i = 0; i < arraySize; ++i){
        dataArray[i] = other.dataArray[i];
    }
}

Six::Six(Six&& other) noexcept {
    arraySize = other.arraySize;
    dataArray = other.dataArray;
    other.arraySize = 0;
    other.dataArray = nullptr;
}

size_t Six::getSize(){
    size_t len = this->arraySize; 
    return len;
}

void Six::printclass(){
    std::cout<<"[ ";
    for(size_t i =0; i<this->arraySize; i++){
        std::cout<<this->dataArray[i]<<" ";
    }
    std::cout<<"]\n";
}

void Six::plus1(unsigned char newValue){
    unsigned char* newArray = new unsigned char[arraySize + 1];
    for (size_t i = 0; i < arraySize; ++i){
        newArray[i] = dataArray[i];
    }
    newArray[arraySize] = newValue;
    delete[] dataArray;
    dataArray = newArray;
    ++arraySize;
}

void Six::minus1(){
    unsigned char* newArray = new unsigned char[arraySize - 1];
    for (size_t i = 0; i < arraySize - 1; ++i){
        newArray[i] = dataArray[i];
    }
    delete[] dataArray;
    dataArray = newArray;
    --arraySize;
}
//5, 5 1, 1
Six Six::add(const Six& other){
    if (this->arraySize != other.arraySize){
        throw std::logic_error("error: cannot be performed\n");
    }
    for (int i = 0; i < this->arraySize; i++){
        if (i >= other.arraySize){
            break;
        }
        if (((this->dataArray[i] - '0') + (other.dataArray[i] - '0')) >= 6){
            this->dataArray[i] = (this->dataArray[i] - '0') + (other.dataArray[i] - '0') - 6 + '0';
            for (int j = i + 1; j <= this->arraySize; j++){
                if (j == this->arraySize){
                    this->plus1('1');
                    break;
                }
                else{
                    this->dataArray[j] = this->dataArray[j] + 1;
                    if ((this->dataArray[j] - '0') < 6){
                        break;
                    }
                    this->dataArray[j] = '0';
                }
            }
        }
        else{
            this->dataArray[i] = (this->dataArray[i] - '0' + other.dataArray[i] - '0') + '0'; 
        }
    }
    return *this;
}

Six Six::remove(const Six& other){
    if (this->arraySize != other.arraySize){
        throw std::logic_error("error: cannot be performed\n");
    }
    int flag = 0;
    for(int i = this->arraySize - 1; i >= 0; i--){
        if (this->dataArray[i] < other.dataArray[i]){
            flag = 1;
            break;
        }
        else if (this->dataArray[i] > other.dataArray[i]){
            flag = 0;
            break;
        }
    }
    if (flag){
        throw std::logic_error("error: result will be negative\n");
    }
    for (int i = 0; i < this->arraySize; i++){
        if(this->dataArray[i] < other.dataArray[i]){
            this->dataArray[i] = 6 + (this->dataArray[i] - '0') - (other.dataArray[i] - '0') + '0';
            for(int j = i + 1; j < arraySize; j++){
                this->dataArray[j] = this->dataArray[j] - 1;
                if(this->dataArray[j] >= '0'){
                    break;
                }
                this->dataArray[j] = '5';
            }
        }
        else{
            this->dataArray[i] = (this->dataArray[i] - '0') - (other.dataArray[i] - '0') + '0';
        }
    }
    while(this->arraySize > 1 && this->dataArray[arraySize - 1] == '0'){
        this->minus1();
    }
    
    return *this;
}

bool Six::equals(const Six& other) const {
    if (this->arraySize != other.arraySize){
        return false;
    }
    for (int i = 0; i < this->arraySize; ++i){
        if (this->dataArray[i] != other.dataArray[i]){
            return false;
        }
    }
    return true;
}

bool Six::bolshe(const Six& other) const {
    if (this->arraySize != other.arraySize){
        throw std::logic_error("error: length does not match");
    }
    for(int i = this->arraySize - 1; i >= 0; i--){
        if (this->dataArray[i] > other.dataArray[i]){
            return true;
        }
        else if (this->dataArray[i] < other.dataArray[i]){
            return false;
        }
    }
    return false; 
}

bool Six::menshe(const Six& other) const {
    if (this->arraySize != other.arraySize){
        throw std::logic_error("error: length does not match");
    }
    
    for(int i = this->arraySize - 1; i >= 0; i--){
        if (this->dataArray[i] < other.dataArray[i]){
            return true;
        }
        else if (this->dataArray[i] > other.dataArray[i]){
            return false;
        }
    }
    return false; 
}




Six::~Six() noexcept {
    if (dataArray != nullptr){
        delete[] dataArray;
        dataArray = nullptr;
    }
    arraySize = 0;
}