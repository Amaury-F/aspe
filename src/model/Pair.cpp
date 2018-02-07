//
// Created by amaury on 29/01/18.
//

#include "Pair.h"

Pair::Pair(int x, int y): x(x), y(y) {}
Pair::Pair(const Pair &p) = default;

Pair::~Pair() = default;


bool Pair::operator==(const Pair &a) const {
    Pair b = *this;
    return a.x == b.x && a.y == b.y;
}

bool Pair::operator!=(const Pair &a)  const {
    Pair b = *this;
    return !(a == b);
}


#define DEF_OPEQ(OP)                                \
Pair& Pair::operator OP##=(const Pair &a) {    \
    x OP##= a.x;                                  \
    y OP##= a.y;                                  \
    return *this;                                   \
}

DEF_OPEQ(+);
DEF_OPEQ(-);
DEF_OPEQ(*);
DEF_OPEQ(/);

#define DEF_BINOP(OP)                           \
Pair Pair::operator OP(const Pair &a) {  \
    Pair r(a);                                  \
    r OP##= *this;                            \
    return r;                                   \
}

DEF_BINOP(+);
DEF_BINOP(-);
DEF_BINOP(*);
DEF_BINOP(/);