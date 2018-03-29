#ifndef JEU2D_PAIR_H
#define JEU2D_PAIR_H

#include <iostream>

/**
 * Gestion des couples d'entiers (utiles a la postion, la vitesse ...).
 */
class Pair {
public:
    Pair(int x, int y);
    Pair(const Pair &p);
    ~Pair();

    int x;
    int y;

    bool operator==(const Pair &a) const;
    bool operator!=(const Pair &a) const;

    Pair& operator+=(const Pair &a);
    Pair& operator-=(const Pair &a);
    Pair& operator*=(const Pair &a);
    Pair& operator/=(const Pair &a);

    Pair operator+(const Pair &a);
    Pair operator-(const Pair &a);
    Pair operator*(const Pair &a);
    Pair operator/(const Pair &a);

    friend std::ostream& operator<<(std::ostream& flux, const Pair& p);

};


#endif //JEU2D_PAIR_H
