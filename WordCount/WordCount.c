#include <stdio.h>
#include <stdlib.h>
#include <string.h>


//ͳ�Ƶ���
int CountWords(char *file) {
	int SumWord = 0;
	FILE* fp;
	int n = 0;
	char temp;
	fp = fopen(file, "r");
	if (fp == NULL) 
		printf("�ļ���ȡ����");
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

//ͳ���ַ�
int CountChars(char *file) {
	int SumChar = 0;
	FILE* fp;
	char temp;
	fp = fopen(file, "r");
	if (fp == NULL)
		printf("�ļ���ȡ����");
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
		printf("�ļ�%s���ַ���Ϊ��%d", argv[2], CountChars(argv[2]));
	}
	else if (!strcmp(argv[1], "-w")) {
		printf("�ļ�%s�ĵ�����Ϊ��%d", argv[2], CountWords(argv[2]));
	}
	else {
		printf("�������");
	}
	return 0;
}