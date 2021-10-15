#ifndef _FUNCTION_HPP_
#define _FUNCTION_HPP_ 1

#include <iostream>

class Funkcija {
public:
    virtual void ispis(std::ostream& ostr) const = 0;
    virtual double izracunaj(double x) const = 0;
    virtual Funkcija* izvod() const = 0;
};

class IdFunkcija: public Funkcija {
public: 
    void ispis(std::ostream& ostr) const;
    double izracunaj(double x) const;
    Funkcija* izvod() const;
};

class Konstanta: public Funkcija {
public:
    Konstanta(double c)
        : _c(c) { }
    void ispis(std::ostream& ostr) const;
    double izracunaj(double x) const;
    Funkcija* izvod() const;
private:
    double _c;
};

class BinOperator: public Funkcija {
public:
    BinOperator(Funkcija* f1, Funkcija* f2, char znak)
        : _fl(f1), _fd(f2), _znak(znak) { }
    void ispis(std::ostream& ostr) const;
    Funkcija* GetL() const {
        return _fl;
    }
    Funkcija* GetD() const {
        return _fd;
    }
    // double izracunaj(double x) const;
    // Funkcija* izvod() const;
private:
    Funkcija* _fl;
    Funkcija* _fd;
    char _znak;
};

class ElementarnaFja: public Funkcija {
public:
    ElementarnaFja(Funkcija* arg, std::string ime)
        : _ime(ime), _arg(arg) { }
    void ispis(std::ostream& ostr) const;
    Funkcija* getArg() const {
        return _arg;
    }
    // double izracunaj(double x) const;
    // Funkcija* izvod() const;
private:
    std::string _ime;
    Funkcija* _arg;
};

class Sin: public ElementarnaFja {
public:
    Sin(Funkcija* arg)
        : ElementarnaFja(arg, "sin") { }
    // void ispis(std::ostream& ostr) const;
    double izracunaj(double x) const;
    Funkcija* izvod() const;
};

class Cos: public ElementarnaFja {
public:
    Cos(Funkcija* arg)
        : ElementarnaFja(arg, "cos") { }
    // void ispis(std::ostream& ostr) const;
    double izracunaj(double x) const;
    Funkcija* izvod() const;
};

class Plus : public BinOperator {
public:
  Plus(Funkcija* prva, Funkcija* druga)
    :BinOperator(prva, druga, '+') { }
  double izracunaj(double x) const;
  Funkcija* izvod() const;
};

class Puta : public BinOperator {
public:
  Puta(Funkcija* prva, Funkcija* druga)
    :BinOperator(prva, druga, '*') { }
  double izracunaj(double x) const;
  Funkcija* izvod() const;
};

std::ostream& operator << (std::ostream &izlaz, const Funkcija& f);


#endif