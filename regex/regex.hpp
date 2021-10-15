#ifndef __REGEX_HPP__
#define __REGEX_HPP__

#include <iostream>
#include <vector>

class Regex {
public:
    virtual ~Regex() { }
    virtual std::ostream& Write(std::ostream& ostr) const = 0;
};

class Cat : public Regex{
public:
    Cat(Regex *l, Regex* r)
        : _l(l), _r(r) { }
    ~Cat();
    std::ostream& Write(std::ostream& ostr) const;
private:
    Regex *_l, *_r;
};

class Char : public Regex {
public:
    Char(char c)
        : _c(c) { }
    ~Char() { }
    std::ostream& Write(std::ostream& ostr) const;

private:
    char _c;
};


class CharClass : public Regex {
public:
    CharClass(Regex *chars)
        : _chars(chars) { }
    ~CharClass();
    std::ostream& Write(std::ostream& ostr) const;
    
private:
    Regex *_chars;
};


class Plus : public Regex {
public:
    Plus(Regex* e)
        : _e(e) { }
    ~Plus();
    std::ostream& Write(std::ostream& ostr) const;

private:
    Regex* _e;
};


class Star : public Regex {
public:
    Star(Regex* e)
        : _e(e) { }
    ~Star();
    std::ostream& Write(std::ostream& ostr) const;

private:
    Regex* _e;
};


class QMark : public Regex {
public:
    QMark(Regex* e)
        : _e(e) { }
    ~QMark();
    std::ostream& Write(std::ostream& ostr) const;

private:
    Regex* _e;
};


class Times : public Regex {
public:
    Times(Regex* e, int t)
        : _e(e) , _t(t) { }
    ~Times();
    std::ostream& Write(std::ostream& ostr) const;

private:
    Regex* _e;
    int _t;
};


class Or : public Regex {
public:
    Or(Regex *e1, Regex *e2)
        : _lefte(e1), _righte(e2) { }
    ~Or();
    std::ostream& Write(std::ostream& ostr) const;

private:
    Regex *_lefte, *_righte;
};


std::ostream& operator << (std::ostream& ostr, Regex& e);


#endif