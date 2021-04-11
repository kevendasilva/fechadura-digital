#include "stm32f1xx_hal.h"

#ifndef ANOTHER_KEYPAD_H_
#define ANOTHER_KEYPAD_H_

void setColumn (int column);
void setNumber (int row, int column);
int readRow (int row);
int keypadLoopF ();
int keypadLoopO ();


#endif /* ANOTHER_KEYPAD_H_ */
