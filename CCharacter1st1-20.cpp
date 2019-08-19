#include <stdio.h>

#define MAXLINE 1000


int getline(char line[],int lim);
void detab(char currLine[],char detaLine[],int li);

int main(){
	char currentLine[MAXLINE];
	char detabLine[MAXLINE];
	int len = 0;
	while((len = getline(currentLine,MAXLINE)) > 0){//��ǰ���������Ч
		detab(currentLine,detabLine,len);
		printf("%s",detabLine);
	}
	return 0;

}

int getline(char s[],int l) //��ȡ����������ַ���
{ 
	int c, i; 
	for (i=0; i < l-1 && (c=getchar())!=EOF && c!='\n'; ++i) 
		s[i] = c; 
	if (c == '\n') { 
		s[i] = c; 
		++i; 
	} 
	s[i] = '\0'; 
	return i; 
} 

void detab(char cuLine[],char deLine[],int length){
	int i,j;
	for(i = 0,j = 0;i < length -1,j < MAXLINE - 1;i ++){//������j������������ѭ���ڣ���ͬ�����̷�֧�������������һ��
		if(cuLine[i] == '\t'){
			int n = 3;
			while(n > 0){
				deLine[j++] = ' ';
				n --;
			}
		}else{
			deLine[j++] = cuLine[i];
		}
	}
	deLine[j] = '\0';
}