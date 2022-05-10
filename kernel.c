#define BACKGROUND 0x07

void home();
unsigned int print(char *message, unsigned int line);


jaya(
{
	home();
	print("JayaOS.", 0);
};

void home(
{
	char *load = (char *) 0xb8000;
	unsigned int i=0;
	while(i < (80*25*2))
	{
		load[i]=' ';
		i++;
		load[i]=BACKGROUND;
		i++;
	};
};

unsigned int print(char *message, unsigned int line)
{
	char *load = (char *) 0xb8000;
	unsigned int i=0;

	i=(line*80*2);

	while(*message!=0)
	{
		if(*message=='\n')
		{
			line++;
			i=(line*80*2);
			*message++;
		} else {
			load[i]=*message;
			*message++;
			i++;
			load[i]=WHITE_TXT;
			i++;
		};
	};

	return(1);
};
