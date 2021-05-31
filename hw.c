#include<stdio.h>
int main()
{
	FILE *fp;
    char ch;
    int i,pos;
    fp=fopen("file.txt","r");
    ch=getc(fp);
    while(ch!=EOF)
    {
    	putchar(ch);
    	ch=getc(fp);
	}
	if(feof(fp))
		printf("  : Contents in file\n");
	else
		printf("wrong");
    if(fp==NULL)
    {
        printf("\n\tFile does not exist..\n");
    }
    fseek(fp,0,SEEK_END);
    pos=ftell(fp);
    ch=getc(fp);
	i=0;
    while(i<pos)
    {
        i++;
        fseek(fp,-i,SEEK_END);
        printf("%c",fgetc(fp));
    }
    printf("  : Reversed content");
    return 0;
}
