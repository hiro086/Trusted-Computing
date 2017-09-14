#ifndef MOUDLE_CRYPTO_TA_PBKDF_H_
#define MOUDLE_CRYPTO_TA_PBKDF_H_

#include "new_taps_ta_type.h"

#ifndef MOUDLE_CRYPTO_TA_PBKDF_C_

extern void g_CryptoTaPbkdf_PBKDF2(CHAR P[],int Plen, CHAR S[], int Slen, int c,int dkLen, CHAR* output);
#endif

#endif  /* MOUDLE_NAME_H*/