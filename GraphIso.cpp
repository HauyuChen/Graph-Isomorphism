#include<iostream>
using namespace std;

/******************��������********************/
//ͬ�;���
void SimilarMatrix(int **p1,int **p2,int n)
{
	for(int i=0;i<n;i++)
	{
	
		for(int j=0;j<n;j++)
		{
		
			if(p1[i][j]>0)
			{
				p2[i][j]=1;
			}
			else
			{
				p2[i][j]=0;
			}
		}
	}

}

//������
void XORMatrix(int **p1,int **p2,int **p3,int n)
{
		for( int i=0;i<n;i++)
	{
	
		for(int j=0;j<n;j++)
		{
		
			if(i==j)
			{
				p3[i][j]=p1[i][i];
			}
			else
			{
				int sum1,sum12;
					sum1=0;
				for(int k=0;k<n;k++)
				{	
					
					if(p2[i][k]==p2[j][k])
					{
						sum12=0;
					}
					else
					{
						sum12=1;
					}
					
					sum1=sum1+(p1[i][k]+p1[j][k])*sum12;
				}

				p3[i][j]=sum1;
			}
		}
	}
}

//ͬ�����
void AORMatrix(int **p1,int **p2,int **p4,int n)
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
		
			if(i==j)
			{
				p4[i][j]=p1[i][i];
			}
			else
			{
				int sum1,sum12;
					sum1=0;
				for(int k=0;k<n;k++)
				{	
					if(p2[i][k]==p2[j][k])
					{
						sum12=1;
					}
					else
					{
						sum12=0;
					}
					sum1=sum1+(p1[i][k]+p1[j][k])*sum12;
				}
				p4[i][j]=sum1;
			}
		}
	}
}

//�������
void Display(int **p,char *s,int n)
{
	cout<<s;
	cout<<"\n";
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cout<<p[i][j];
			cout<<"\t";
		}
		cout<<"\n";
	}
}

//ð������
void BubbleSort(int mp[],int n)
{
	int t;
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n-1-i;j++)
		{
			if(mp[j]>mp[j+1])
			{
				t=mp[j];
				mp[j]=mp[j+1];
				mp[j+1]=t;
			}
		}
	}
}


//��������ת��
void Transf(int **p1,int **p13,int **p14,int **p2,int **p23,int **p24,int n)
{
	int *p77=new int[n];	//��ʱһά���飬���p13
	int *p88=new int[n];	//��ʱһά���飬���p23
	int *p33=new int[n];	//��ʱһά���飬���p1
	int *p44=new int[n];	//��ʱһά���飬���p14
	int *p55=new int[n];	//��ʱһά���飬���p2
	int *p66=new int[n];	//��ʱһά���飬���p24
	int *p99=new int[n];	//��ʱһά���飬���������滻

	int t;
	int tt;					//��ת�ж�
	int ttt=0;				//��ת�ж�

	//�����滻
	for( int i=0;i<n;i++)
	{
		//�и�ֵ������һ������p13
		for(int i77=0;i77<n;i77++)
		{
			p77[i77]=p13[i][i77];
		}
		//�и�ֵ������һ������p1
		for(int i33=0;i33<n;i33++)
		{
			p33[i33]=p1[i][i33];
		}
		//�и�ֵ������һ������
		for(int i44=0;i44<n;i44++)
		{
			p44[i44]=p14[i][i44];
		}
		//p77,p33,p44ð������
		BubbleSort(p77,n);
		BubbleSort(p33,n);
		BubbleSort(p44,n);

		//��ʼ�Ƚ�,p12��ÿһ����p23��ÿһ�н��бȽ�
		for(int y=i;y<n;y++)
		{
			tt=0;
			//�и�ֵ������һ������
			for(int i88=0;i88<n;i88++)
			{
				p88[i88]=p23[y][i88];
			}
			//�и�ֵ������һ������
			for(int i55=0;i55<n;i55++)
			{
				p55[i55]=p2[y][i55];
			}
			//�и�ֵ������һ������
			for(int i66=0;i66<n;i66++)
			{
				p66[i66]=p24[y][i66];
			}
			//p88,p55,p66ð������
			BubbleSort(p88,n);
			BubbleSort(p55,n);
			BubbleSort(p66,n);
			//��ʼ�Ƚ�
			for(int a=0;a<n;a++)
			{
				if(p77[a]==p88[a])
				{
					tt=a;
					if(a==n-1)	//������������,�ҵ�ƥ��
					{
						//�ڽӾ����Ӧλ�ñȽ�
						for(int b=0;b<n;b++)
						{
							if(p33[b]==p55[b])
							{
								continue;
							}
							else if(b<n-1)
							{
								cout<<"��ͬ��\n";
								return;
							}
						}
						//ͬ�����
						for(int c=0;c<n;c++)
						{
							if(p44[c]==p66[c])
							{
								continue;
							}
							else if(c<n-1)
							{
								cout<<"��ͬ��\n";
								return;
							}
						}
						ttt++;		//�ɹ�ƥ��һ��
						//����ת��p2
						for(int u1=0;u1<n;u1++)
						{
							t=p2[i][u1];
							p2[i][u1]=p2[y][u1];
							p2[y][u1]=t;
						}
						for(int u11=0;u11<n;u11++)
						{
							t=p2[u11][i];
							p2[u11][i]=p2[u11][y];
							p2[u11][y]=t;
						}
						//����ת��p23
						for(int u2=0;u2<n;u2++)
						{
							t=p23[i][u2];
							p23[i][u2]=p23[y][u2];
							p23[y][u2]=t;
						}
						for(int u22=0;u22<n;u22++)
						{
							t=p23[u22][i];
							p23[u22][i]=p23[u22][y];
							p23[u22][y]=t;
						}
						//����ת��p24
						for(int u3=0;u3<n;u3++)
						{
							t=p24[i][u3];
							p24[i][u3]=p24[y][u3];
							p24[y][u3]=t;
						}
						for(int u33=0;u33<n;u33++)
						{
							t=p24[u33][i];
							p24[u33][i]=p24[u33][y];
							p24[u33][y]=t;
						}
					break;	
					}
					else
					{
						continue;
					}
				}
				else if(y==n-1)		//һֱѭ�������δ�ҵ�ƥ��
				{
					cout<<"-------------------------------------\n";
					cout<<"ͼͬ���жϽ����";
					cout<<"��ͬ��\n";
					return;
				}
				else
				{
					break;
				}
			}

			//ƥ��������������滻
			if(tt==n-1)
			{
				if(ttt==n)
				{
					cout<<"-------------------------------------\n";
					cout<<"> ͼͬ���жϽ����";
					cout<<"ͬ��\n";
					cout<<"-------------------------------------\n";
					return;
				}
				else
				{
				  break;	//�ɹ�����ѭ���ж���һ��
				}
			}	
		}
	}
}

