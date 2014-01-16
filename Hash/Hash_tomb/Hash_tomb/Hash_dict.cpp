#include <iostream>
#include <stdlib.h>
#include <string.h>
#include "Int.h"
#include "Compare.h"

#include "Hash_dict.h"
using namespace std;


// �����ؼ���ֵΪk�ļ�¼���ٶ�ÿ���ؼ����̽��������
//������һ�����ǿյģ��������Ǿͻ����һ������ѭ���С�
template <class Key, class Elem, class KEComp, class EEComp>
bool hashdict<Key, Elem, KEComp, EEComp>::
	hashSearch(const Key& K, Elem& e) const {
		int home= h(K);      // home ����K�Ļ���ַ
		int i=0;    
		int pos = home;     // ̽�����еĳ�ʼλ��
		while(!EEComp::eq(EMPTY, HT[pos])){
			if (KEComp::eq(K, HT[pos])) {  // ����Ŀ��
				e = HT[pos];
				return true;
			}
			i++;
			pos = (home + p(K, i)) % M;
		}
		return false;    
}







// ������Ԫ��e���뵽ɢ�б� HT
template <class Key, class Elem, class KEComp, class EEComp>
bool hashdict<Key, Elem, KEComp, EEComp>::hashInsert(const Elem &e)
{
	int home= h(getkey(e));        // home��¼��λ��
	int i=0;    
	int pos = home;               // ̽�����еĳ�ʼλ��
	while(!EEComp::eq(EMPTY, HT[pos])
		&& !EEComp::eq(TOMB, HT[pos])){
			if (KEComp::eq(getkey(e), HT[pos]))
				return false;           //�������ظ��ؼ���
			i++;
			pos = (home + p(getkey(e), i)) % M;
	}
	HT[pos]=e;                    //����e
	return true;
}


// ɾ������
template <class Key, class Elem, class KEComp, class EEComp>
Elem hashdict<Key,Elem,KEComp,EEComp>::hashDelete(const Key& K)
{
	int home= h(K);         // home��¼��λ��
	int i=0;    
	int pos = home;        // ̽�����еĳ�ʼλ��
	while(!EEComp::eq(EMPTY, HT[pos])){
		if (KEComp::eq(K, HT[pos])){
			temp = HT[pos];
			HT[pos] = TOMB; //����Ĺ��
			return temp;    //����Ŀ��
		}
		i++;
		pos = (home + p(K, i)) % M;
	}
	return EMPTY; 
}




int getkey(Int* e)
{
	return e->key();
}


char* getkey(char* e)
{ 
	return e;
}



int Intkey(Int& e) 
{
	return e.key();
}


char* charkey(char*& e) 
{
	return e;
}

void main(int argc, char** argv) {
	hashdict<int, Int*, intIntsCompare, IntsIntsCompare> dict(100, new Int(-1),new Int(-2));
	Int* val;

	dict.hashInsert(new Int(10));
	if (dict.hashSearch(10, val))
		cout << "����ֵ " << val << " ƥ��ؼ���10\n";
	else
		cout << "û�з���ƥ��ؼ���10��Ԫ��\n";


	system("pause");
}