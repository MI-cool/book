#define COM8279         XBYTE[0x9FFF]                   //8279命令地址
#define DAT8279         XBYTE[0x9FFE]                   //8279数据地址
#define A8255           XBYTE[0xCFFC]                   //8255A口地址
#define B8255           XBYTE[0xCFFD]                   //8255B口地址
#define C8255           XBYTE[0xCFFE]                   //8255C口地址
#define COM8255         XBYTE[0xCFFF]                   //8255命令口地址
#define A8253           XBYTE[0xBFFC]                   //8253计数器0地址
#define B8253           XBYTE[0xBFFD]                   //8253计数器1地址
#define C8253           XBYTE[0xBFFE]                   //8253计数器地址
#define COM8253         XBYTE[0xBFFF]                   //8253命令口地址
#define ADCOM           XBYTE[0xACFF]                   //启动AD574口地址
#define ADHI            XBYTE[0xAEFF]                   //AD574高8位数据输出口地址
#define ADLO            XBYTE[0xAFFF]                   //AD574低4位数据输出口地址
#define HDA667			XBYTE[0xDFFE]					//DA667高8位数据输出口地址,输出同时启动转换
#define LDA667			XBYTE[0xDFFD]					//DA667低4位数据输出口地址,左对齐
#define LCDDATA			XBYTE[0x8FFE]					//SED1330写指令参数，显示数据，读状态标志
#define LCDORDER		XBYTE[0x8FFF]					//SED1330写指令代码，读显示数据和光标指针
#define SERA8253        XBYTE[0xEFFC]                   //串口8253计数器0地址
#define SERB8253        XBYTE[0xEFFD]                   //串口8253计数器1地址
#define SERC8253        XBYTE[0xEFFE]                   //串口8253计数器地址
#define SERCOM8253      XBYTE[0xEFFF]                   //串口8253命令口地址
#define SERDAT8251      XBYTE[0xFFFE]                   //8251数据地址
#define SERCOM8251      XBYTE[0xFFFF]                   //8251命令地址

sbit    PA0=P1^0;                                   //通道选择A0和8253的0通道使能
sbit    PA1=P1^1;                                   //通道选择A1和8253的1通道使能
sbit    PA2=P1^2;                                   //通道选择A2和8253的2通道使能
sbit    PALE=P3^5;                                  //8253的通道使能压入信号
sbit    adbusy=P1^7;                                    //AD574转换结束标志位
sbit    SCL=P1^3;                                   //I2C总线时钟口
sbit    SDA=P1^4;                                   //I2C总线数据口
sbit    RS485=P1^5;                         //RS485输入输出控制 1为接收0为发送
sbit    STAUT=P1^6;
sbit    STAUT1=P3^3;
sbit    STAUT2=P3^4;

sbit    ADNUMBER1=P1^0;                                 //AD574通道号低位
sbit    ADNUMBER2=P1^1;                                 //AD574通道号高位
sbit    ADNUMBER3=P1^2;                                 //AD574通道号高位

union {unsigned int dat16;			//16位到双8位的转换
                struct {unsigned char hi;unsigned char lo;}dat8;
               }dat168;
//键盘宏定义
#define PRINT           10
#define SEND            11
#define LEFT            12
#define RIGHT           14
#define UP              13
#define DOWN            18
#define ESC             15
#define ENTER           16
#define INPUT			17
//20键盘映射表
unsigned char code keytab20[]={	'0','1','2','3','4',
								'5','6','7','8','9',
								PRINT,SEND, LEFT, UP,  RIGHT,
								ESC,  ENTER,INPUT,DOWN,'A',

								'A','D','G','J','M',
								'P','S','V','Y','/',
								PRINT,SEND, LEFT, UP,  RIGHT,
								ESC,  ENTER,INPUT,DOWN,'A',

								'B','E','H','K','N',
								'Q','T','W','Z','(',
								PRINT,SEND, LEFT, UP,  RIGHT,
								ESC,  ENTER,INPUT,DOWN,'A',

								'C','F','I','L','O',
								'R','U','X','-',')',
								PRINT,SEND, LEFT, UP,  RIGHT,
								ESC,  ENTER,INPUT,DOWN,'A',
};

