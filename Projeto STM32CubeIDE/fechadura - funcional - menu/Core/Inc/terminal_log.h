#include "stm32f1xx_hal.h"

#ifndef TERMINAL_LOG_H_
#define TERMINAL_LOG_H_

void terminalPrint (char string[]);
void terminalPrintNL (int n);
void terminalPrintInit ();
void terminalPasswordLog (int senha, int unlocked);
void terminalResetPassword();
void terminalPasswordChanged();

#endif /* TERMINAL_LOG_H_ */
