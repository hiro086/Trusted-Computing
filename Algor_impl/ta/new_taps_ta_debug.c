#define MOUDLE_CRYPTO_TA_DEBUG_C_

#include "new_taps_ta_debug.h"

void g_TA_Printf(CHAR* buf, UINT32 len);
void g_TA_Printf(CHAR* buf, UINT32 len)
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
		
		TF("0x%02x, ", (buf[index] & 0xFFU));

	}
	TF("\n\n");
}