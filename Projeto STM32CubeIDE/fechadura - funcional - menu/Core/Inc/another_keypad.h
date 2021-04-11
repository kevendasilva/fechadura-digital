#include "stm32f1xx_hal.h"

#ifndef ANOTHER_KEYPAD_H_
#define ANOTHER_KEYPAD_H_

void setColumn(int column);
void setNumber(int row, int column);
void keypadLoop();
int readRow(int row);


#endif /* ANOTHER_KEYPAD_H_ */
