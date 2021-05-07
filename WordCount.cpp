#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void wcexe(char *filename,char a[]){
	FILE *fp;
	char buffer[1000];
	char c;
	int bufferlen;
	int isLastBlank = 0;
	int charCount=0;
	int wordCount=0;

	int i;
 
	if((fp=fopen(filename,"rb"))==NULL){
		printf("文件不能打开\n");
		exit(0);
	}
	while(fgets(buffer,1000,fp)!=NULL){
		int a=0;
		bufferlen=strlen(buffer);
		for(i=0;i<bufferlen;i++){
			c=buffer[i];
			if(a==0){
				if(c==' ' || c=='\t'|| c==','){
					if(c!=','){
						charCount++;
					}
					continue;
				}else{
					charCount++;
					wordCount++;
					a=1;
				}
			}else{
				if(c==' ' || c=='\t'|| c==','){
					if(c!=','){
						charCount++;
					}
					if(isLastBlank==0 ){
						wordCount++;
					}
					isLastBlank=1;
				}else if(c!=','){
					charCount++;
					isLastBlank=0;
				}
			}
		}
	}
	fclose(fp);
	if(strcmp(a,"-c")==0){
			printf("字符数：%d\n",charCount);
	}
	if(strcmp(a,"-w")==0){
			printf("单词数：%d\n",wordCount);
	}
}
int main(int argc,char *argv[]){
	char *filename=argv[2];
	wcexe(filename,argv[1]);
}
