#include "function.hpp"
#include <cmath>

void IdFunkcija::ispis(std::ostream& ostr) const { 
    ostr << "( x )";
}

double IdFunkcija::izracunaj(double x) const { 
    return x;
}

Funkcija* IdFunkcija::izvod() const { 
    return new Konstanta(1);
}


void Konstanta::ispis(std::ostream& ostr) const {
    ostr << this->_c;
}

double Konstanta::izracunaj(double x) const {
    return _c;
}

Funkcija* Konstanta::izvod() const {
    return new Konstanta(0);
}


void BinOperator::ispis(std::ostream& ostr) const {
    ostr << "(";
    this->_fl->ispis(ostr);
    ostr << this->_znak;
    this->_fd->ispis(ostr);    
    ostr << ")";
}

void ElementarnaFja::ispis(std::ostream& ostr) const {
    ostr << _ime << "(";
    _arg->ispis(ostr);
    ostr << ")";
}

double Sin::izracunaj(double x) const {
    return std::sin(x);
}

Funkcija* Sin::izvod() const {
    return new Puta(new Sin(getArg()), getArg()->izvod());
}

double Cos::izracunaj(double x) const {
    return std::cos(x);

}

Funkcija* Cos::izvod() const {
    return new Puta(new Puta(new Konstanta(-1), new Sin(getArg())), getArg()->izvod());
}

double Puta::izracunaj(double x) const { 
    return GetL()->izracunaj(x) * GetD()->izracunaj(x);
}

Funkcija* Puta::izvod() const { 
    return new Plus(new Puta(GetL()->izvod(), GetD()), new Puta(GetD()->izvod(), GetL()));
}

double Plus::izracunaj(double x) const {
    return GetD()->izracunaj(x) + GetL()->izracunaj(x);
}

Funkcija* Plus::izvod() const {
    return new Plus(GetD()->izvod(), GetL()->izvod());
    
}

std::ostream& operator << (std::ostream &izlaz, const Funkcija& f) {
  f.ispis(izlaz);
  return izlaz;
}

