/************************************/
/*	Author	  :	ESLAM_HOSNY			*/
/*	SWC		  : TIMERS				*/
/*  Layer	  : APP					*/
/*	Version	  :	1.0		  			*/
/*	Date	  :	December 8, 2022	*/
/*	Last Edit : N/A					*/
/************************************/
#define F_CPU	8000000UL
#include "LSTD_types.h"
#include "LBIT_math.h"
#include "MDIO_interface.h"
#include "PORT_interface.h"
#include "MGIE_interface.h"
#include "MTIM_interface.h"
#include "MADC_interface.h"

void LED(void);
int main (void)
{

	PORT_voidInit();

	TIMER0_Init();
	SET_CALLPACK(&LED);
	MGIE_voidEnableGIE();



	while(1)
	{

	}
	return 0;
}

void LED(void)
{
	static u8 L_u8ReturnValue=1;
	static u8 count=0;
	count++;
	if(count==4000)
	{

		TOGGLE_BIT(L_u8ReturnValue,0);
		MDIO_u8SetPinValue(MDIO_PORTB, 0, L_u8ReturnValue);
		count=0;
	}


}
