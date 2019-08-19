#include <stdio.h>

#define MAXLINE 1000


int getline(char line[],int lim);
void detab(char currLine[],char detaLine[],int li);

int main(){
	char currentLine[MAXLINE];
	char detabLine[MAXLINE];
	int len = 0;
	while((len = getline(currentLine,MAXLINE)) > 0){//当前输入的行有效
		detab(currentLine,detabLine,len);
		printf("%s",detabLine);
	}
	return 0;

}

int getline(char s[],int l) //获取键盘输入的字符串
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
	for(i = 0,j = 0;i < length -1,j < MAXLINE - 1;i ++){//将变量j的自增控制在循环内，不同的流程分支，自增的情况不一样
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