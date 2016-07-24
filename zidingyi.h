/*******************************************************************************
**************我自己写的头文件，包含一些常用宏定义和简单库函数******************
********你也可以随便往里面加，声明函数可以放在.h里面,函数内容放在.c里面*********
****************      献给我最可爱最用功的小包子    ****************************
******************             (*^_^*)           *******************************
**********************                        **********************************
****************************  (°ω °) ****************************************
*******************************************************************************/
//**************************cpu设置*************************
#define CPU_F ((double)8000000)   //外部高频晶振8MHZ

//**********************延时函数宏定义*************************
#define delay_us(x)   (__delay_cycles((double)x*CPU_F/1000000.0))
#define delay_ms(x)   (__delay_cycles((double)x*CPU_F/1000.0))
 
//串口波特率计算，当BRCLK=CPU_F时用下面的公式可以计算，否则要根据设置加入分频系数
#define baud           9600                                //设置波特率的大小
#define baud_setting   (uint)((ulong)CPU_F/((ulong)baud))  //波特率计算公式
#define baud_h         (uchar)(baud_setting>>8)            //提取高位
#define baud_l         (uchar)(baud_setting)               //低位


#define uchar unsigned char
#define uint unsigned int
#define ulong unsigned long

void WDT_Init();
void UART_Init();
void Clock_Init();
void Send_Byte(uchar data);
void putc(char *x);

//彩屏/12864液晶/1602液晶的数据口，三液晶共用
#define DataDIR         P4DIR                     //数据口方向
#define DataPort        P4OUT                     //P4口为数据口
//12864/1602液晶控制管脚
#define RS_CLR	        P5OUT &= ~BIT5           //RS置低
#define RS_SET	        P5OUT |=  BIT5           //RS置高

#define RW_CLR	        P5OUT &= ~BIT6           //RW置低
#define RW_SET	        P5OUT |=  BIT6           //RW置高

#define EN_CLR	        P5OUT &= ~BIT7           //E置低
#define EN_SET	        P5OUT |=  BIT7           //E置高

#define PSB_CLR	        P5OUT &= ~BIT0            //PSB置低，串口方式
#define PSB_SET	        P5OUT |=  BIT0            //PSB置高，并口方式

#define RST_CLR	        P5OUT &= ~BIT1            //RST置低
#define RST_SET	        P5OUT |= BIT1             //RST置高
void LCD_PORT_Init();
void LCD_write_com(unsigned char com);
void LCD_write_data(unsigned char data);
void LCD_clear(void);
void LCD_write_str(unsigned char x,unsigned char y, char *s);
void LCD_write_char(unsigned char x,unsigned char y,unsigned char data); 
void LCD_init(void);
