///////////////////////////////////////////////////////////////////////////////
/// \file DebugInterface.h
/// \author Ronald Sousa
/// \website www.HashDefineElectronics.com
/// \company Hash Define Electronics Ltd
///
/// \brief  handles the debug serial interface
///
///
/// \setion Project Dependency
/// Compiler: Microchip XC32 v1.34
/// library: Microchip Harmony v1.03.01
/// IDE: Microchip MPLABX v2.26
///////////////////////////////////////////////////////////////////////////////
#include "../common.h"
#ifdef EN_DEBUG_INTERFACE

#ifndef __DEBUG_INTERFACE_H__
#define __DEBUG_INTERFACE_H__

    #include "MCU/SeriaStructure.h"

    ///////////////////////////////////////////////////////////////////////////////
    /// \brief Define the maximun number of charater is string parameter can support
    ///////////////////////////////////////////////////////////////////////////////
    #define SDEBUG_STRING_LENGTH 20

    ///////////////////////////////////////////////////////////////////////////////
    /// \brief Define home many parameter we are willing to support per data
    /// transmission
    ///////////////////////////////////////////////////////////////////////////////
    #define SDEBUG_MAX_PARAMETER_SUPPORT 10

    ///////////////////////////////////////////////////////////////////////////////
    /// \brief Define the supported data type
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum{
        SDEnum_U = 'U',         ///< unsinged integer 32 bit
        SDEnum_I = 'I',         ///< singed integer 32 bit
        SDEnum_F = 'F',         ///< float 32 bit
        SDEnum_T = 'T',         ///< string
        SDEnum_L = 'L',         ///< boolean false
        SDEnum_H = 'H',         ///< boolean true

        // Lower case support
        SDEnum_u = 'u',         ///< unsinged integer 32 bit
        SDEnum_i = 'i',         ///< singed integer 32 bit
        SDEnum_f = 'f',         ///< float 32 bit
        SDEnum_t = 't',         ///< string
        SDEnum_l = 'l',         ///< boolean false
        SDEnum_h = 'h',         ///< boolean true

        SDEnum_E = 'E',         ///< Error code. unsinged integer
        SDEnum_S = 'S',         ///< Select option. unsinged integer 32 bit
        SDEnum_s = 's',         ///< Select option. unsinged integer 32 bit
    }SDebugDataTypeEnum;

    ///////////////////////////////////////////////////////////////////////////////
    /// \brief Define the supported data type
    ///////////////////////////////////////////////////////////////////////////////
    typedef enum{
        SDErrorEnum_E0 = 0,         ///< Incorrect command parameter
        SDErrorEnum_E1,             ///< Buffer overflow
        SDErrorEnum_E2,             ///< No parameter detected
        SDErrorEnum_E3,             ///< too many parameters
        SDErrorEnum_E4,             ///< Invalid parameter
        SDErrorEnum_E5,             ///< parameter data is too long. Its should be less than (SDEBUG_STRING_LENGTH - 2). see SDEBUG_STRING_LENGTH
    }SDebugErrorEnum;

    ///////////////////////////////////////////////////////////////////////////////
    /// \brief Define the paramter data holder
    ///////////////////////////////////////////////////////////////////////////////
    typedef union {
        struct{
            uint8_t Type;                           ///< see SDebugDataTypeEnum
            DataConverter Data;                     ///< The convert signed, unsinged and float
        };
        uint8_t String[SDEBUG_STRING_LENGTH];       ///< stores the text representation of the data received
    }SDebugParameterStruct;

    ///////////////////////////////////////////////////////////////////////////////
    /// \brief Define the parameter data structure
    ///////////////////////////////////////////////////////////////////////////////
    typedef struct{
        uint32_t ParameterLength;                                           ///< number of parameter detected
        SDebugParameterStruct Parameter[SDEBUG_MAX_PARAMETER_SUPPORT];      ///< holds all the detected parameters
    }SDebugType;

    ////////////////////////////////////////////////////////////////////////////////
    ///	\brief	Define the menu debug screen used by the serial interface
    ////////////////////////////////////////////////////////////////////////////////
    typedef struct SDMenuStruture{
        uint8_t *MenuTitle;                                                  ///< define the menu title
        void (*DrawOptions)(void);                                           ///< define the draw menu options
        void (*Process )(uint8_t *character);                                ///< define the process screen. this screen is passed every charater we've detect on the screen
        struct SDMenuStruture * (* MenuPointer) (SDebugType *systemData);    ///< define the current menu pointer that will handle the input data
    }SDMenuStruture;

    void SDebug_Init(SerialInterface *uartInterface);
    void SDebug_WriteString(uint8_t *source);
    uint_fast8_t SDebug_Monitor(void);

    ///////////////////////////////////////////////////////////////////////////////
    /// \brief Macro for clearing the terminal screen
    ///////////////////////////////////////////////////////////////////////////////
    #define CLEAR_TERMINAL_SCREEN() SDebug_WriteByte(0x0C)

#endif

#endif // EN_DEBUG_INTERFACE
