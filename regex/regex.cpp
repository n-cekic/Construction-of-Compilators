#include "regex.hpp"

Cat::~Cat() {
    delete _l;
    delete _r;
}


CharClass::~CharClass() {
    delete _chars;
}


Plus::~Plus() {
    delete _e;
}


Star::~Star() {
    delete _e;
}


QMark::~QMark() {
    delete _e;
}


Times::~Times() {
    delete _e;
}


Or::~Or() {
    delete _lefte;
    delete _righte;
}


std::ostream& Cat::Write(std::ostream& ostr) const {
    _l->Write(ostr);
    _r->Write(ostr);
    return ostr;
}


std::ostream& Char::Write(std::ostream& ostr) const {
    ostr << "(" << _c << ")";
    return ostr;
}


std::ostream& CharClass::Write(std::ostream& ostr) const {
    ostr << "(";
    _chars->Write(ostr);
    ostr << ")";
    return ostr;
}


std::ostream& Plus::Write(std::ostream& ostr) const {
    ostr << "(";
    _e->Write(ostr);
    ostr << "(";
    _e->Write(ostr);
    ostr << "*))";
    return ostr;
}


std::ostream& Star::Write(std::ostream& ostr) const {
    ostr << "(";
    _e->Write(ostr);
    ostr << ")*";
    return ostr;
}


std::ostream& QMark::Write(std::ostream& ostr) const {
    ostr << "(";
    _e->Write(ostr);
    ostr << "|eps)";
    return ostr;
}


std::ostream& Times::Write(std::ostream& ostr) const {
    for (int i = 0; i < _t; i++)
        _e->Write(ostr);
    return ostr;
}


std::ostream& Or::Write(std::ostream& ostr) const {
    ostr << "(";
    _lefte->Write(ostr);
    ostr << ")|(";
    _righte->Write(ostr);
    ostr << ")";
    return ostr;
}


std::ostream& operator << (std::ostream& ostr, Regex& e) {
    e.Write(ostr);
    return ostr;
}