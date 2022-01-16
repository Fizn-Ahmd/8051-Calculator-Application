#include<reg51.h>

#include "calculator_app.h"

code u8 tan[4][4] = {{'7','8','9','/'},
					 {'4','5','6','*'},
					 {'1','2','3','-'},
					 {'C','0','=','+'}};

u8 key()
{
	u8 row, col;
	r0=r1=r2=r3=0;
	while(c0 & c1 & c2 & c3);
	r0 = 0;
	r1 = 1;
	r2 = 1;
	r3 = 1;
	if ((c0 & c1 & c2 & c3) == 0) {
		row = 0;
		goto col;
	}
	r1 = 0;
	r0 = 1;
	r2 = 1;
	r3 = 1;
	if((c0 & c1 & c2 & c3) == 0) {
		row = 1;
		goto col;
	}
	r2 = 0;
	r0 = 1;
	r1 = 1;
	r3 = 1;
	if((c0 & c1 & c2 & c3) == 0) {
		row = 2;
		goto col;
	}
	r3 = 0;
	r0 = 1;
	r1 = 1;
	r2 = 1;
	if((c0 & c1 & c2 & c3) == 0) {
		row = 3;
		goto col;
	}

	col:
	if(c0 == 0)
		col = 3;
	else if(c1 == 0)
		col = 2;
	else if(c2 == 0)
		col = 1;
	else if(c3 == 0)
		col = 0;

	while((c0 & c1 & c2 & c3) == 0);
	return tan[row][col];
}
