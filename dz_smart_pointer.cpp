// dz_smart_pointer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

/*
Измените следующую программу (см. ниже), заменив обычный указатель на 
умный указатель std::unique_ptr, где это необходимо.
*/

class Fraction
{
private:
    int m_numerator = 0;
    int m_denominator = 1;

public:
    Fraction(int numerator = 0, int denominator = 1) :
        m_numerator(numerator), m_denominator(denominator)
    {
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& f1)
    {
        out << f1.m_numerator << "/" << f1.m_denominator;
        return out;
    }
};

void printFraction(std::unique_ptr<Fraction> obj)
{
    if (obj)
        std::cout << *obj;
}

int main()
{
    // создание объекта с динамическим выделением памяти
    std::unique_ptr<Fraction> obj_fr = std::make_unique<Fraction>(7, 9);

    // либо можно инициализировать таким способом:
    // std::unique_ptr<Fraction> obj_fr (new Fraction(6,7)); 
   
    printFraction(std::move(obj_fr));  // используется семантика перемещения
    return 0;
}
