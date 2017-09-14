#define MOUDLE_CRYPTO_TF_C_

#include "new_taps_ca_debug.h"

void g_CA_PrintfBuffer(CHAR* buf, UINT32 len)
{
	UINT32 index = 0U;
	for(index = 0U; index < len; index++)
	{
		if(index < 15U)
		{
		}
		else if(0U == index%16U)
		{
			TF("\n");
			
		}
		else
		{
		}
		
		TF("0x%02x, ", (buf[index] & 0x000000FFU));
		

	}
	TF("\n");
   
}
