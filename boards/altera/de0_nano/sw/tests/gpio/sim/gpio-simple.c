#define LIM 1000000

char* gpio_base = (char*) 0x91000000;

int add(int a,int b)
{
	int c;
	c=a+b;
	c=c*10;
	c=c-1;
	return c;
}

int main(void)
{	
	add(1,2);
	volatile unsigned long i=0;
	*(gpio_base+1) = 0xff;
	while(1)
	{
		*(gpio_base+0) = 0x55; 
		for(i=0;i<LIM;i++);		
		*(gpio_base+0) = 0xaa;  
		for(i=0;i<LIM;i++);		
		
    }
	
	return 0;
}

 
