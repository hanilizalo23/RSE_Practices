#include "MK64F12.h"
#include "DAC.h"

void initDAC(void){

	SIM->SCGC2 = SIM_SCGC2_DAC0_MASK;
	DAC0->C0 = 0xC0;
	DAC0->DAT[0].DATL = 0;
	DAC0->DAT[0].DATH = 0;
}

void DacSend(uint32_t Data){
    DAC0->DAT[0].DATL = (Data) & 0xFF;
    DAC0->DAT[0].DATH = (Data >> 8) & 0x0F;
}