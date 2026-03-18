#ifndef PP_QR_H
#define PP_QR_H

#include "matrix.h"

namespace pp {

class qr {
public:
    matrix Q;
    matrix R;

    qr(const matrix& A);
};

}

#endif