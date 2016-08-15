#define _CRT_SECURE_NO_WARNINGS 
#include<vector>
#include<iostream>
using namespace std;
template<class T>
class BitMap
{
public:
	BitMap()//�޲����Ŀ�������
		:_size(0)
	{}
	BitMap(size_t size)//�и����Ŀ�������
		:_size(0)
	{
		_array.resize((size>>5)+1);//һ������4���ֽ�32��������λ  ��������ǿ����˶��ٸ��ֽ�
	}
	void Set(size_t num)
	{
		//�ѵ�0�ֽ�1λ����Ϊ1
		size_t index = num >> 5;//�ֽ�λ��
		size_t n = num % 32;
		//_array[0]��ʾ0��31��_array[index]=00000000 00000000 00000000 00000000
		_array[index] |= (1 << n);//д��1��õ�00000000 00000000 000000000 000000010
	}
	void Reset(size_t num)
	{
		size_t index = num >> 5;
		size_t n = num % 32;
		_array[index] &= ~(1 << n);
	}
	bool Test(size_t num)
	{
		size_t index = num >> 5;
		size_t n = num % 32;
		return _array[index] & (1 << n);
	}
public:
	vector<size_t> _array;
	size_t _size;
};
void Test()
{
	BitMap<size_t> bm(66);
	bm.Set(1);
	bm.Set(34);
	bm.Set(4);
	cout << "1?" << bm.Test(1) << endl;
	cout << "34?" << bm.Test(34) << endl;
	cout << "4?" << bm.Test(4) << endl;

	bm.Reset(34);
	cout << "1?" << bm.Test(1)<<endl;
	cout << "34?" << bm.Test(34) << endl;
	cout << "4?" << bm.Test(4) << endl;

}
int main()
{
	Test();
	system("pause");
	return 0;
}