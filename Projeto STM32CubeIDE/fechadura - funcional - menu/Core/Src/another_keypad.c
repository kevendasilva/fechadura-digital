#include "another_keypad.h"
#include "lcd_v1.2.h"

int numeroOpcao = 0;
int linhaAnterior = 0;

void setColumn (int column)
{
	GPIOA->ODR = 0x40<<column;
}

int readRow (int row)
{
	row+=4;
	row=0x40<<row;

	return (int) HAL_GPIO_ReadPin(GPIOA, row);
}

void setNumber (int row, int column)
{
	char element[4][4][2] = {{"7\r","8\r","9\r","A\r"},
							 {"4\r","5\r","6\r","B\r"},
							 {"1\r","2\r","3\r","C\r"},
							 {"*\r","0\r","#\r","D\r"}};

	if ((row == 1) && (column == 3))
	{
		numeroOpcao++;
		if (numeroOpcao == 4)
		{
			numeroOpcao = 0;
			linhaAnterior = 3;
		}
		else
		{
			linhaAnterior = numeroOpcao - 1;
		}
		lcd_proxima_linha(numeroOpcao, linhaAnterior);
	}
	else if ((row == 3) && (column == 3))
	{
		lcd_escolhe_tela(numeroOpcao);
	}
	else
	{
		lcd_escreve_string(element[row][column]);
	}
}

int keypadLoopO ()
{
	int key;
	int mat[3][3] = {7,8,9,4,5,6,1,2,3};
	int pressed = 0 ;
	while (pressed != 1)
	{
		for (int j = 0 ; j < 4 ; j++)
		{
			setColumn(j);
			for (int i = 0; i < 4 ; i++)
			{
				if (readRow(i) == 1)
				{
					if (i==2 || i==1)
					{
						key = mat[i][j];
						pressed = 1;
						break;
					}
				}
		    }
			if (pressed == 1)  break;
		}
	  }
	  HAL_Delay(150);
	  return key;
}


int keypadLoopF ()
{
  int key[4]; // Assumirei como 4 dígitos
  int dig = 0;
  int mat[3][3] = {7,8,9,4,5,6,1,2,3};
  do
  {
      for (int j = 0 ; j < 4 ; j++)
      {
    	  setColumn(j);
    	  for (int i = 0; i < 4 ; i++)
    	  {
			  if (readRow(i) == 1)
			  {
				  if (dig == 0)
				  {
					  key[0] = mat[i][j];
					  lcd_posicao_do_cursor(2, 2);
					  lcd_escreve_string("1 numbers read\r");
					  HAL_Delay(500);
					  lcd_limpa_linha(1);
					  lcd_limpa_linha(2);
					  lcd_limpa_linha(3);
				  }
				  else if (dig == 1)
				  {
					  key[1] = mat[i][j];
					  lcd_posicao_do_cursor(2, 2);
					  lcd_escreve_string("2 numbers read\r");
					  HAL_Delay(1000);
					  lcd_limpa_linha(1);
					  lcd_limpa_linha(2);
					  lcd_limpa_linha(3);
				  }
				  else if (dig == 2)
				  {
					  key[2] = mat[i][j];
					  lcd_posicao_do_cursor(2, 2);
					  lcd_escreve_string("3 numbers read\r");
					  HAL_Delay(1000);
					  lcd_limpa_linha(1);
					  lcd_limpa_linha(2);
					  lcd_limpa_linha(3);
				  }
				  else if (dig == 3)
				  {
					  key[3] = mat[i][j];
					  lcd_posicao_do_cursor(2, 2);
					  lcd_escreve_string("4 numbers read\r");
					  HAL_Delay(1000);
					  lcd_limpa_linha(1);
					  lcd_limpa_linha(2);
					  lcd_limpa_linha(3);
				  }
				  dig = dig + 1;
			  }
    	  }
      }
  }
  while (dig<4);

  int senha = (1000 * (key[0])) + (100 * (key[1])) + (10 * (key[2])) + (key[3]);
  lcd_limpa_display();
  lcd_posicao_do_cursor(0, 0);
  lcd_escreve_string("Converted password\r");
  HAL_Delay(150);

  return senha;
}
