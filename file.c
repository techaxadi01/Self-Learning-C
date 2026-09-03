#include <stdio.h>
#include <stdlib.h>

int main(){

FILE *fp;
char ch;
char str[100];

fp=fopen("sample.txt","w");

if (fp==NULL)
{
printf("error opening file in write mode\n");
exit(1);
}

printf("enter text to write in file\n");
fgets(str,sizeof(str),stdin);

fprintf(fp, "%s", str);

fclose(fp);
printf("Data written successfully\n\n");

fp=fopen("sample.txt","a");

if (fp==NULL)
{
printf("error opening file in append mode\n");
exit(1);
}

printf("enter text to append\n");
fgets(str,sizeof(str),stdin);


fprintf(fp, "%s", str);

fclose(fp);
printf("Data appended successfully\n\n");

fp=fopen("sample.txt","r");

if (fp==NULL)
{
printf("error opening file in read mode\n");
exit(1);
}

printf("Reading file contents!\n\n");

while (ch= (fgetc(fp)) !=EOF){
printf("%c", ch);
}

fclose(fp);


fp=fopen("sample.txt","r");


if (fp==NULL)
{
printf("error reopening file in read mode\n");
exit(1);
}

fseek(fp, 0, SEEK_END);
long size= ftell(fp);

printf("\n\n File size: %d bytes\n", size);

rewind(fp);

return 0;
}

