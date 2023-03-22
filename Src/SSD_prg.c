/*
 * SSD_prg.c
 *
 *  Created on: Feb 1, 2023
 *  Author: Ahmed Tarek Youssef
 */

#include"STD_TYPES.h"
#include"DIO_interface.h"

#include"SSD_pri.h"
#include"SSD_config.h"
#include"SSD_int.h"

static void	_delay_ms(u32 _ms)
{
	for(u32 i = 0; i < (_ms * 500) ; i++)
	{
		asm("NOP");
	}
}

void H_SSD_Void_init(void)
{
	//set all SSD pins as output
	M_DIO_void_setPinDir(SSD_LED_A_PORT, SSD_LED_A_PIN, OUT_2MHZ_PP) ;
	M_DIO_void_setPinDir(SSD_LED_B_PORT, SSD_LED_B_PIN, OUT_2MHZ_PP) ;
	M_DIO_void_setPinDir(SSD_LED_C_PORT, SSD_LED_C_PIN, OUT_2MHZ_PP) ;
	M_DIO_void_setPinDir(SSD_LED_D_PORT, SSD_LED_D_PIN, OUT_2MHZ_PP) ;
	M_DIO_void_setPinDir(SSD_LED_E_PORT, SSD_LED_E_PIN, OUT_2MHZ_PP) ;
	M_DIO_void_setPinDir(SSD_LED_F_PORT, SSD_LED_F_PIN, OUT_2MHZ_PP) ;
	M_DIO_void_setPinDir(SSD_LED_G_PORT, SSD_LED_G_PIN, OUT_2MHZ_PP) ;
	M_DIO_void_setPinDir(SSD_LED_DOT_PORT, SSD_LED_DOT_PIN, OUT_2MHZ_PP) ;

	//set enable pins at output
	M_DIO_void_setPinDir(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN, OUT_2MHZ_PP) ;
	M_DIO_void_setPinDir(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN, OUT_2MHZ_PP) ;

}


void H_SSD_Void_DisplayNumber(u8 number)
{
	if(number>99)
	{
		return ;
	}

	u8 uints = number % 10 ;
	u8 tens = number / 10 ;
	u32 i ;

	for(i=0;i<SSD_DISPLAY_TIME;i++)
	{
		switch(uints)
		{
		case 0:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_LOW) ;
			break ;
		case 1:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_LOW) ;
			break ;
		case 2:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 3:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 4:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 5:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 6:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 7:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_LOW) ;
			break ;
		case 8:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 9:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		}

		// enable DIG 1 (units)
		M_DIO_void_setPinVal(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN,DIO_LOW  ) ;
		// disable DIG 2 (tens)
		M_DIO_void_setPinVal(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN,DIO_HIGH ) ;
		//delay
		_delay_ms(10) ;
		// disable DIG 1 (units)
		//M_DIO_void_setPinVal(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN, DIO_HIGH) ;

		switch(tens)
		{
		case 0:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_LOW) ;
			break ;
		case 1:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_LOW) ;
			break ;
		case 2:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 3:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 4:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 5:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 6:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 7:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_LOW) ;
			break ;
		case 8:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		case 9:
			M_DIO_void_setPinVal(SSD_LED_A_PORT, SSD_LED_A_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_B_PORT, SSD_LED_B_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_C_PORT, SSD_LED_C_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_D_PORT, SSD_LED_D_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_E_PORT, SSD_LED_E_PIN, DIO_LOW) ;
			M_DIO_void_setPinVal(SSD_LED_F_PORT, SSD_LED_F_PIN, DIO_HIGH) ;
			M_DIO_void_setPinVal(SSD_LED_G_PORT, SSD_LED_G_PIN, DIO_HIGH) ;
			break ;
		}
		// enable DIG 2 (tens)
		M_DIO_void_setPinVal(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN, DIO_HIGH) ;
		M_DIO_void_setPinVal(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN,DIO_LOW ) ;
		_delay_ms(10) ;
		// disable DIG 2 (tens)
		M_DIO_void_setPinVal(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN, DIO_HIGH) ;
	}
}

void H_SSD_Void_DisplayOFF(void)
{
	// disable DIG 1 (units)
	M_DIO_void_setPinVal(SSD_DIG_1_EN_PORT, SSD_DIG_1_EN_PIN, DIO_HIGH) ;
	// disable DIG 2 (tens)
	M_DIO_void_setPinVal(SSD_DIG_2_EN_PORT, SSD_DIG_2_EN_PIN, DIO_HIGH) ;
}
