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
		int home= h(K);                    // home ����K�Ļ���ַ
		int i=0;                           // 
		int pos = home;                    // ̽�����еĳ�ʼλ��

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






int getkey(Int* e) 
{ 
	return e->key();
}


char* getkey(char* e)
{ 
	return e;
}

// ������Ԫ��e���뵽ɢ�б� HT

template <class Key, class Elem, class KEComp, class EEComp>
bool hashdict<Key, Elem, KEComp, EEComp>::
	hashInsert(const Elem& e) {
		int home;                                      //home�洢��λ��      
		int i=0;     
		int pos = home= h(getkey(e));                 //��ʼ��̽������
		while(!EEComp::eq(EMPTY, HT[pos])){
			if (EEComp::eq(e, HT[pos])) 
				return false; // �����ظ�, ����
			i++;
			pos = (home + p(getkey(e), i)) % M;      // ������ǰ̽��

		}
		HT[pos] = e;                             // ����Ԫ��e
		return true;
}





int Intkey(Int& e) { return e.key(); }
char* charkey(char*& e) { return e; }

void main(int argc, char** argv) {
	hashdict<int, Int*, intIntsCompare, IntsIntsCompare> dict(100, new Int(-1));
	Int* val;

	dict.hashInsert(new Int(10));
	if (dict.hashSearch(10, val))
		cout << "����ֵ " << val << " ƥ��ؼ���10\n";
	else
		cout << "û�з��ֹؼ���Ϊ10��Ԫ��\n";

	hashdict<char*, char*, CCCompare, CCCompare> Strdict(100, "");
	char* str;

	Strdict.hashInsert("hello");
	if (Strdict.hashSearch("hello", str))
		cout << "����ֵ  " << str << " ƥ��ؼ��� hello\n";
	else
		cout << "û�з��ֹؼ���Ϊhello��Ԫ��\n";

	system("pause");
}