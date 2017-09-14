#ifndef MOUDLE_CRYPTO_TA_OTHER_H_
#define MOUDLE_CRYPTO_TA_OTHER_H_

#include "new_taps_ta_type.h"

#ifndef MOUDLE_CRYPTO_TA_OTHER_C_

extern void g_CryptoTaOther_Random(UINT32 len, CHAR* output);

extern void g_CryptoTaOther_base64(CHAR* input, UINT32 lenIn, CHAR* output, UINT32 lenOut, UINT32 oper);

#endif

#endif  /* MOUDLE_NAME_H*/
