#include "ds18b20.h"
#include "delay.h"
#include "uart.h"
//��λ����
u8 DS18B20_Reset(void)  
{  
    u8 i = 0;  
      
    Set18b20IOout();    //�����˿��������ģʽ  
    Write18b20IO(1);  
    Delay_US(1);  
    Write18b20IO(0);    //��������480us~240us  
    //Delay_US(500);      //>480US��ʱ 
    Delay_US(500);  
    Write18b20IO(1);  
    Delay_US(2);        //��λ���  
    Set18b20IOin();     //�����˿ڸ�������ģʽ  
    while(Read18b20IO())    //�ȴ��͵�ƽӦ���ź�  
    {  
        i++;  
        Delay_US(1);  
        if(i > 100)  
            return 1;       //�ȴ���ʱ,��ʼ��ʧ��,����1;  
    }  
    //Delay_US(250);          //�����ظ��ź� 
    Delay_US(250);  
    return 0x00;            //��⵽DS18B20,���ҳ�ʼ���ɹ�  
}  
u8 DS18B20_ReadData(void)  
{  
    u8 i,dat = 0;  
      
    for(i = 0;i < 8;i ++)  
    {  
        Set18b20IOout();    //�����˿��������ģʽ  
        Write18b20IO(0);    //��������10-15us  
        dat >>= 1;  
        Delay_US(15);  
        Write18b20IO(1);    //�ͷ�����  
        Set18b20IOin();     //�����˿ڸ�������ģʽ  
        Delay_US(1);  
        if(Read18b20IO())   //��ȡ����,��ȡ���Լ��ʱ40-45us  
            dat |= 0x80;  
        Delay_US(42);  
    }  
    return dat;  
}  
void DS18B20_WriteData(u8 dat)  
{  
    u8 i;  
      
    Set18b20IOout();    //�����˿��������ģʽ  
    for(i = 0;i < 8;i ++)  
    {  
        Write18b20IO(0);        //��������10-15us  
        Delay_US(15);  
        Write18b20IO(dat & 0x01);  //д������λ,����20-45us  
        Delay_US(45);  
        Write18b20IO(1);        //�ͷ�����  
        dat >>= 1;  
        Delay_US(2);  
    }  
}  
s16 DS18B20_ReadTemper(void)  
{   
    u8 th,tl;  
    s16 data;  
      
    if(DS18B20_Reset())   
    {  
    	//Uart_Printf("reset error1\n");
        return 0xffff;  //���ش���  
    } 
    //Uart_Printf("reset ok\n"); 
    Delay_MS(2);
    DS18B20_WriteData(0xcc);    //���������к�  
    DS18B20_WriteData(0x44);    //�����¶�ת�� 
    Delay_MS(2); 
    DS18B20_Reset();  
    Delay_MS(2);
    DS18B20_WriteData(0xcc);    //���������к�  
    DS18B20_WriteData(0xbe);    //��ȡ�¶� 
    Delay_MS(5); 
    tl = DS18B20_ReadData();    //��ȡ�Ͱ�λ  
    th = DS18B20_ReadData();    //��ȡ�߰�λ  
    data = th;  
    data <<= 8;  
    data |= tl;  
    data *= 625;               //�¶�ֵ����100������ȷ��2λС�� 
    data /=100; 
     
    return data;  
}  