///键盘映射表
unsigned char code keytab18[]={	'1','2','3',ESC,INPUT,ENTER,'A','B',
								'4','5','6',LEFT, UP,RIGHT,'C','D',
								'7','8','9','0', DOWN,'E','F','G',								

								'A','D','G',ESC,INPUT,ENTER,'A','B',
								'J','M','P',LEFT, UP,RIGHT,'C','D',
								'S','V','Y','0', DOWN,'E','F','G',

								'B','E','H',ESC,INPUT,ENTER,'A','B',
								'K','N','Q',LEFT, UP,RIGHT,'C','D',
								'T','W','Z','0', DOWN,'E','F','G',

								'C','F','I',ESC,INPUT,ENTER,'A','B',
								'L','O','R',LEFT, UP,RIGHT,'C','D',
								'U','X',' ','0', DOWN,'E','F','G'
};
unsigned char onpower;
float vda667=0;
unsigned char bout485=0;
unsigned char rs485in=0;
unsigned char rs485out=0;
unsigned char rs232in=0;
unsigned int da667 = 0;
unsigned char  keytype;
unsigned char bdata tem8255a,tem8255b,tem8255c;
unsigned char do8255a[9],do8255b[9],do8255c[9];
unsigned char ok24c02 = 1;
sbit a1=tem8255a^0;
sbit a2=tem8255a^1;
sbit a3=tem8255a^2;
sbit a4=tem8255a^3;
sbit a5=tem8255a^4;
sbit a6=tem8255a^5;
sbit a7=tem8255a^6;
sbit a8=tem8255a^7;
sbit b1=tem8255b^0;
sbit b2=tem8255b^1;
sbit b3=tem8255b^2;
sbit b4=tem8255b^3;
sbit b5=tem8255b^4;
sbit b6=tem8255b^5;
sbit b7=tem8255b^6;
sbit b8=tem8255b^7;
sbit c1=tem8255c^0;
sbit c2=tem8255c^1;
sbit c3=tem8255c^2;
sbit c4=tem8255c^3;
sbit c5=tem8255c^4;
sbit c6=tem8255c^5;
sbit c7=tem8255c^6;
sbit c8=tem8255c^7;


