#include "menu.h"
#include "lcd_v1.2.h"
#include "stm32f1xx_hal.h"

void menuInit ()
{
	 // Mensagem inicial (lcd)

	  lcd_posicao_do_cursor(0, 4);
	  lcd_escreve_string("Hello, user.\r");
	  lcd_posicao_do_cursor(2, 6);
	  lcd_escreve_string("Welcome!\r");
	  HAL_Delay(500);
	  lcd_limpa_display();
}

void menuMain ()
{
	lcd_limpa_display ();
	lcd_posicao_do_cursor(0, 0);
	lcd_escreve_string("Success!\r");
	HAL_Delay(1000);
	lcd_posicao_do_cursor(0, 0);
	lcd_escreve_string("~=~=~=~ Menu ~=~=~=~\r");
	lcd_posicao_do_cursor(1, 0);
	lcd_escreve_string("1. Open the door\r");
	lcd_posicao_do_cursor(2, 0);
	lcd_escreve_string("2. Change Password\r");
	lcd_posicao_do_cursor(3, 0);
	lcd_escreve_string("3. Reset to default\r");
}


void menuPassword ()
{
	  // Mensagem para receber a senha do usuário
	  lcd_posicao_do_cursor(0, 0);
	  lcd_escreve_string("Enter password:\r");
	  lcd_posicao_do_cursor(2, 0);
	  lcd_escreve_string(">\r");
	  lcd_posicao_do_cursor(2, 2);
}

void menuPasswordFail ()
{
	  HAL_Delay(1000);
	  lcd_limpa_display();
	  lcd_posicao_do_cursor(0, 0);
	  lcd_escreve_string("Incorrect password!\r");
}

void menu1 ()
{
	lcd_limpa_display();
	lcd_posicao_do_cursor(0, 0);
	lcd_escreve_string("Open door!\r");
}

void menu2 ()
{
	lcd_limpa_display();
	lcd_posicao_do_cursor(0, 0);
	lcd_escreve_string("New password\r");
	lcd_posicao_do_cursor(2, 0);
	lcd_escreve_string(">\r");
	lcd_posicao_do_cursor(2, 2);
}

void menu3 ()
{
	lcd_limpa_display();
	lcd_posicao_do_cursor(0, 0);
	lcd_escreve_string("Password changed!\r");
}

void menuE ()
{
	lcd_limpa_display();
	lcd_posicao_do_cursor(0, 0);
	lcd_escreve_string("Invalid option!\r");
}


