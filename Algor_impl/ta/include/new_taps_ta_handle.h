#ifndef MOUDLE_CRYPTO_TA_HANDLE_H_
#define MOUDLE_CRYPTO_TA_HANDLE_H_

#include "new_taps_ta_type.h"

#define TA_MY_CRYPTO_VERIFY_UUID { 0x0ed8f0a9, 0xcfc1, 0x4a2c, \
		{ 0xb5, 0x71, 0xd9, 0x42, 0xf3, 0x96, 0xc4, 0x88 } }
		
/* Define the command index in this TA(Get Aes boot key) */
#define CMD_GEN_RANDOM_OPER                   1U 
#define CMD_SHA_OPER                          2U
#define CMD_AES_OPER                          3U
#define CMD_PBKDF_OPER                        4U
#define CMD_MAX_NUMBER                        5U
#define CMD_RSA_ENC_PKCS1_OPER            	  6U
#define CMD_RSA_DEC_PKCS1_OPER                7U
#define CMD_RSA_SIGN_PKCS1_OPER               8U
#define CMD_RSA_VERIFY_PKCS1_OPER             9U    
#define CMD_HMAC_OPER                         10U 
#define CMD_BASE64_OPER                       11U
#define CMD_BN_OPER                           14U 

/*STRUCTRUE DEFINITION USED ONLY BY THIS MODULE*/
#ifndef MOUDLE_CRYPTO_TA_HANDLE_C_
/*FUNCTIONS SUPPLIED BY THIS MODULE*/
extern int g_CryptoTaHandle_Random(uint32_t paramTypes, TEE_Param params[4]);
extern int g_CryptoTaHandle_Sha(uint32_t paramTypes, TEE_Param params[4]);
extern int g_CryptoTaHandle_Aes(uint32_t paramTypes, TEE_Param params[4]);
extern int g_CryptoTaHandle_Rsa(uint32_t paramTypes, TEE_Param params[4], UINT32 opMode, UINT32 padding);
extern int g_CryptoTaHandle_Pbkdf(uint32_t paramTypes, TEE_Param params[4]);
extern int g_CryptoTaHandle_hmac(uint32_t paramTypes, TEE_Param params[4]);
extern int g_CryptoTaHandle_base64(uint32_t paramTypes, TEE_Param params[4]);


#endif
#endif
