#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//统计单词
int CountWords(char *file) {
	int SumWord = 0;
	FILE* fp;
	int n = 0;
	char temp;
	fp = fopen(file, "r");
	if (fp == NULL) 
		printf("文件读取错误");
	else {
		temp = fgetc(fp);
		while (temp != EOF) {

			do {
				temp = fgetc(fp);
			} while ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') && temp != ',' && temp != ' ');
			SumWord++;
			temp = fgetc(fp);
		}
	}
	return SumWord;
}

//统计字符
int CountChars(char *file) {
	int SumChar = 0;
	FILE* fp;
	char temp;
	fp = fopen(file, "r");
	if (fp == NULL)
		printf("文件读取错误");
	else {
		temp = fgetc(fp);
		while (temp != EOF) {
			SumChar++;
			temp = fgetc(fp);
		}
	return SumChar;
	}
}

int main(int argc, char *argv[]) {
	if (!strcmp(argv[1], "-c")) {
		printf("文件%s的字符数为：%d", argv[2], CountChars(argv[2]));
	}
	else if (!strcmp(argv[1], "-w")) {
		printf("文件%s的单词数为：%d", argv[2], CountWords(argv[2]));
	}
	else {
		printf("输入错误");
	}
	return 0;
}