#include "matrix.hpp"

Matrix::Matrix() {
    
}
Matrix::Matrix(int i, int j) {
    _m.resize(i);
    for (int k = 0; k < i; k++)
        _m[k].resize(j);
}

std::vector<double>& Matrix::operator [] (int i) {
    return _m[i];
}

std::vector<double> Matrix::operator [] (int i) const {
    return _m[i];
}

void Matrix::addRow (const std::vector<double>& v) {
    _m.push_back(v);
}

void Matrix::write (std::ostream& ostr) const {
    for (auto r : _m) {
        for (auto e : r) 
            ostr << e << "\t";
        ostr << std::endl;
    }
}

Matrix Matrix::operator + (const Matrix& m) const {
    if (_m.size() != m._m.size() || _m[0].size() != m._m[0].size())
        throw "Matrix dimesnisons must agree!\n";

    
    Matrix result (_m.size(), _m[0].size());

    for (int i = 0; i < _m.size(); i++) {
        for (int j = 0; j < _m[0].size(); j++) {
            result[i][j] = (*this)[i][j] + m[i][j];
        }
    }
    
    return result;
}

Matrix Matrix::operator - (const Matrix& m) const {
    if (_m.size() != m._m.size() || _m[0].size() != m._m[0].size())
        throw "Matrix dimensions must agree\n";
    
    Matrix result(_m.size(), _m[0].size());

    for (int i = 0; i < _m.size(); i++)
        for (int j = 0; j < _m[0].size(); j++) 
            result[i][j] = (*this)[i][j] + m[i][j];

    return result;
}

Matrix Matrix::operator * (const Matrix& a) const {
    if (_m[0].size() != a._m.size())
        throw "Neodgovarajuce dimenzije";
    
    Matrix r (_m.size(), a._m[0].size());
    for (int i = 0; i < _m.size(); i++)
        for (int j = 0; j < a._m[0].size(); j++)
            for (int k = 0; k < _m[0].size(); k++)
	            r[i][j] += (*this)[i][k] * a[k][j];
    return r;
}

Matrix Matrix::coordProduct (const Matrix& m) const {
    if (_m.size() != m._m.size() || _m[0].size() != m._m[0].size())
        throw "Matrix dimensions must agree";

    Matrix result (_m.size(),  _m[0].size());

    for (int i = 0; i < _m.size(); i++)
        for (int j = 0; j < _m[0].size(); j++)
            result[i][j] = (*this)[i][j] * m[i][j];
    
    return result;
}

Matrix Matrix::transpose() const {
    Matrix res (_m[0].size(), _m.size());

    for (int i = 0; i < _m.size(); i++)
        for (int j = 0; j < _m[0].size(); j++)
            res[j][i] = (*this)[i][j];

    return res;
}

std::ostream& operator << (std::ostream& ostr, Matrix m) {
    m.write(ostr);
    return ostr;
}
