#ifndef __POLINOMI_HPP__
#define __POLINOMI_HPP__

#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

class Polinom {
public:
    Polinom(){}
    Polinom(double c) {
        this->_koef = new std::vector<double>(1,c);
        _deg = 0;
    }
    Polinom(std::vector<double>* koef)
        { _koef=koef; _deg=koef->size(); }
    ~Polinom();
    void print(std::ostream& ostr) const;
    Polinom* operator + (const Polinom& p) const;
    Polinom* operator - (const Polinom& p) const;
    Polinom* operator * (const Polinom& p) const;
    double operator [] (int x);
private:
    std::vector<double>* _koef;
    int _deg;
};

std::ostream& operator << (std::ostream& ostr, const Polinom& p);


#endif