////������
int main()
{
	int Vertex_Num;		//ͼ�Ķ�����
	char *s;			//�ַ�����ʾ
	char Run_Flag='y';
	cout<<"******************************************************************\n";
	cout<<"**------------------------  ͼͬ���ж�  ------------------------**\n";
	cout<<"\n";
	while(Run_Flag=='y')
	{
		cout<<"Step 1��������ͼ�Ķ������\n";
		cin>>Vertex_Num;	//����ͼ�Ķ������
		if(cin.fail())
		{
			cout<<"**********�����������������*************\n";
			continue;
		}
		else
		{
			//����ͼһ�ڽӾ�������
			int **p1=new int*[Vertex_Num];
			for(int i1=0;i1<Vertex_Num;i1++)
			{
				p1[i1]=new int[Vertex_Num];
			}
			//����ͼһͬ�;���
			int **p12=new int*[Vertex_Num];
			for(i1=0;i1<Vertex_Num;i1++)
			{
				p12[i1]=new int[Vertex_Num];
			}
			//����ͼһ��������
			int **p13=new int*[Vertex_Num];
			for(i1=0;i1<Vertex_Num;i1++)
			{
				p13[i1]=new int[Vertex_Num];
			}
			//����ͼһ��ͬ�����
			int **p14=new int*[Vertex_Num];
			for(i1=0;i1<Vertex_Num;i1++)
			{
				p14[i1]=new int[Vertex_Num];
			}

			//����ͼ���ڽӾ�������	
			int **p2=new int*[Vertex_Num];
			for(int i2=0;i2<Vertex_Num;i2++)
			{
				p2[i2]=new int[Vertex_Num];
			}
			//����ͼ��ͬ�;���
			int **p22=new int*[Vertex_Num];
			for(i1=0;i1<Vertex_Num;i1++)
			{
				p22[i1]=new int[Vertex_Num];
			}
			//����ͼ����������
			int **p23=new int*[Vertex_Num];
			for(i1=0;i1<Vertex_Num;i1++)
			{
				p23[i1]=new int[Vertex_Num];
			}
			//����ͼ����ͬ�����
			int **p24=new int*[Vertex_Num];
			for(i1=0;i1<Vertex_Num;i1++)
			{
				p24[i1]=new int[Vertex_Num];
			}

			//���յ�һ���ڽӾ���Ķ�ά����
			cout<<"\nStep 2��������ͼһ���ڽӾ���\n";
			for(int i11=0;i11<Vertex_Num;i11++)
			{
				for(int j11=0;j11<Vertex_Num;j11++)
				{
					cin>>p1[i11][j11];
				}
			
			}
			//���յڶ����ڽӾ���Ķ�ά����
			cout<<"\nStep 3��������ͼ�����ڽӾ���\n";
			for(int i22=0;i22<Vertex_Num;i22++)
			{
				for(int j22=0;j22<Vertex_Num;j22++)
				{
					cin>>p2[i22][j22];
				}
			}

			//ͼһͬ�;���
			SimilarMatrix(p1,p12,Vertex_Num);
			//ͼһ������
			XORMatrix(p1,p12,p13,Vertex_Num);
			//ͼһͬ�����
			AORMatrix(p1,p12,p14,Vertex_Num);
			//ͼ��ͬ�;���
			SimilarMatrix(p2,p22,Vertex_Num);
			//ͼ��������
			XORMatrix(p2,p22,p23,Vertex_Num);
			//ͼ��ͬ�����
			AORMatrix(p2,p22,p24,Vertex_Num);

			cout<<"\n";
			Transf(p1,p13,p14,p2,p23,p24,Vertex_Num);	//���Ĵ��룬������ת��
			cout<<"\n";
			cout<<"**---------------------------  END  ----------------------------**\n";
			cout<<"******************************************************************\n";
			cout<<"\n>>>>>>>>>>> �Ƿ������(Y/N)";
			cin>>Run_Flag;
		}
	}
	return 0;
}
