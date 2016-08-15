#define _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>
#define Max_size 100
typedef int Datatype;
typedef struct seqlist
{
	Datatype array[Max_size];//最大容纳量
	size_t size;//实际个数
}seqlist;
 void Initseqlist(seqlist*pseq)
{
	 memset(pseq->array, 0, sizeof(Datatype)*Max_size);
	 pseq->size = 0;
}
 void Printfseqlist(seqlist*pseq)
 {
	 assert(pseq);
	 size_t i;
	 for (i = 0; i < pseq->size; i++)
	 {
		 printf("%d", pseq->array[i]);
	 }
	 printf("\n");
 }
 void Pushback(seqlist*pseq, Datatype x)
 {
	 assert(pseq);
	 if (pseq->size == Max_size)
	 {
		 printf("顺序表已满，无法插入！");
		 return 0;
	 }
	 else
		 pseq->array[pseq->size++] = x;
 }
 void Popback(seqlist*pseq, Datatype x)
 {
	 assert(pseq);
	 if (pseq->size == 0)
	 {
		 printf("顺序表为空！");
		 return 0;
	 }
	 else
		 pseq->size--;
 }
 void Pushfront(seqlist*pseq, Datatype x)
 {
	 Datatype begin;
	 begin = pseq->size - 1;
	 assert(pseq);
	 if (pseq->size == Max_size)
		 printf("顺序表已满无法插入！");
	 else
	 for (begin = pseq->size - 1; begin >= 0; begin--)
	 {
		 pseq->array[begin+1] = pseq->array[begin];
	 }
	 pseq->array[0] = x;
	 ++pseq->size;
 }
 void Popfront(seqlist*pseq)
 {
	 int i=0;
	 assert(pseq);
	 if (pseq->size == 0)
	 {
		 printf("顺序表为空！");
		 return 0;
	 }
	 else
	 for (; i <pseq->size; i++)
	 {
		 pseq->array[i] = pseq->array[i+1];
	 }
	 pseq->size--;
 }
 void Insertseqlist(seqlist*pseq, Datatype pos, Datatype x)
 {
	 int i = pseq->size-1;
	 assert(pseq);
	 if (pos>pseq->size)
		 printf("插入位置不合法！");
	 if (pseq->size == Max_size)
	 {
		 printf("顺序表已满！");
		 return 0;
	 }
	 else
	 for (; i >= pos; i--)
	 {
		 pseq->array[i+1] = pseq->array[i];
	 }
	 pseq->array[pos] = x;
	 pseq->size++;
 }
 int Find(seqlist* s, Datatype x)
 {
	 int i = 0;
	 assert(s);

	 for (i = 0; i < s->size; ++i)
	 {
		 if (s->array[i] == x)
		 {
			 return i;
		 }
	 }

	 return  -1;
 }
 void Erase(seqlist*pseq, size_t pos)
 {
	 assert(pseq);
	 Datatype cur=pos;
	 if (pos > pseq->size)
	 {
		 printf("删除位置不合法！");
	 }
	 else
	 for (; cur <pseq->size -1; cur++)
	 {
		 pseq->array[cur] = pseq->array[cur+1];
	 }
	 pseq->size--;
 }
 void Remove(seqlist*pseq, Datatype x)
 {
	 assert(pseq);
	 int  i = 0;
	 for (i = 0; i < pseq->size; i++)
	 {
		 if (pseq->array[i] == x)
		 {
			 int j = i;
			 for (; j < pseq->size; j++)
			 {
				 pseq->array[j] = pseq->array[j + 1];
			 }
			 break;
		 }
	 }
	 pseq->size--;
 }
 /*void Removeall(seqlist*pseq, Datatype x)
 {
	 assert(pseq);
	 int i=0;
	 int count=0;
	 for (; i < pseq->size; i++)
	 {
		 int count = 0;

		 if (pseq->array[i] == x)
		 {
			 count++;
			 int j = i;
			 for (; j < pseq->size; j++)
			 {
				 pseq->array[j] = pseq->array[j + 1];
			 }
		 }
		 pseq->size -= count;
			
	 }
	 pseq->size -= count;
 }*/
 void Removeall(seqlist*pseq, Datatype x)
 {
	 assert(pseq);
	 int count = 0;
	 int firstindx=0, secondindx=0;
	 while (secondindx < pseq->size)
	 {
		 if (pseq->array[secondindx] != x)
		 {
			 pseq->array[firstindx] = pseq->array[secondindx];
			 firstindx++;
		 }
		 else
		 {
			 count++;
		 }
		 secondindx++;
	 }
	 pseq->size -= count;
 }
 void Bubsort(seqlist*pseq)
 {
	 int i ;
	 int j,temp;
	 assert(pseq);
	 for (i = 1; i < pseq->size; i++)
	 {
		 for (j = 0; j < pseq->size - i; j++)
		 {
			 if (pseq->array[j]>pseq->array[j + 1])
			 {
				 temp = pseq->array[j];
				 pseq->array[j] = pseq->array[j + 1];
				 pseq->array[j + 1] = temp;
			 }
				
		 }
	 }
 }
 void Selectsort(seqlist*pseq)
 {
	 assert(pseq);
	 int i, j,k;
	 int temp;
	 for (i = 0; i < pseq->size; i++)
	 {
		 int k = i;
		 for (j = i+1; j < pseq->size; j++)
		 {
			 if (pseq->array[i]>pseq->array[j])
				 k = j;
		 }
		 temp = pseq->array[k];
		 pseq->array[k] = pseq->array[i];
		 pseq->array[i] = temp;
	 }
 }
 int Binarysearch(seqlist*pseq, Datatype x)
 {
	 int left = 0;
	 int right = pseq->size;
	 while (left <= right)
	 {
		 int mid = (left + right) / 2;

		 if (pseq->array[mid] < x)
		 {
			 left = mid + 1;
		 }
		 else if (pseq->array[mid]>x)
		 {
			 right = mid - 1;
		 }
		 else
		 {
			 return mid;
		 }
	 }
	 return -1;
 }
 void Test1()
 {
	 seqlist s;
	 Initseqlist(&s);
	 Pushback(&s, 1);
	 Pushback(&s, 2);
	 Pushback(&s, 3);
	 Pushback(&s, 4);
	 Pushback(&s, 5);
	 Pushback(&s, 6);
	 //Popback(&s, 5);
	// Popback(&s, 6);
	// Pushfront(&s, 0);
	 Popfront(&s, 1);
	/* Insertseqlist(&s, 2, 5);*/
	 // Find(&s, 2);
	 //Erase(&s, 2);
	 //Remove(&s, 2);
	 //Removeall(&s, 2);
	  // Bubsort(&s);
	// Selectsort(&s);
	 //Binarysearch(&s, 3);
	 Printfseqlist(&s);
 }
 
int main()
{
	Test1();
	system("pause");
	return 0;
}