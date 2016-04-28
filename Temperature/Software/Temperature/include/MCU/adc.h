////////////////////////////////////////////////////////////////////////////////
/// \file adc.h
/// Author: Ronald Sousa (@Opticalworm)
////////////////////////////////////////////////////////////////////////////////

#ifndef __ADC_H__
#define __ADC_H__

	#include "common.h"

	void ADC_On(void);
	void ADC_Off(void);
	uint_fast8_t ADC_Read(uint_fast32_t channel, uint_fast16_t * destination);
	uint_fast8_t ADC_ReadNorm(uint_fast32_t channel, float * destination);
	float ADC_ReturnCalibratedTemperaturer(uint_fast16_t rawData);


#endif
