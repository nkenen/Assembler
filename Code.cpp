#include "Code.h"

Code::Code()
{
	
}


Code::~Code()
{
}


int Code::dest(char *dst) {
	int i = 1;
	if (dst[0] != '\0') {
		while (dst != sdst[i] && i != 8)
		{
			i++;
		}
		return i;
	}

	return 0;
}


int Code::comp(char *cmp) {

	int i = 0;
	if (cmp[0] != '\0') {
		while (cmp != scmp[i] && i != 28)
		{
			i++;
		}
	}
	switch (i)
	{
	case 0:return 0b0101010;break;//0
	case 1:return 0b0111111;break;//1
	case 2:return 0b0111010;break;//-1
	case 3:return 0b0001100;break;//D	
	case 4:return 0b0110000;break;//A
	case 5:return 0b0001101;break;//!D
	case 6:return 0b0110001;break;//!A
	case 7:return 0b0001111;break;//-D
	case 8:return 0b0110011; break;//-A
	case 9:return 0b0011111; break;//D+1
	case 10:return 0b0110111; break;//A+1
	case 11:return 0b0001110; break;//D-1
	case 12:return 0b0110010; break;//A-1
	case 13:return 0b0000010; break;//D+A
	case 14:return 0b0010011; break;//D-A
	case 15:return 0b0000111; break;//A-D
	case 16:return 0b0000000; break;//D&A
	case 17:return 0b0010101; break;//D|A
	case 18:return 0b1110000; break;//M
	case 19:return 0b1110001; break;//!M
	case 20:return 0b1110011; break;//-M
	case 21:return 0b1110111; break;//M+1
	case 22:return 0b1110010; break;//M-1
	case 23:return 0b1000010; break;//D+M
	case 24:return 0b1010011; break;//D-M
	case 25:return 0b1000111; break;//M-D
	case 26:return 0b1000000; break;//D&M
	case 27:return 0b1010101; break;//D|M
	default:
		break;
	}
	return -1;
}


int Code::jump(char *jmp) {

	int i = 1;
	if (jmp[0] != '\0') {
		while (jmp != sjmp[i] && i != 8)
		{
			i++;
		}
		return i;
	}
	
	return 0;
	
}