#include<stdio.h>
int charcount(char file[])//�ַ�ͳ�ƺ���
{
	FILE *p = NULL;
	int charcount = 0;
	char c;
	fopen_s(&p,file, "r");
	if (p==NULL)
	{
		printf("�ļ���ʧ��\n");
		return -1;
	}
	printf("�ļ��򿪳ɹ�\n");
	c=fgetc(p);
	while (c != EOF)
	{
		c = fgetc(p);
		charcount++;
	}
	fclose(p);
	return charcount;
}
int linecount(char file[])//����ͳ�ƺ���
{
	FILE *p = NULL;
	char c;
	int linecount = 0;
	fopen_s(&p,file, "r");
	if (p == NULL)
	{
		printf("�ļ���ʧ��\n");
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
int wordcount(char file[])//������ͳ�ƺ���
{
	FILE *p = NULL;
	char c;
	int wordcount = 0;
	fopen_s(&p, file, "r");
	if (p == NULL)
	{
		printf("�ļ���ʧ��\n");
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
int spacecount(char file[])//aģʽ�µĿ���ͳ�ƺ���
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
		printf("�ļ���ʧ��\n");
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
int codecount(char file[])//aģʽ�µĴ�����ͳ�ƺ���
{
	FILE *p = NULL;
	char c;
	int codecount = 0;
	int count = 0;
	int flag = 0;
	fopen_s(&p, file, "r");
	if (p == NULL)
	{
		printf("�ļ���ʧ��\n");
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
int annocount(char file[])//aģʽ�µ�ע����ͳ�ƺ���
{
	FILE *p = NULL;
	char c;
	int annocount = 0;
	int count = 0;
	fopen_s(&p, file, "r");
	if (p == NULL)
	{
		printf("�ļ���ʧ��\n");
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
		printf("��ӭʹ�ã��ַ�ͳ�ƹ���\n");
		printf("��ѡ��Ҫʵ�ֵĹ��ܣ�\nc���ַ���ͳ��\nl������ͳ��\nw��������ͳ��\na�������ļ��п��С���������ע����ͳ��\n");
		printf("***********************************\n");
		printf("Ҫ������������q\n");
		scanf_s("%c", &order,1);
		switch(order-'a')
		{
			case 2:
			{
				printf("�������ļ����ƣ�\n");
				scanf_s("%s", file, 50);
				final = charcount(file);
				if (final == -1)
				{
					printf("�ļ�������\n");
					break;
				}
				printf("�ļ��ַ�����Ϊ��%d\n", final);
				break;
			}
			case 11:
			{
				printf("�������ļ����ƣ�\n");
				scanf_s("%s", file, 50);
				final = linecount(file);
				if (final == -1)
				{
					printf("�ļ�������\n");
					break;
				}
				printf("�ļ�������Ϊ��%d\n", final);
				break;
			}
			case 22:
			{
				printf("�������ļ����ƣ�\n");
				scanf_s("%s", file, 50);
				final = wordcount(file);
				if (final == -1)
				{
					printf("�ļ�������\n");
					break;
				}
				printf("�ļ���������Ϊ��%d\n", final);
				break;
			}
			case 0:
			{
				printf("�������ļ����ƣ�\n");
				scanf_s("%s", file, 50);
				final = spacecount(file);
				if (final == -1)
				{
					printf("�ļ�������\n");
					break;
				}
				printf("�ļ���������Ϊ��%d\n", final);
				final = codecount(file);
				if (final == -1)
				{
					printf("�ļ�������\n");
					break;
				}
				printf("�ļ�����������Ϊ��%d\n", final);
				final = annocount(file);
				if (final == -1)
				{
					printf("�ļ�������\n");
					break;
				}
				printf("�ļ�ע��������Ϊ��%d\n", final);
				break;
			}
			case 16:
			{
				printf("�������н�������лʹ��\n");
				return 0;
			}
		}
	}
}