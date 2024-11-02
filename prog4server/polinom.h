#ifndef POLINOM_H
#define POLINOM_H

#include "number.h"
#include "array.h"

enum EPrintMode
{
    EPrintModeClassic,
    EPrintModeCanonic,
};

class TPolinom
{
    EPrintMode printMode;
    TArray roots;
    TArray coefficients;
    int N;
public:
    TPolinom();
    TPolinom(number, number*, int);
    friend ostream& operator<< (ostream&, TPolinom&);
    friend QString& operator<< (QString&, TPolinom&);
    friend istream& operator>> (istream&, TPolinom&);
    void set_print_mode (EPrintMode);
    number count_value (number);
    void change_an (number);
    void change_root (number, size_t);
    void change_size (int);
    int get_size();
private:
    void count_coefficients(number);
};

#endif // POLINOM_H
