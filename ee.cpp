#include<iostream>
#include<fstream>
#include<cstring>
#include<string>
using namespace std;

struct Word{      //����ṹ��
    int Count;//������
     Word() : Str(""), Count(0) {}  
    string Str; //�ַ���
    char *p;
};


void exchange(Word &word)  //���������ڽ������ʣ����򵥴ʣ�    
{  
    string tStr = word.Str;  
    int tCount = word.Count;  
    word.Str = Str;  
    word.Count = Count;  
    Str = tStr;  
    Count = tCount;  
}  

Words test[100];

void lwr(char x[])     //��дתСд
{   int k = 0;
    while (x[k] != '\0')
    {
        if (x[k] >= 'A'&&x[k] <= 'Z')
            x[k] = x[k] + 32;
        k++;
    }
}

int identify(char a[])    //�ж��Ƿ���ϵ��ʵĶ���
{   int m=(strlen(a)>=4)?1:0;
    int n=(a[0]>='a'&&a[0]<='z')?1:0;
    if(!m||!n)
        return 0;
    else
        while(a)
        {   for(int i=1;;i++)
           {  
               if(!(a[i]>='a'&&a[i]<='z')||!(a[i]>='0'&&a[i]<='9'))
                        return 0;
               else
                        return 1;
           }
        }
}

void SortWordDown(Word * words, int size)  //�Ե��ʳ���Ƶ�ʽ������е��ʣ�words �������飬size ��������
{  
    for(int i=0;i<size;i++)  
    {
        for(int j=0;j <size-1;j++)  
        { 
            if(words[j].Count<words[j+1].Count)  
            {  
                words[j].exchange(words[j+1]);  
            }  
        }  
    }  
}  

int counting(char b[],int num)    //�Գ��ִ�������
{   for(int j=0;j<num;j++)
    {

        if(!strcmp(b,test[j].p))
             test[j].count++;
        else
            return 0;
    }
}


int main()
{   char c[200];
    ifstream fin("D:/A_Tale_of_Two_Cities.txt");   //���ĵ��л�ȡ�ַ���
    for(int f=0;;f++)
        fin>>c[f];
    fin.close();
    cin.get();
    lwr(c);
    const char *delim = ",����.''!?";      //�ָ��ַ���
    char *q;
    int n=0;
    q = strtok(c, delim);
    SortWordDown(words, wCount);  
    while (q)
    {
        if (identify(q))
        {
            
                strcpy(test[n].p,q);
                n++;
            
        }

       
       q=strtok(NULL,delim);
    }
	cout<<"����ͳ�Ƴ���Ƶ����ָ�����ʣ�\n";    
	char r;
	cin>>r;
	int t=0;
	while(!strcmp(test[n].p,r))     //�ҵ�ָ������
	{   
		t++;
	}
	cout<< test[n].p << ":" << test[n].count << '\n';    //���ָ�����ʵ�ͳ�ƽ��
    return 0;
}