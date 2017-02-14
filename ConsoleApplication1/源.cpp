#include <string>
#include <iostream>
using namespace std;
void maxsubstring(const string& str1, const string& str2)
{
	const int size1 = str1.size();
	const int size2 = str2.size();
	int count[100][100] = { 0 };	//�������
	for(int i=0;i<size1;++i)
		for (int j = 0; j < size2; ++j)
			if (str1[i] == str2[j])
				count[i][j] = 1;		//��ȵ�Ϊ1		
			else
				count[i][j] = 0;
	int max = count[0][0];
	for (int i = 1; i < size1; ++i)
		for (int j = 1; j < size2; ++j)
		{
			if (count[i - 1][j - 1] != 0 && count[i][j] != 0)
				count[i][j] += count[i - 1][j - 1];		//�������Ͻǵ�ֵ
			max = count[i][j] > max ? count[i][j] : max;
		}
			
	cout << max << endl;
	for (int i = 0; i < size1; ++i)
		for (int j = 0; j < size2; ++j)
			if (max == count[i][j])			//max���ڵ�Ϊ�ַ������һ��λ��
			{
				while (max--)
				{
					cout << str1[i-max];
					//cout << str2[j-max];
				}
			}				
}

int main()
{
	const string str1 = "nihaodajiahaocaishizhendehao";
	const string str2 = "yidiandoubuhaodajiahaocaishibuhao";
	maxsubstring(str1, str2);

	return 0;
}