// 15-12.cpp : �������̨Ӧ�ó������ڵ㡣
//�ڱ������У�ʹ�õ���ջ���ˣ�unwinding the stack����������try��û��ֱ�ӵ��������쳣�ĺ��������ǵ����ˣ��������쳣�ĺ��������е��õĺ�����
//��������̽��������쳣�ĺ�����������try��ʹ������ĺ�����
//ջ���ˣ��������ڳ����쳣����ֹ������Ҳ���ͷ�ջ�е��ڴ棬���������ͷ�ջ�ĵ�һ�����ص�ַ��ֹͣ�����Ǽ����ͷ�ջ��
//		  ֱ���ҵ�һ��λ��try���еķ��ص�ַ����󣬿���Ȩ��ת����β���쳣������򣨼�catch�飩�������Ǻ������ú�ĵ�һ�����

/*return��throw������
		�ٺ���fun�����е�return��佫����Ȩ���ظ�����fun�����ĺ���
		��throw��佫����Ȩ���Ϸ��ص���һ�������ĺ����������ܹ�������Ӧ�쳣��try-catch��ϡ�
*/


#include "stdafx.h"
#include <iostream>
#include "exc_mean.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	double x, y, z;
	{
		demo d1("found in block in main()");
		cout << "Enter two numbers:";
		while (cin >> x >> y)
		{
			try
			{
				z = means(x, y);
				cout << "The mean of " << x << " and " << y << " is " << z << endl;
				cout << "Enter next pair: ";
			}
			catch (bad_hmean & bg)
			{
				bg.mesg();
				cout << "Try again.\n";
				continue;
			}
			catch (bad_gmean & bg)
			{
				cout << bg.mesg();
				cout << "Values used : " << bg.v1 << ", " << bg.v2 << endl;
				cout << "Sorry,you don't get to play any more.\n";
				break;
			}
		}
		d1.show();
	}
	getchar();
	getchar();
    return 0;
}

