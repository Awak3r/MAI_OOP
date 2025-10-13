#pragma once

#include <string>
#include <iostream>




class Six {
    public:
    Six();
    
    Six(const size_t& arraySize, unsigned char defaultValue = 0);
    
    Six(const std::initializer_list<unsigned char>& initialValues);
    
    Six(const std::string& sourceString);
        
    Six(const Six& other);
    
    Six(Six&& other) noexcept;

    size_t getSize();

    void printclass();

    void plus1(unsigned char newValue);

    void minus1();

    Six add(const Six& other);
    
    Six remove(const Six& other);
    
    bool equals(const Six& other) const;

    bool bolshe(const Six& other) const;
    
    bool menshe(const Six& other) const;


    std::ostream& print(std::ostream& outputStream);

    virtual ~Six() noexcept;

    private:
    size_t arraySize;           
    unsigned char* dataArray; 
};

