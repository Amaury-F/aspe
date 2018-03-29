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

/*
 * Permet d'utiliser des opérateurs entre deux couples d'entier.
 */
#define DEF_BINOP(OP)                           \
Pair Pair::operator OP(const Pair &a) {         \
    Pair r(a);                                  \
    r.x = this->x OP r.x;                       \
    r.y = this->y OP r.y;                       \
    return r;                                   \
}

DEF_BINOP(+)
DEF_BINOP(-)
DEF_BINOP(*)
DEF_BINOP(/)


#define DEF_OPEQ(OP)                                \
Pair& Pair::operator OP##=(const Pair &a) {         \
    x = x OP a.x;                                   \
    y = y OP a.y;                                   \
    return *this;                                   \
}

DEF_OPEQ(+);
DEF_OPEQ(-);
DEF_OPEQ(*);
DEF_OPEQ(/);

std::ostream &operator<<(std::ostream &flux, const Pair &p) {
    flux << "Pair(" << p.x << ',' << p.y << ')';
    return flux;
}
