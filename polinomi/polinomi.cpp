#include "polinomi.hpp"

Polinom::~Polinom() {
    delete this->_koef;
}

void Polinom::print(std::ostream& ostr) const{
    ostr << _koef->at(0);
    
    if (_deg == 0){
        std::cout << std::endl;
        return;
    }

    if (_koef->at(1) >= 0)
        ostr << "+";
    ostr << _koef->at(1) << "x";

    for(int i = 2; i < this->_deg; i++) {
        if (_koef->at(i) >= 0)
            ostr << "+";
        ostr << _koef->at(i) << "x^" << i;
    }
    ostr << std::endl;
}

Polinom* Polinom::operator + (const Polinom& p) const {
    int d = std::min(this->_deg, p._deg);
    std::vector<double>* koef = new std::vector<double>;
    
    for (int i = 0; i < d; i++) 
        koef->push_back(this->_koef->at(i) + p._koef->at(i));
    
    if (d != this->_deg)
        for (int i = d; i < this->_deg; i++) 
            koef->push_back(this->_koef->at(i));
    else if (d != p._deg)
        for (int i = d; i < p._deg; i++) 
            koef->push_back(p._koef->at(i));
    
    return new Polinom(koef);
}

Polinom* Polinom::operator - (const Polinom& p) const {
    int d = std::min(this->_deg, p._deg);
    std::vector<double>* koef = new std::vector<double>;
    
    for (int i = 0; i < d; i++) 
        koef->push_back(this->_koef->at(i) - p._koef->at(i));
    
    if (d != this->_deg)
        for (int i = d; i < this->_deg; i++) 
            koef->push_back(this->_koef->at(i));
    else if (d != p._deg)
        for (int i = d; i < p._deg; i++) 
            koef->push_back(0 - p._koef->at(i));
    
    return new Polinom(koef);
}


Polinom* Polinom::operator * (const Polinom& p) const {
    return new Polinom(p);
}


double Polinom::operator[] (int x) {
    int value = 0;
    for (int i = 0; i < this->_deg; i++)
        value = value + std::pow(x,i)*this->_koef->at(i);

    return value; 
}

std::ostream& operator << (std::ostream& ostr, const Polinom& p) {
    p.print(ostr);
    return ostr;
}