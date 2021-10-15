#ifndef _MATRIX_HPP_
#define _MATRIX_HPP_ 1

#include <vector>
#include <iostream>

class Matrix {
public:
    Matrix();
    Matrix(int i, int j);
    std::vector<double>& operator [] (int i);
    std::vector<double> operator [] (int i) const;

    void write(std::ostream& ostr) const;
    void addRow(const std::vector<double>& r);
    Matrix operator + (const Matrix& m) const;
    Matrix operator - (const Matrix& m) const;
    Matrix operator * (const Matrix& m) const;
    Matrix coordProduct (const Matrix& m) const;
    Matrix transpose () const;
private:
    std::vector<std::vector<double>> _m;
};
//               probaj sa std::ostream& ostr, CONST Matrix m
std::ostream& operator << (std::ostream& ostr, Matrix m);

#endif