unsigned char  keyinterrupt = 1;			//按键中断检测标志0
unsigned char buttonselect;//最后一次按键号
unsigned char adtemp1 = 0;//当前采集AD信号量
float result[8] = {0.0, 0.0, 0.0, 0.0,0.0, 0.0, 0.0, 0.0};
unsigned int adtemp[8] = {0,0,0,0,0,0,0,0};
unsigned char disstr[20];				//临时字串
//////////////////全局变量及标志定义////////////////////
//键盘中断信号量
OS_EVENT *KeySem;
//返回错误变量
INT8U lcnerr;
unsigned char key,keystaut = 0;							//最后一次获得的键值
bit bSecond;
unsigned char code Bmp015[]=
{
0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x27,0x7F,0xC0,0x00,0x25,0x1F,0xFF,0xFF,0x00,0x24,0x07,0xFF,0xFF,0xFF,0xF8,0x00,0x23,0x3F,0xFF,0xFF,0xFF,0xFF,0x00,0x23,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x21,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x21,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x21,0x7F,0xFF,0xFF,0xFF,0xFF,
0xFF,0xFF,0xC0,0x00,0x1F,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x1F,0x03,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x1F,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x1F,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x1F,0x7F,0xFF,0xFF,0xF8,0x00,0x01,0x06,0xFF,0xFF,0xFE,0x00,0x1F,0xFF,0xFF,0xFF,
0x00,0x03,0x3F,0xFF,0xFC,0x00,0x1E,0x01,0xFF,0xFF,0xFC,0x00,0x03,0x07,0xFF,0xFC,0x00,0x1E,0x03,0xFF,0xFF,0xC0,0x00,0x04,0xFF,0xF8,0x00,0x1E,0x07,0xFF,0xFF,0x00,0x05,0x1F,0xF0,0x00,0x1E,0x0F,0xFF,0xFE,0x00,0x05,0x0F,0xF0,0x00,0x1E,0x1F,0xFF,0xF8,0x00,0x05,0x03,0xE0,0x00,0x1E,0x3F,0xFF,0xE0,0x00,0x05,0x01,0xC0,0x00,0x1E,
0x7F,0xFF,0xC0,0x00,0x06,0x40,0x00,0x1E,0xFF,0xFF,0x80,0x00,0x24,0x01,0xFF,0xFF,0x00,0x25,0x01,0xFF,0xFC,0x00,0x25,0x03,0xFF,0xF8,0x00,0x25,0x07,0xFF,0xF0,0x00,0x25,0x07,0xFF,0xE0,0x00,0x25,0x0F,0xFF,0xC0,0x00,0x25,0x1F,0xFF,0xC0,0x00,0x25,0x1F,0xFF,0x80,0x00,0x02,0x7F,0xFF,0xFF,0xFF,0xE0,0x00,0x1E,0x3F,0xFF,0x00,0x03,
0x7F,0xFF,0xFF,0xFF,0xF0,0x00,0x1E,0x7F,0xFE,0x00,0x03,0x7F,0xFF,0xFF,0xFF,0xF8,0x00,0x1E,0x7F,0xFC,0x00,0x03,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x1E,0xFF,0xFC,0x00,0x02,0x01,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x1E,0xFF,0xF8,0x00,0x02,0x01,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x1D,0x01,0xFF,0xF8,0x00,0x02,0x03,0xFF,0xFF,0xFF,0xFF,0xF8,
0x00,0x1D,0x01,0xFF,0xF0,0x00,0x02,0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x1D,0x01,0xFF,0xE0,0x00,0x02,0x07,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x1D,0x01,0xFF,0xE0,0x00,0x02,0x0F,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x1D,0x03,0xFF,0xE0,0x00,0x02,0x1F,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x1D,0x07,0xFF,0xC0,0x00,0x02,0x1F,0xFF,0xFF,0xFF,0xFF,
0xF8,0x00,0x1D,0x07,0xFF,0xC0,0x00,0x07,0x7F,0xFF,0xFF,0xFF,0xFC,0x00,0x19,0x07,0xFF,0x80,0x00,0x07,0x7F,0xFF,0xFF,0xFF,0xF8,0x00,0x19,0x07,0xFF,0x80,0x00,0x07,0x7F,0xFF,0xFF,0xFF,0xF0,0x00,0x19,0x07,0xFF,0x00,0x08,0x7F,0xFF,0xFF,0xFF,0xE0,0x00,0x19,0x0F,0xFF,0x00,0x08,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x19,0x0F,0xFE,0x00,
0x07,0x01,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x19,0x0F,0xFE,0x00,0x07,0x01,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x19,0x1F,0xFE,0x00,0x02,0x01,0xFF,0xFF,0xFF,0xFF,0x01,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x19,0x1F,0xFE,0x00,0x02,0x03,0xFF,0xFF,0xFF,0xFF,0x81,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x19,0x1F,0xFE,0x00,0x02,0x03,0xFF,0xFF,0xFF,0xFF,
0x81,0xFF,0xFF,0xFF,0xFF,0x00,0x1A,0x1F,0xFC,0x00,0x02,0x07,0xFF,0xFF,0xFF,0xFF,0xC0,0xFF,0xFF,0xFF,0xFF,0x00,0x1A,0x1F,0xFC,0x00,0x02,0x0F,0xFF,0xFF,0xFF,0xFF,0xC0,0x3F,0xFF,0xFF,0xFE,0x00,0x1A,0x1F,0xFC,0x00,0x02,0x0F,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x1E,0x1F,0xFE,0x00,0x02,0x0F,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x1E,0x1F,
0xFE,0x00,0x02,0x1F,0xFF,0xFF,0xFF,0xFF,0x00,0x1F,0x1F,0xFC,0x00,0x02,0x1F,0xFF,0xFF,0xFF,0xFF,0x00,0x1F,0x1F,0xFC,0x00,0x02,0x3F,0xFF,0xFF,0xFF,0xFF,0x00,0x1F,0x1F,0xFC,0x00,0x02,0x7F,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x1E,0x1F,0xFC,0x00,0x02,0x7F,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x1E,0x1F,0xFC,0x00,0x06,0x07,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0x00,0x19,0x1F,0xFC,0x00,0x06,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x19,0x1F,0xFC,0x00,0x06,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x19,0x1F,0xFC,0x00,0x06,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x19,0x1F,0xFC,0x00,0x06,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x19,0x1F,0xFC,0x00,0x01,0x07,0xFF,0xFF,
0xFF,0xF8,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x19,0x1F,0xFC,0x00,0x01,0x07,0xFF,0xFF,0xFF,0xFC,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x19,0x1F,0xFE,0x00,0x01,0x0F,0xFF,0xFF,0xFF,0xFE,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x19,0x1F,0xFE,0x00,0x01,0x1F,0xFF,0xFF,0xFF,0xFE,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,
0x19,0x1F,0xFE,0x00,0x01,0x1F,0xFF,0xFF,0xFF,0xFE,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x19,0x0F,0xFE,0x00,0x01,0x3F,0xFF,0xFF,0xFF,0xFC,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x19,0x0F,0xFF,0x00,0x01,0x3F,0xFF,0xFF,0xFF,0xFC,0x00,0x20,0x0F,0xFF,0x00,0x01,0x7F,0xFF,0xFF,0xFF,0xFC,0x00,0x20,0x0F,0xFF,0x00,0x01,0x7F,
0xFF,0xFF,0xFF,0xF8,0x00,0x20,0x07,0xFF,0x80,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x20,0x07,0xFF,0x81,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x20,0x07,0xFF,0x81,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x20,0x07,0xFF,0xC0,0x00,0x04,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x19,0x03,0xFF,0xC0,0x00,0x04,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,
0x00,0x19,0x03,0xFF,0xC0,0x00,0x04,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x19,0x01,0xFF,0xE0,0x00,0x04,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x19,0x01,0xFF,0xF0,0x00,0x04,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x19,0x01,0xFF,0xF0,0x00,0x04,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x1A,0xFF,0xF8,
0x00,0x04,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x1A,0xFF,0xFC,0x00,0x04,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x1A,0x7F,0xFC,0x00,0x04,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x1A,0x7F,0xFE,0x00,0x04,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x1B,0x3F,0xFF,0x00,0x04,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,
0x00,0x1B,0x1F,0xFF,0x80,0x00,0x03,0x1F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x1B,0x1F,0xFF,0x80,0x00,0x08,0x30,0x00,0x1C,0x0F,0xFF,0xC0,0x00,0x08,0x78,0x00,0x1C,0x07,0xFF,0xE0,0x00,0x08,0xFC,0x00,0x1C,0x07,0xFF,0xF0,0x00,0x07,0x01,0xFE,0x00,0x1C,0x07,0xFF,0xF8,0x00,0x07,0x01,0xFF,0x00,0x1C,0x01,0xFF,0xFE,0x00,0x07,0x07,
0xFF,0x80,0x00,0x1B,0x01,0xFF,0xFF,0x00,0x07,0x0F,0xFF,0xC0,0x00,0x1C,0xFF,0xFF,0x00,0x07,0x1F,0xFF,0xE0,0x00,0x1C,0x7F,0xFF,0x80,0x00,0x06,0x7F,0xFF,0xE0,0x00,0x1C,0x3F,0xFF,0xE0,0x00,0x05,0x01,0xFF,0xFF,0xC0,0x00,0x1C,0x1F,0xFF,0xF8,0x00,0x05,0x03,0xFF,0xFF,0x00,0x1D,0x1F,0xFF,0xFC,0x00,0x05,0x0F,0xFF,0xFF,0x00,0x1D,
0x07,0xFF,0xFF,0x00,0x05,0x1F,0xFF,0xFE,0x00,0x1D,0x07,0xFF,0xFF,0xC0,0x00,0x04,0x7F,0xFF,0xFC,0x00,0x1D,0x03,0xFF,0xFF,0xFC,0x00,0x03,0x01,0xFF,0xFF,0xF8,0x00,0x1E,0xFF,0xFF,0xFE,0x00,0x03,0x0F,0xFF,0xFF,0xE0,0x00,0x1E,0x7F,0xFF,0xFF,0xE0,0x00,0x01,0x01,0xFF,0xFF,0xFF,0xC0,0x00,0x1E,0x3F,0xFF,0xFF,0xFF,0x0C,0x7F,0xFF,
0xFF,0xFF,0x80,0x00,0x1E,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x00,0x1F,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x20,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x20,0x7F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x20,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x20,0x0F,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,
0x00,0x21,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xF0,0x00,0x22,0x7F,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x22,0x0F,0xFF,0xFF,0xFF,0xFC,0x00,0x24,0x7F,0xFF,0xFF,0xC0,0x00,0x24,0x07,0xFF,0xF8,0x00,0x26,0x08,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0x2E,0x06,0x00,0x1F,0x03,0x00,0x03,0x03,0xC0,0x00,0x02,0x0F,0x80,0x00,0x1E,
0x0F,0x80,0x00,0x02,0x07,0xE0,0x00,0x02,0x1F,0xC0,0x00,0x06,0x0E,0x00,0x17,0x0F,0xC0,0x03,0x00,0x01,0x0F,0xE0,0x00,0x02,0x1F,0xC0,0x00,0x06,0x1F,0xFF,0xFC,0x07,0xC0,0x07,0x00,0x08,0x1E,0x00,0x09,0x0F,0xE0,0x07,0xC0,0x0F,0xF0,0x00,0x02,0x0F,0xC0,0x00,0x06,0x3F,0xFF,0xFE,0x0F,0xFF,0xFF,0x80,0x00,0x07,0x7F,0xFF,0xFF,0xFF,
0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x0F,0xE0,0x07,0xC0,0x0F,0xF0,0x00,0x02,0x0F,0xC0,0x03,0x80,0x1F,0x00,0x03,0x3F,0xFF,0xFE,0x0F,0xFF,0xFF,0xC0,0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFE,0x00,0x02,0x0F,0xE0,0x07,0xE0,0x0F,0xF0,0x00,0x02,0x0F,0xC0,0x07,0xFF,0xFF,0x80,0x00,0x02,0x3F,0x00,0x01,0x7E,0x0F,0xC0,0x0F,0x80,
0x00,0x07,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x02,0x07,0xE0,0x07,0xE0,0x0F,0xF0,0x00,0x02,0x0F,0xC0,0x07,0xFF,0xFF,0x80,0x00,0x02,0x3E,0x00,0x01,0x7C,0x0F,0x80,0x0F,0x80,0x00,0x06,0x01,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFF,0xFC,0x00,0x02,0x07,0xF0,0x07,0xE0,0x0F,0xF0,0x00,0x02,0x0F,0xC0,0x07,0xFF,0xFF,0x80,0x00,
0x02,0x3E,0x00,0x01,0x7C,0x07,0x80,0x07,0x80,0x00,0x06,0x01,0xFF,0x80,0x00,0x01,0x1F,0xC0,0x7F,0xFF,0xF8,0x00,0x02,0x07,0xF0,0x07,0xE0,0x0F,0xE0,0x00,0x02,0x0F,0xC0,0x07,0xFD,0xFF,0x80,0x00,0x02,0x1E,0x00,0x01,0x7C,0x07,0x80,0x0F,0x80,0x00,0x06,0x01,0xF0,0x00,0x02,0x1F,0xC0,0x00,0x01,0xFF,0xF0,0x00,0x02,0x03,0xF0,0x07,
0xE0,0x0F,0xE0,0x00,0x01,0x0F,0xCF,0xC0,0x03,0xF0,0x3F,0x00,0x03,0x1F,0xFF,0xFC,0x07,0xFF,0xFF,0x00,0x08,0x80,0x00,0x02,0x3F,0x80,0x00,0x01,0x0F,0xC0,0x00,0x02,0x03,0xF0,0x07,0xE0,0x0F,0xE0,0x00,0x01,0x1F,0xFF,0xFF,0xC3,0xE0,0x3F,0x00,0x03,0x1F,0xFF,0xF8,0x07,0xFF,0xFF,0x00,0x0B,0x3F,0x80,0x00,0x05,0x03,0xF0,0x07,0xE0,
0x0F,0xE0,0x00,0x01,0x3F,0xFF,0xFF,0xE3,0xE0,0x3E,0x00,0x03,0x1F,0xFF,0xF9,0x83,0xFF,0xFF,0x00,0x0B,0x7F,0x00,0x06,0x01,0xF0,0x07,0xE0,0x0F,0xE0,0x00,0x01,0x3F,0xFF,0xFF,0xE3,0xE0,0x3E,0x00,0x03,0x0F,0x80,0x73,0xC0,0x1C,0x1E,0x00,0x09,0x01,0xE0,0x7F,0x00,0x01,0x1F,0x00,0x04,0x01,0xF0,0x07,0xE0,0x07,0xE0,0x00,0x01,0x3F,
0xFF,0xFF,0xC3,0xE0,0x3E,0x00,0x05,0x07,0xE0,0x3C,0x00,0x0A,0x07,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x03,0x01,0xF0,0x07,0xC0,0x07,0xE0,0x00,0x01,0x3C,0x0F,0xC0,0x03,0xE0,0x3C,0x00,0x05,0x07,0xE0,0x3C,0x00,0x0A,0x07,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x03,0x01,0xF0,0x07,0xC0,0x07,0xE0,0x00,0x02,0x1F,0xC0,0x03,0xE0,0x7C,0x00,0x03,
0x04,0x00,0x01,0x0F,0xC0,0x78,0x00,0x0A,0x0F,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x03,0x01,0xF0,0x07,0xC0,0x07,0xE0,0x00,0x02,0x1F,0xC0,0x03,0xE0,0x7C,0x00,0x03,0x0F,0xFF,0xFF,0xFF,0xFF,0xF8,0x00,0x09,0x07,0xFF,0xFF,0xFF,0xFF,0xE0,0x00,0x03,0x01,0xF0,0x07,0xC0,0x07,0xE0,0x00,0x02,0x3F,0xE0,0x03,0xE0,0x7C,0x00,0x03,0x1F,0xFF,
0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x08,0x07,0xF0,0x00,0x02,0x1F,0xE0,0x00,0x03,0x01,0xF0,0x07,0xC0,0x07,0xE0,0x00,0x02,0x3F,0xF0,0x03,0xE0,0x7C,0x00,0x03,0x3F,0xFF,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x08,0x07,0xF0,0x00,0x02,0x1F,0xC0,0x00,0x03,0x01,0xF0,0x07,0xC0,0x07,0xE0,0x00,0x02,0x7F,0xF8,0x03,0xE0,0x7C,0x00,0x03,0x3F,0xFF,
0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x08,0x07,0xF0,0x00,0x02,0x1F,0xC0,0x00,0x03,0x01,0xE0,0x07,0xC0,0x07,0xE0,0x00,0x02,0xFF,0xFC,0x03,0xE0,0x7C,0x00,0x03,0x38,0x01,0xFC,0x0F,0x00,0x0B,0x07,0xF0,0x00,0x02,0x1F,0xC0,0x00,0x03,0x03,0xE0,0x07,0xC0,0x07,0xE0,0x00,0x01,0x01,0xFF,0xFE,0x03,0xE0,0x7C,0x00,0x04,0x03,0xF8,0x1F,0xF8,
0x00,0x0A,0x07,0xF0,0x00,0x02,0x1F,0xC0,0x00,0x03,0x03,0xE0,0x07,0xC0,0x07,0xE0,0x00,0x01,0x03,0xFF,0xFF,0x03,0xE0,0x7C,0x00,0x04,0x0F,0xE0,0x1F,0xFF,0x80,0x00,0x09,0x03,0xF0,0x00,0x02,0x1F,0xC0,0x00,0x03,0x03,0xE0,0x07,0xC0,0x07,0xE0,0x00,0x01,0x07,0xFF,0xFF,0x83,0xE0,0x7C,0x00,0x04,0x3F,0xC0,0x07,0xFF,0xF8,0x00,0x09,
0x03,0xFF,0xFF,0xFF,0xFF,0xC0,0x00,0x03,0x07,0xC0,0x07,0xC0,0x07,0xE0,0x00,0x01,0x0F,0xFF,0xCF,0x07,0xE0,0x7E,0x00,0x03,0x01,0xFF,0x80,0x00,0x01,0x7F,0xFF,0xC0,0x00,0x08,0x03,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x03,0x0F,0xC0,0x07,0xC0,0x07,0xE0,0x00,0x01,0x1F,0xDF,0xC0,0x07,0xC0,0x7E,0x00,0x03,0x0F,0xFE,0x00,0x02,0x0F,0xFF,
0xFE,0x00,0x08,0x03,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x03,0x0F,0xC0,0x07,0xC0,0x07,0xE0,0x00,0x01,0x7F,0x9F,0xC0,0x07,0xC0,0x7F,0x00,0x02,0x0F,0xFF,0xF8,0x00,0x02,0x01,0xFF,0xFF,0xC0,0x00,0x07,0x03,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x03,0x1F,0x80,0x07,0xC0,0x07,0xE0,0x00,0x01,0xFF,0x1F,0xC0,0x0F,0xC0,0x7F,0x00,0x02,0x3F,0xFF,
0xE0,0x1C,0x00,0x02,0x7F,0xFF,0xC0,0x00,0x07,0x03,0xFF,0x80,0x03,0xFF,0x80,0x00,0x03,0x3F,0x80,0x07,0xC0,0x07,0xE0,0x01,0xFF,0x1F,0xC0,0x0F,0xC0,0x7F,0x80,0x00,0x01,0x1F,0xFF,0xFF,0xFE,0x1F,0xFF,0xFF,0xFF,0x80,0x00,0x07,0x03,0xF0,0x00,0x02,0x3F,0x80,0x00,0x03,0x7F,0x00,0x01,0x07,0xC0,0x07,0xE0,0x03,0xFE,0x1F,0xC0,0x1F,
0x80,0x3F,0xC0,0x00,0x01,0x0F,0xFF,0xFF,0xFF,0x1F,0xFF,0xFF,0xFF,0x80,0x00,0x07,0x03,0xE0,0x00,0x02,0x3F,0x80,0x00,0x03,0xFF,0x00,0x01,0x07,0xC0,0x07,0xE0,0x01,0xFC,0x1F,0xC0,0x3F,0x80,0x3F,0xE0,0x02,0x07,0xCF,0xFF,0xFF,0x1F,0xFF,0xFF,0xFF,0x00,0x08,0x03,0xE0,0x00,0x02,0x3F,0x80,0x00,0x02,0x01,0xFE,0x00,0x01,0x07,0xC0,
0x07,0xE0,0x00,0x01,0x70,0x1F,0xC0,0x7F,0x80,0x1F,0xFE,0x7E,0x00,0x01,0x0F,0xC0,0x3F,0x1F,0xF0,0x7C,0x7E,0x00,0x08,0x03,0xE0,0x00,0x02,0x3F,0x80,0x00,0x02,0x07,0xFC,0x00,0x01,0x07,0xC0,0x07,0xF0,0x00,0x02,0x1F,0xC0,0xFF,0x00,0x01,0x1F,0xFF,0xFC,0x00,0x01,0x0F,0x80,0x1F,0x1F,0x00,0x01,0x3C,0x3C,0x00,0x08,0x03,0xE0,0x00,
0x02,0x3F,0x80,0x00,0x02,0x1F,0xF8,0x00,0x01,0x07,0xC0,0x07,0xF0,0x00,0x02,0x1F,0xC3,0xFF,0x00,0x01,0x0F,0xFF,0xFC,0x00,0x01,0x0F,0x80,0x1E,0x1F,0x00,0x01,0x3C,0x00,0x09,0x03,0xE0,0x00,0x02,0x3F,0x80,0x00,0x01,0x03,0xFF,0xF8,0x00,0x01,0x07,0xC0,0x07,0xF0,0x00,0x02,0x1F,0xCF,0xFE,0x00,0x01,0x07,0xFF,0xF8,0x00,0x01,0x0F,
0x80,0x1E,0x0F,0x80,0x3C,0x00,0x09,0x03,0xF0,0x00,0x02,0x3F,0x80,0x00,0x01,0x1F,0xFF,0xF0,0x00,0x01,0x0F,0xC0,0x07,0xF0,0x00,0x02,0x1F,0xC7,0xFC,0x00,0x01,0x07,0xFF,0xF8,0x00,0x01,0x0F,0x80,0x3E,0x0F,0x80,0x3C,0x00,0x09,0x03,0xF0,0x00,0x02,0x7F,0x80,0x00,0x01,0x1F,0xFF,0xC0,0x00,0x01,0x0F,0xC0,0x07,0xF0,0x00,0x02,0x1F,
0xC3,0xF8,0x00,0x01,0x03,0xFF,0xF0,0x00,0x01,0x0F,0xFF,0xFE,0x0F,0xC3,0xFC,0x00,0x09,0x03,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x01,0x0F,0xFF,0x80,0x00,0x01,0x0F,0xC0,0x03,0xF0,0x00,0x02,0x1F,0xC0,0xE0,0x00,0x02,0xFF,0xE0,0x00,0x01,0x0F,0xFF,0xFE,0x0F,0xFF,0xFC,0x00,0x09,0x03,0xFF,0xFF,0xFF,0xFF,0x80,0x00,0x01,0x0F,0xFE,0x00,
0x02,0x0F,0x80,0x03,0xF0,0x00,0x02,0x1F,0xC0,0x00,0x03,0x7F,0xE0,0x00,0x01,0x07,0xFF,0xFC,0x0F,0xFF,0xFC,0x00,0x09,0x03,0xFF,0xFF,0xFF,0xFF,0x00,0x02,0x03,0xFC,0x00,0x02,0x07,0x00,0x01,0x03,0xF0,0x00,0x02,0x0F,0xC0,0x00,0x03,0x1F,0x80,0x00,0x01,0x07,0xC0,0x7C,0x0F,0xFF,0xFC,0x00,0x09,0x03,0xFF,0xFF,0xFF,0xFF,0x00,0x08,
0x03,0xF0,0x00,0x02,0x0F,0xC0,0x00,0x09,0x07,0x00,0x01,0x3C,0x00,0x09,0x01,0xE0,0x00,0x02,0x3F,0x00,0x08,0x01,0xC0,0x00,0x02,0x0F,0x80,0x00,0x19,0x08,0x00,0x0C,0x07,0x00,0xFF,0x00,0xFF,0x00,0xFF,0x00,0xFF};