
#include "lcd.h"
#include "math.h"

int tem=0;
void lcdPortInit(void)
{
//	rGPICON = rGPICON & (~0xffffffff) | 0xaaaaaaaa;
//	rGPIPUD = rGPIPUD & (~0xffffffff) | 0xaaaaaaaa;
	
//	rGPJCON = rGPJCON & (~0xffffff) | 0xaaaaaa;
//	rGPJPUD = rGPJPUD & (~0xffffff) | 0xaaaaaa;
	rGPICON =0;
	rGPICON |=0xaaaaaaaa;
	rGPIPUD =0;
	rGPIPUD |=0xaaaaaaaa;
	rGPJCON =0;
	rGPJCON |=0xaaaaaaaa;
	rGPJPUD =0;
	rGPJPUD |=0xaaaaaaaa;
}

void lcdInit(void)
{
	rVIDCON0 &= ~(0x03<<0);
	rWINCON0 &= ~(1<<0); 
	rMIFPCON &= ~(0x01<<3); 
	rSPCON &= ~(0x03);
  	rSPCON |= (0x01);    
  	/* lcd��ʾģʽ������ʱ�ӣ������źż���*/
	rVIDCON0= (VIDOUT<<26)|(PNRMODE<<17)|(CLKVALUP<<16)|(CLKVAL_F<<6)|(CLKDIR<<4)|(CLKSEL_F<<2)|(0<<0); 
//	rVIDCON0 |=3<<23;//���ݸ�ʽ��24BPP
//	rVIDCON0 |=3<<20;	
	//rVIDCON1|=(1<<7)|(0<<6)|(0<<5)|(0<<4); //vclk �����صõ�����
	rVIDCON1 &=~(1<<7);//vclk �½��صõ�����
	rVIDCON1 &=~(1<<4);
	rVIDCON1 &=~(1<<5);
	rVIDCON1 &=~(1<<6);
	
	rVIDTCON0=((VBP-1)<<16)|((VFP-1)<<8)|(VPW-1);   //��ֱ�����źŸ���
	rVIDTCON1=((HBP-1)<<16)|((HFP-1)<<8)|(HPW-1);   //ˮƽ�����źŸ���
	rVIDTCON2=((HEIGHT-1)<<11)|((WIDTH-1)<<0);      //ͼ����ʾ�ߴ�
	
	rWINCON0|=(11<<2);//24BPP
	rWINCON0 &=~(1<<13);//RGB
	
	rVIDOSD0A =(0<<11)|(0);  //�������Ͻ�λ��                    
	rVIDOSD0B =((WIDTH-1)<<11)|((HEIGHT-1)<<0);//�������½�λ��  
	rVIDOSD0C =(WIDTH*HEIGHT);//���ڴ�С
	
	rVIDW00ADD0B0 = (u32)LCD_BUFFER;  //�Դ���ʼ��ַ      
	rVIDW00ADD1B0 = (u32)((u32)LCD_BUFFER+LCD_BUF_SIZE);//�Դ������ַ
	rVIDW00ADD2 |= (WIDTH*4);//ҳ����
	
	rVIDCON0 |= 0x03; //video out enable and display control signal enable  
	rWINCON0 |= 0x01;//video out en
}

void clearScr(u32 c)
{
	u16 x,y ;

	for(x = 0;x < WIDTH; x++ )
    { 
		for( y = 0 ; y < HEIGHT ; y++ )
		{
			LCD_BUFFER[y][x] = c ;			
		}
    }
}
void disPoint(u16 x,u16 y,u32 c)
{
	if ( ( x < SCR_XSIZE) && ( y < SCR_YSIZE) )
		LCD_BUFFER[y][x] = c;
}
void disSizePoint(u16 x,u16 y,u32 c,u8 size)
{
    u16 x_p,y_p;
    for(x_p=x;x_p<x+size;x_p++)
    {
    	for(y_p=y;y_p<y+size;y_p++)
    	{
    		if ( ( x_p < SCR_XSIZE) && ( y_p < SCR_YSIZE) )
		    LCD_BUFFER[y_p][x_p] = c;	
    	}
    }

}
void disLine(u16 x1,u16 y1,u16 x2,u16 y2,u8 fat,u32 c)
{
	s16 x,y,x_p;
	if(x2>x1)
	{
		x=x2-x1;
		y=y2-y1;
		for(x_p=x1;x_p<=x2;x_p++)
		{
	 	 if(y2<y1)
		 LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = c;
		 else
	     LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = c;
		}	
	}
	else
	{
		x=x2-x1;
		y=y2-y1;
		for(x_p=x1;x_p>=x2;x_p--)
		{
	 	 if(y2<y1)
		 LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = c;
		 else
	     LCD_BUFFER[y*(x_p-x1)/x+y1][x_p] = c;
		}
	}	
}
void disImg(const u8 img[])
{
	u16 x,y;
	u32 x_size,y_size,offset=8;
	x_size = img[3]<<8 | img[2];	//read image size
	y_size = img[5]<<8 | img[4];
	for(y = 0;y < y_size; y++ )
    { 
		for( x = 0 ; x < x_size ; x++ )
		{
		
		LCD_BUFFER[y][x]=(img[offset++]<<16) | (img[offset++]<<8) | (img[offset++]<<0);
	//	offset +=3;
		//	LCD_BUFFER[y][x] = ((u32)(*(img_addr+3*offset))<<16) | ((u32)(*(img_addr+3*offset+1))<<8) | ((u32)(*(img_addr+3*offset+2)));			
		}
    }	
}



