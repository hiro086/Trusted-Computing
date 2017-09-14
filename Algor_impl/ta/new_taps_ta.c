/*
 * Copyright (c) 2016, Linaro Limited
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice,
 * this list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 * this list of conditions and the following disclaimer in the documentation
 * and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#define STR_TRACE_USER_TA "NEW_TAPS"

#include "new_taps_ta_handle.h"
#include "new_taps_ta_rsa.h"

/*
 * Called when the instance of the TA is created. This is the first call in
 * the TA.
 */
TEE_Result TA_CreateEntryPoint(void)
{
	//DMSG("has been called");
	TF("Crypto verify task TA_CreateEntryPoint \n");
	return TEE_SUCCESS;
}



/*
 * Called when a new session is opened to the TA. *sess_ctx can be updated
 * with a value to be able to identify this session in subsequent calls to the
 * TA. In this function you will normally do the global initialization for the
 * TA.
 */
TEE_Result TA_OpenSessionEntryPoint(uint32_t paramTypes, TEE_Param __maybe_unused params[4], 
				void __maybe_unused **sessionContext)
{
	TEE_Result ret=TEE_SUCCESS;
	TF("Crypto verify task TA_OpenSessionEntryPoint\n");

	UNUSED(paramTypes);
	UNUSED(params);
	UNUSED(sessionContext);

	return ret;
}

//TEE_Result TA_OpenSessionEntryPoint(uint32_t param_types,
//		TEE_Param __maybe_unused params[4],
//		void __maybe_unused **sess_ctx)
//{
//	uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_NONE,
//						   TEE_PARAM_TYPE_NONE,
//						   TEE_PARAM_TYPE_NONE,
//						   TEE_PARAM_TYPE_NONE);
//	if (param_types != exp_param_types)
//		return TEE_ERROR_BAD_PARAMETERS;
//
//	/* Unused parameters */
//	(void)&params;
//	(void)&sess_ctx;
//
//	/*
//	 * The DMSG() macro is non-standard, TEE Internal API doesn't
//	 * specify any means to logging from a TA.
//	 */
//	DMSG("This is Hiro!\n");
//
//	/* If return value != TEE_SUCCESS the session will not be created. */
//	return TEE_SUCCESS;
//}
//
///*
// * Called when a session is closed, sess_ctx hold the value that was
// * assigned by TA_OpenSessionEntryPoint().
// */

void TA_CloseSessionEntryPoint(void __maybe_unused *session_context)
{
	TF("Crypto verify task TA_CloseSessionEntryPoint\n");
	UNUSED(session_context);
}
//void TA_CloseSessionEntryPoint(void __maybe_unused *sess_ctx)
//{
//	(void)&sess_ctx; /* Unused parameter */
//	DMSG("Goodbye!_new_taps\n");
//}

/*
 * Called when the instance of the TA is destroyed if the TA has not
 * crashed or panicked. This is the last call in the TA.
 */
//void TA_DestroyEntryPoint(void)
//{
//	DMSG("has been called");
//}
void TA_DestroyEntryPoint(void)
{
	TF("Crypto verify task TA_DestroyEntryPoint\n");
}

/*
 * Called when a TA is invoked. sess_ctx hold that value that was
 * assigned by TA_OpenSessionEntryPoint(). The rest of the paramters
 * comes from normal world.
 */
