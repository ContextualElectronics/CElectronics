///////////////////////////////////////////////////////////////////////////////
/// \file Debug_MainMenu.h
/// \author Ronald Sousa
/// \website www.HashDefineElectronics.com
/// \company Hash Define Electronics Ltd
///
/// \brief  handles the debug main screen used by our serial interface
///////////////////////////////////////////////////////////////////////////////
#include "common.h"
#ifdef EN_DEBUG_INTERFACE

#include "Terminal/DebugInterface.h"
#include "MCU/led.h"

///////////////////////////////////////////////////////////////////////////////
/// \brief Draw main menu
///////////////////////////////////////////////////////////////////////////////
static void SDebug_DrawMainMenu(void)
{
    SDebug_WriteString( "\n\r"
                        "S1. Set LED State\n\r"
                      );
}
///////////////////////////////////////////////////////////////////////////////
/// \brief This is the menu options
///////////////////////////////////////////////////////////////////////////////
typedef enum
{
    SDCommand_LEDControl = 1,
} SDebug_CommandCode;

///////////////////////////////////////////////////////////////////////////////
/// \brief Process the screen command
///
/// \param SystemData system parameter data structure
/// \return true on success else false
///////////////////////////////////////////////////////////////////////////////
static struct SDMenuStruture * SDebug_MainMenu(SDebugType *SystemData)
{
    uint8_t Buffer[1024];
    uint32_t CurrentTickCounter = 0;
    float TickInSecond = 0;
    static uint32_t NumberOFPulse = 1;
    static uint32_t PulseUpdateRate = 100;

    switch(SystemData->Parameter[0].Data.ui32_t[0])
    {
        case SDCommand_LEDControl:

            if( SystemData->ParameterLength > 1)
            {
                if(SystemData->Parameter[1].Data.ui32_t[0])
                {
                    Led_On();
                }
                else
                {
                    Led_Off();
                }
            }
            else
            {
                Led_Toggle();
            }

        break;

        default:
            break;
    }

    return 0;
}

///////////////////////////////////////////////////////////////////////////////
/// \brief This is the default menu screen
///////////////////////////////////////////////////////////////////////////////
struct SDMenuStruture  DefaultMenu = {
    "Main Menu",
    SDebug_DrawMainMenu,
    NULL,
    SDebug_MainMenu
};

#endif // EN_DEBUG_INTERFACE
