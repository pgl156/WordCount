#include <stdio.h>
#include <ctype.h>

int main(int argc, char* argv[]) {
	
    if (argc != 3) {
        printf("Usage: %s <-c or -w> <filename>\n", argv[0]);
        return 1;
    }

    FILE* file = fopen(argv[2], "r");
    
    if (file == NULL) {
        printf("Error opening file.\n"); //打开文件失败 
        return 1;
    }

    int charCount = 0; // 字符数量 
    int wordCount = 0; // 单词数量 
    int inWord = 0; // 标记是不是在同一个单词中

    int ch;
    while ((ch = fgetc(file)) != EOF) {
    	
        charCount++; // 统计字符 

        // 检查是否是空格或逗号 
        if (isspace(ch) ||',' == ch) {
            inWord = 0; // 不是同一个单词的字符 
        } 
		else {
            // 是同一个单词的字符 
            if (!inWord) {
                wordCount++;// 统计单词数量 
                inWord = 1;
            }
        }
    }

    fclose(file);
    
    if(argv[1][1] == 'c') printf("字符数: %d\n", charCount);
    else if (argv[1][1] == 'w') printf("单词数: %d\n", wordCount);
    else printf("错误指令 -%c\n"); 

    return 0;
}

