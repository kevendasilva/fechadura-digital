#include "terminal_log.h"
#include <string.h>
#include "stm32f1xx_hal.h"

UART_HandleTypeDef huart1;

void terminalPrint (char string[])
{
	// Letra
	unsigned char letra;

	// Contador
	int i = 0;

	// Imprimindo a string no terminal
	for (i = 0 ; i < strlen(string) ; i++)
	{
		// Letra em hexa
		letra = (unsigned char) string[i];

		// Imprimindo o dado
		HAL_UART_Transmit (&huart1, &letra, 1, 10);
	}

}

void terminalPrintNL (int n)
{
	// Contador
	int j;

	// Pulando n linhas
	for (j = 0 ; j < n ; j++)
	{
		terminalPrint("\r\n");
	}
}

void terminalPrintInit ()
{
	// Mensagem inicial (terminal)
	terminalPrint("***************************************");
	terminalPrintNL(1);
	terminalPrint("*                                     *");
	terminalPrintNL(1);
	terminalPrint("*        DEADBEEF - Enterprises       *");
	terminalPrintNL(1);
	terminalPrint("*                                     *");
	terminalPrintNL(1);
	terminalPrint("*     Digital Door Lock - V 1.0.3.    *");
	terminalPrintNL(1);
	terminalPrint("*                                     *");
	terminalPrintNL(1);
	terminalPrint("*                                     *");
	terminalPrintNL(1);
	terminalPrint("***************************************");
	terminalPrintNL(2);


	terminalPrint("Digital door lock started successfully!");
	terminalPrintNL(2);
	HAL_Delay(50);
	terminalPrint("Welcome, user.");

}

void terminalPasswordLog(int senha, int unlocked)
{

	// Mensagem caso usuário tente entrar
	terminalPrintNL(2);
	terminalPrint("Attempt to unlock the door with the password: 1111");


	if (unlocked)
	{
		terminalPrintNL(2);
		terminalPrint("Access Allowed!");
	}
	else
	{
		terminalPrintNL(2);
		terminalPrint("Access Denied!");
	}

}

void terminalResetPassword () {
	terminalPrintNL(2);
	terminalPrint("Password reset to factory default.");
	terminalPrintNL(2);
}

void terminalPasswordChanged () {
	terminalPrintNL(2);
	terminalPrint("Request to change password.");
	terminalPrintNL(2);
}
