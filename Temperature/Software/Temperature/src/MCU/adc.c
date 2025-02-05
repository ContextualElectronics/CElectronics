/////////////////////////////////////////////////////////////////////////
///	\file adc.c
///	\brief STM32 adc MCU hardware layer.
///
///	Author: Ronald Sousa (Opticalworm)
/////////////////////////////////////////////////////////////////////////
#include "MCU/adc.h"

/////////////////////////////////////////////////////////////////////////
/// \brief enables the ADC so that we can read from the temperature channel
/////////////////////////////////////////////////////////////////////////
void ADC_On(void)
{
	RCC->APB2RSTR |= RCC_APB2RSTR_ADCRST;
	RCC->APB2RSTR &= ~RCC_APB2RSTR_ADCRST;
	RCC->APB2ENR |= RCC_APB2ENR_ADCEN;

	ADC->CCR |= ADC_CCR_TSEN; // enable the temperature sensor.

	// enable ADC
	ADC1->CR |= ADC_CR_ADEN;
	// wait until the ADC is ready to start conversion
	while ( ! ADC1->ISR & ADC_ISR_ADRDY ) ;

}

/////////////////////////////////////////////////////////////////////////
/// \brief disable the ADC and ensure that it doesn't consume power
/////////////////////////////////////////////////////////////////////////
void ADC_Off(void)
{
	ADC1->CR |= ADC_CR_ADDIS;
	// wait until the ADC is disable. ADDIS = 1: mean that the system is still in the process of turning of the ADC
	while( ADC1->CR & ADC_CR_ADDIS );

}

/////////////////////////////////////////////////////////////////////////
/// \brief reads the raw adc value from the select channel.
///
///	\param channel the ADC channel to select range 0 to 17
///	\param destination pointer to return the read value
///
///	\return true on success else adc is not open
/////////////////////////////////////////////////////////////////////////
uint_fast8_t ADC_Read(uint_fast32_t channel, uint_fast16_t * destination)
{
	// Check that the ADC is on
	if(!(ADC1->CR & ADC_CR_ADEN) || channel > 17 || !destination )
	{
		return FALSE;
	}

	// check to see if the ADC is already running, if so return false
	if (ADC1->CR & ADC_CR_ADSTART)
	{
		return FALSE;
	}

	// select channel
	ADC1->CHSELR = ((uint32_t)(1 << channel));

	// start the conversion
	ADC1->CR |= ADC_CR_ADSTART;

	// wait until ADC is done with conversion
	while(!(ADC1->ISR & ADC_ISR_EOC) ) ;

	*destination = (uint32_t)(0x0000FFFF & ADC1->DR);

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////
/// \brief return the normalized adc value from the select channel.
///
///	\param ADC channel
///	\param destination pointer to return the read value
///
///	\return true on success else adc is not open
/////////////////////////////////////////////////////////////////////////
uint_fast8_t ADC_ReadNorm(uint_fast32_t channel, float * destination)
{
	uint_fast8_t Status = ERROR;
	uint_fast16_t ADCSample;
	uint32_t ADCResolution;

	if (destination){
		Status = ADC_Read(channel, &ADCSample);

		if (TRUE == Status){

			if(0 != ADCSample) {
				ADCResolution = ((uint32_t)12 - (((uint32_t)(ADC1->CFGR1 & ADC_CFGR1_RES) >> 3) * 2));
				ADCResolution = ((uint32_t)(1 << ADCResolution))-1;
				*destination = ((float)ADCSample/ADCResolution);
			} else {
				*destination = 0;
			}
		}
	}

	return Status;
}

/* Temperature sensor calibration value address */
#define TEMP110_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7C2))
#define TEMP30_CAL_ADDR ((uint16_t*) ((uint32_t) 0x1FFFF7B8))
#define VDD_CALIB ((uint16_t) (330))
#define VDD_APPLI ((uint16_t) (300))


/////////////////////////////////////////////////////////////////////////
/// \brief return the converted/calibrated temperature reading in Degree
///
///	\param rawData the ADC raw data for the temperature sensor.
///
///	\return returns the converted value
///	\sa ADC_Read()
/////////////////////////////////////////////////////////////////////////
float ADC_ReturnCalibratedTemperature(uint_fast16_t rawData)
{
	int32_t Temperature; /* will contain the temperature in degree Fahrenheit */
	Temperature = (((int32_t) rawData * VDD_APPLI / VDD_CALIB) - (int32_t) *TEMP30_CAL_ADDR );
	Temperature = Temperature * (int32_t)(110 - 30);
	Temperature = Temperature / (int32_t)(*TEMP110_CAL_ADDR - *TEMP30_CAL_ADDR);
	Temperature = Temperature + 30;

	return ((float)(Temperature - 32.0) * ((float)(5.0/9.0)));
}
