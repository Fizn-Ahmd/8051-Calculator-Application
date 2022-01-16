#include "calculator_app.h"

#define MAX_DIGITS_TO_CALCULATE 10

s16 atoi(s8 *);
void rearrange_char_arr(s8 *, s16);
void rearrange_int_arr(s16 *, s16);

void main()
{
	s16 i = 0, j = 0, k = 0;
	s16 converted_int_arr[MAX_DIGITS_TO_CALCULATE];
	s8 unconverted_char_arr[MAX_DIGITS_TO_CALCULATE];
	s8 sign_arr[MAX_DIGITS_TO_CALCULATE];
	s8 click;
	lcd_init();
	while (1) {
		click = key();
		if (click == 'C')
			return;
		if (click == '=') {
			unconverted_char_arr[i] = '\0';
			converted_int_arr[j] = atoi(unconverted_char_arr);
			break;
		}
		lcd_input(click);

		if (click == '+' || click == '*' || click == '/' ||
		    click == '-') {
			unconverted_char_arr[i] = '\0';
			i = 0;
			sign_arr[k] = click;
			k++;
			converted_int_arr[j] = atoi(unconverted_char_arr);
			j++;
		} else {
			unconverted_char_arr[i] = click;
			i++;
		}
	}
	sign_arr[k] = '\0';
	for (i = 0; sign_arr[i]; i++) {
		if (sign_arr[i] == '*') {
			converted_int_arr[i] =
			    converted_int_arr[i] * converted_int_arr[i + 1];
			rearrange_char_arr(sign_arr, i);
			rearrange_int_arr(converted_int_arr, i + 1);
			i--;
		}
		if (sign_arr[i] == '/') {
			converted_int_arr[i] =
			    converted_int_arr[i] / converted_int_arr[i + 1];
			rearrange_char_arr(sign_arr, i);
			rearrange_int_arr(converted_int_arr, i + 1);
			i--;
		}
	}
	for (i = 0; sign_arr[i]; i++) {
		if (sign_arr[i] == '+') {
			converted_int_arr[i] =
			    converted_int_arr[i] + converted_int_arr[i + 1];
			rearrange_char_arr(sign_arr, i);
			rearrange_int_arr(converted_int_arr, i + 1);
			i--;
		}
		if (sign_arr[i] == '-') {
			converted_int_arr[i] =
			    converted_int_arr[i] - converted_int_arr[i + 1];
			rearrange_char_arr(sign_arr, i);
			rearrange_int_arr(converted_int_arr, i + 1);
			i--;
		}
	}
	lcd_cmd(0xc0);
	lcd_integer(converted_int_arr[0]);

	while (1) {
		click = key();
		if (click == 'C')
			return;
	}
}

void rearrange_int_arr(s16 *p, s16 i)
{
	s16 j;
	for (j = i; j < MAX_DIGITS_TO_CALCULATE - 1; j++)
		p[j] = p[j + 1];
}

void rearrange_char_arr(s8 *p, s16 i)
{
	s16 j;
	for (j = i; p[j]; j++)
		p[j] = p[j + 1];
}

s16 atoi(s8 *p)
{
	s16 num = 0, j;
	for (j = 0; p[j]; j++) {
		num = (num * 10) + (p[j] - 48);
	}
	return num;
}
