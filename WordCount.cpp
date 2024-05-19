#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	
    if (argc != 3) {
        printf("Usage: %s <-c or -w> <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[2], "r");
    
    if (file == NULL) {
        printf("Error opening file.\n"); //���ļ�ʧ�� 
        return 1;
    }

    int charCount = 0; // �ַ����� 
    int wordCount = 0; // �������� 
    int inWord = 0; // ����ǲ�����ͬһ��������

    int ch;
    while ((ch = fgetc(file)) != EOF) {
    	
        charCount++; // ͳ���ַ� 

        // ����Ƿ��ǿո�򶺺� 
        if (isspace(ch) ||',' == ch) {
            inWord = 0; // ����ͬһ�����ʵ��ַ� 
        } 
		else {
            // ��ͬһ�����ʵ��ַ� 
            if (!inWord) {
                wordCount++;// ͳ�Ƶ������� 
                inWord = 1;
            }
        }
    }

    fclose(file);
    
    if(argv[1][1] == 'c') printf("�ַ���: %d\n", charCount);
    else if (argv[1][1] == 'w') printf("������: %d\n", wordCount);
    else printf("����ָ�� -%c\n"); 

    return 0;
}

