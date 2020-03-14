#include<stdio.h>
int charcount(char file[])//字符统计函数
{
	FILE *p = NULL;
	int charcount = 0;
	char c;
	fopen_s(&p,file, "r");
	if (p==NULL)
	{
		printf("文件打开失败\n");
		return -1;
	}
	printf("文件打开成功\n");
	c=fgetc(p);
	while (c != EOF)
	{
		c = fgetc(p);
		charcount++;
	}
	fclose(p);
	return charcount;
}
int linecount(char file[])//行数统计函数
{
	FILE *p = NULL;
	char c;
	int linecount = 0;
	fopen_s(&p,file, "r");
	if (p == NULL)
	{
		printf("文件打开失败\n");
		return -1;
	}
	c = fgetc(p);
	while (c != EOF)
	{
		if (c == '\n')
		{
			linecount++;
		}
		c = fgetc(p);
	}
	linecount++;
	fclose(p);
	return linecount;
}
int wordcount(char file[])//单词数统计函数
{
	FILE *p = NULL;
	char c;
	int wordcount = 0;
	fopen_s(&p, file, "r");
	if (p == NULL)
	{
		printf("文件打开失败\n");
		return -1;
	}
	c = fgetc(p);
	while (c != EOF)
	{
		if (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z' || c >= '0'&&c <= '9')
		{
			while (c >= 'a'&&c <= 'z' || c >= 'A'&&c <= 'Z' || c >= '0'&&c <= '9' || c == '_')
			{
				c = fgetc(p);
			}
			wordcount++;
			c = fgetc(p);
		}
		c = fgetc(p);
	}
	fclose(p);
	return wordcount;
}
int spacecount(char file[])//a模式下的空行统计函数
{
	FILE *p = NULL;
	char c;
	int spacecount = 0;
	int codecount = 0;
	int annocount = 0;
	int count = 0;
	fopen_s(&p, file, "r");
	if (p == NULL)
	{
		printf("文件打开失败\n");
		return -1;
	}
	c = fgetc(p);
	while (c != EOF)
	{
		if (c != ' ')
		{
			count++;
		}
		if (count<2&&c == '\n')
		{
			spacecount++;
		}
		if (c == '\n')
		{
			count = 0;
		}
		c = fgetc(p);
	}
	fclose(p);
	return spacecount;
}
int codecount(char file[])//a模式下的代码行统计函数
{
	FILE *p = NULL;
	char c;
	int codecount = 0;
	int count = 0;
	int flag = 0;
	fopen_s(&p, file, "r");
	if (p == NULL)
	{
		printf("文件打开失败\n");
		return -1;
	}
	c = fgetc(p);
	while (c != EOF)
	{
		if (c == '/')
		{
			c = fgetc(p);
			if (c == '/')
			{
				flag=1;
			}
		}
		if (c != ' ')
		{
			count++;
		}
		if (count>=2 && c == '\n'&&flag==0)
		{
			codecount++;
		}
		if (c == '\n')
		{
			count = 0;
			flag = 0;
		}
		c = fgetc(p);
	}
	fclose(p);
	return codecount;
}
int annocount(char file[])//a模式下的注释行统计函数
{
	FILE *p = NULL;
	char c;
	int annocount = 0;
	int count = 0;
	fopen_s(&p, file, "r");
	if (p == NULL)
	{
		printf("文件打开失败\n");
		return -1;
	}
	c = fgetc(p);
	while (c != EOF)
	{
		if (c == '/')
		{
			c = fgetc(p);
			if (c == '/')
			{
				annocount++;
			}
		}
		c = fgetc(p);
	}
	fclose(p);
	return annocount;
}
int main()
{
	int final;
	char order;
	char file[50];
	while (1)
	{
		printf("***********************************\n");
		printf("欢迎使用，字符统计工具\n");
		printf("请选择要实现的功能：\nc：字符数统计\nl：行数统计\nw：单词数统计\na：进行文件中空行、代码行与注释行统计\n");
		printf("***********************************\n");
		printf("要结束，请输入q\n");
		scanf_s("%c", &order,1);
		switch(order-'a')
		{
			case 2:
			{
				printf("请输入文件名称：\n");
				scanf_s("%s", file, 50);
				final = charcount(file);
				if (final == -1)
				{
					printf("文件名出错\n");
					break;
				}
				printf("文件字符总数为：%d\n", final);
				break;
			}
			case 11:
			{
				printf("请输入文件名称：\n");
				scanf_s("%s", file, 50);
				final = linecount(file);
				if (final == -1)
				{
					printf("文件名出错\n");
					break;
				}
				printf("文件行总数为：%d\n", final);
				break;
			}
			case 22:
			{
				printf("请输入文件名称：\n");
				scanf_s("%s", file, 50);
				final = wordcount(file);
				if (final == -1)
				{
					printf("文件名出错\n");
					break;
				}
				printf("文件单词总数为：%d\n", final);
				break;
			}
			case 0:
			{
				printf("请输入文件名称：\n");
				scanf_s("%s", file, 50);
				final = spacecount(file);
				if (final == -1)
				{
					printf("文件名出错\n");
					break;
				}
				printf("文件空行总数为：%d\n", final);
				final = codecount(file);
				if (final == -1)
				{
					printf("文件名出错\n");
					break;
				}
				printf("文件代码行总数为：%d\n", final);
				final = annocount(file);
				if (final == -1)
				{
					printf("文件名出错\n");
					break;
				}
				printf("文件注释行总数为：%d\n", final);
				break;
			}
			case 16:
			{
				printf("本次运行结束，感谢使用\n");
				return 0;
			}
		}
	}
}