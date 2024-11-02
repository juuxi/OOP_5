#include "polinom.h"
#include <math.h>

TPolinom::TPolinom()
{
    N = 0;
    printMode = EPrintModeClassic;
}

TPolinom::TPolinom(number _an, number* _roots, int _size)
{
    N = _size;
    roots.change_size(N);
    coefficients.change_size(N+1);
    for (int i = 0; i < N; i++)
        roots[i] = _roots[i];
    count_coefficients(_an);
    printMode = EPrintModeClassic;
}

void TPolinom::count_coefficients (number _an)

{
    for (int i = 0; i < N; i++)
        coefficients[i] = 0;
    coefficients[N] = _an;
    coefficients[1] = 1;
    coefficients[0] = -roots[0];
    for (int k = 2; k <= N; k++)
    {
        coefficients[k] = coefficients[k-1];
        for (int i = k-1; i > 0; i--)
            coefficients[i] = coefficients[i-1] - coefficients[i] * roots[k-1];
        coefficients[0] = -coefficients[0] * roots[k-1];
    }
    for (int i = 0; i <= N; i++)
          coefficients[i] = coefficients[i] * _an;
}

void TPolinom::set_print_mode (EPrintMode _printMode)
{
    printMode = _printMode;
}

ostream& operator<< (ostream& os, TPolinom& pol)
{
    if (pol.printMode == EPrintModeCanonic)
    {
        for (int i = pol.N; i > 0; i--)
            os << pol.coefficients[i] << " x^" << i << " + ";
        os << pol.coefficients[0] << std::endl;
    }
    else
    {
        os << pol.coefficients[pol.N] << " * ";
        for (int i = 0; i < pol.N - 1; i++)
            os << "(x - " << pol.roots[i] << ") * ";
        os << "(x - " << pol.roots[pol.N - 1] << ")" << std::endl;
    }
    return os;
}

QString& operator<< (QString& os, TPolinom& pol)
{
    if (pol.printMode == EPrintModeCanonic)
    {
        for (int i = pol.N; i > 0; i--)
        {
            os << pol.coefficients[i];
            os += " x^";
            os += QString().setNum(i);
            os += " + ";
        }
        os << pol.coefficients[0];
        os += "\n";
    }
    else
    {
        os << pol.coefficients[pol.N];
        os += " * ";
        for (int i = 0; i < pol.N - 1; i++)
        {
            os += "(x - ";
            os << pol.roots[i];
            os +=  ") * ";
        }
        os += "(x - ";
        os << pol.roots[pol.N - 1];
        os += ")";
        os += "\n";
    }
    return os;
}

istream& operator>> (istream& is, TPolinom& pol)
{
    is >> pol.coefficients[pol.N];
    for (int i = 0; i < pol.N; i++)
        is >> pol.roots[i];
    pol.count_coefficients(pol.coefficients[pol.N]);
    return is;
}

number TPolinom::count_value (number _point)
{
    number val = coefficients[N];
    for (int i = 0; i < N; i++)
        val = (_point - roots[i]) * val;
    return val;
}

void TPolinom::change_an(number _an)
{
    coefficients[N] = _an;
    count_coefficients(coefficients[N]);
}

void TPolinom::change_root(number _new_root, size_t _index)
{
    roots[_index] = _new_root;
    count_coefficients(coefficients[N]);
}

void TPolinom::change_size(int new_size)
{
    roots.change_size(new_size);
    coefficients.change_size(new_size + 1);
    N = new_size;
}

int TPolinom::get_size()
{
    return N;
}
