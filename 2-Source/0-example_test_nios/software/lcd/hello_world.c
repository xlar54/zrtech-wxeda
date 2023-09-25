
#include "lcd1602.h"

int main (void) __attribute__ ((weak, alias ("alt_main")));     //���������ڸ�Ϊalt_main()������ʹ
                                                                //�ܶ�����������أ����Դ���С���볤��
void alt_main()
{
    alt_u8 i;

    Lcd_Init();

	//���������ŵ���ʾ*****************
	Lcd_WriteCommand(0x2c); //re=1,2c
	for(i=0; i<16; i++)
	{
		Lcd_Icon(i,0x00);
		usleep(1);
	}

	//��ʾ�������****************************
	Lcd_Icon(13, 0xff);		//13,���ŷ�ͼ�꣬���Բ����ͼƬ��0xff�У���5λ����ͼ�꣬
	Lcd_Icon(0, 0xff);		//�ŷ�ͼ��ֻ��һ��������ͼ��5λ��������+4���ź�
	//******************************************
	Lcd_WriteCommand(0x2a);	//��ʾ�����ַ���re=0,2a

	//�������ַ�����ʾ
	Lcd_Prints(0, 0, "Hello World!");
	Lcd_Prints(0, 1, "Espire_I V2.00");

	while(1);
}