TEE_Result TA_InvokeCommandEntryPoint(void __maybe_unused *session_context,
				uint32_t cmd_id, 
				uint32_t paramTypes, TEE_Param params[4])
{
	TEE_Result l_ret = TEE_SUCCESS;
	int l_RetVal = FAIL;

	TF("CMD_ID = %d\n", cmd_id);

	/** 1) Handle the CA request message according to command index
	*      - EN_CMD_AES_KEY_GET: Get the aes boot key;
	*      - Default:            discard the message */
	switch(cmd_id)
	{
		case CMD_GEN_RANDOM_OPER: 
			TF("Start to generate random data!!!!\n");
			l_RetVal= g_CryptoTaHandle_Random(paramTypes, params);
			break;
		case CMD_SHA_OPER:
			TF("Entry the sha oper\n");
			l_RetVal = g_CryptoTaHandle_Sha(paramTypes, params);
			break;
		case CMD_AES_OPER:
			TF("Entry the aes operation!!!\n");
			l_RetVal = g_CryptoTaHandle_Aes(paramTypes, params);
			break;
		case CMD_PBKDF_OPER:
			TF("Entry pbkdf operation!!\n");
			l_RetVal = g_CryptoTaHandle_Pbkdf(paramTypes, params);
			break;
		case CMD_RSA_ENC_PKCS1_OPER:
			TF("Entry RSA1024_ENC_PKCS1!\n");
			l_RetVal = g_CryptoTaHandle_Rsa(paramTypes, params, EM_OP_ENC, PADDING_PKCS1);
			break;
		case CMD_RSA_DEC_PKCS1_OPER:
			TF("Entry RSA1024_DEC_PKCS1!\n");
			l_RetVal = g_CryptoTaHandle_Rsa(paramTypes, params, EM_OP_DEC, PADDING_PKCS1);
			break;
		case CMD_RSA_SIGN_PKCS1_OPER:
			TF("Entry RSA1024_SIGN_PKCS1!\n");
			l_RetVal = g_CryptoTaHandle_Rsa(paramTypes, params, EM_OP_SIGN, PADDING_PKCS1);
			break;
		case CMD_RSA_VERIFY_PKCS1_OPER:
			TF("Entry RSA1024_VERIFY_PKCS1!\n");
			l_RetVal = g_CryptoTaHandle_Rsa(paramTypes, params, EM_OP_VERIFY, PADDING_PKCS1);
			break;
		case CMD_HMAC_OPER:
			TF("Entry HMAC!\n");
			l_RetVal = g_CryptoTaHandle_hmac(paramTypes, params);
			break;
		case CMD_BASE64_OPER:
			TF("Entry BASE64!\n");
			l_RetVal = g_CryptoTaHandle_base64(paramTypes, params);
			break;

		default:
			l_RetVal = FAIL;
			break;
	}

	/**2) Check if the crypto operation is successful */
	if(FAIL == l_RetVal)
	{
		l_ret = TEE_FAIL;
	}
	else
	{
		l_ret = TEE_SUCCESS;
	}

	/**3) Return the result */
	return  l_ret;
}



//TEE_Result TA_InvokeCommandEntryPoint(void __maybe_unused *sess_ctx,
//			uint32_t cmd_id,
//			uint32_t param_types, TEE_Param params[4])
//{
//	(void)&sess_ctx; /* Unused parameter */
//
//	switch (cmd_id) {
//	case TA_NEW_TAPS_CMD_INC_VALUE:
//		return inc_value(param_types, params);
//#if 0
//	case TA_NEW_TAPS_CMD_XXX:
//		return ...
//		break;
//	case TA_NEW_TAPS_CMD_YYY:
//		return ...
//		break;
//	case TA_NEW_TAPS_CMD_ZZZ:
//		return ...
//		break;
//	...
//#endif
//	default:
//		return TEE_ERROR_BAD_PARAMETERS;
//	}
//}
//
//
//static TEE_Result inc_value(uint32_t param_types,
//	TEE_Param params[4])
//{
//	uint32_t exp_param_types = TEE_PARAM_TYPES(TEE_PARAM_TYPE_VALUE_INOUT,
//						   TEE_PARAM_TYPE_NONE,
//						   TEE_PARAM_TYPE_NONE,
//						   TEE_PARAM_TYPE_NONE);
//
//	DMSG("has been called_nt");
//	if (param_types != exp_param_types)
//		return TEE_ERROR_BAD_PARAMETERS;
//
//	DMSG("Got value: %u from NW_nt", params[0].value.a);
//	params[0].value.a++;
//	DMSG("Increase value to: %u _nt", params[0].value.a);
//	return TEE_SUCCESS;
//}
