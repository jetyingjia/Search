#ifndef _Hash_dict_hpp_
#define _Hash_dict_hpp_


template <class Key, class Elem, class KEComp, class EEComp>
class hashdict 
{
private:
	Elem* HT;     // ɢ�б�
	int M;       // ɢ�б���С
	Elem TOMB;    //Ĺ��
	int currcnt;  // ����Ԫ����Ŀ
	Elem EMPTY;  // �ղ�
	int p(Key K, int i) const // ̽�麯��
	{ return linear(i); }
	int h(int x) const { return x % M; } // ɢ�к���
	int h(char* x) const { // �ַ���ɢ�к���
		int i, sum;
		for (sum=0, i=0; x[i] != '\0'; i++) sum += (int) x[i];
		return(sum % M);
	}
	int linear(int i) const {return i;}        //����̽��
	int square(int i) const {                  //����̽��
		if (i%2==0) return -(i*i/4);
		else       return (i+1)*(i+1)/4;
	}
	int rehash (Key K, int i) const;
	int division(int x ) const { return  x % M; }  //���෨
	int ELFhash ( char*  key )const {
		unsigned long h = 0;
		while(*key) { 
			h = ( ch << 4 ) + *key++;
			unsigned long g = h&0xF0000000L;
			if (g) h^= g >> 24;
			h  = ~g;
		}
		return h % M;
	}

public:
	hashdict(int sz, Elem e, Elem t){// ���캯��, e��������ղ�
		M=sz; EMPTY= e; TOMB=t;
		currcnt=0; HT=new Elem[sz];
		for(int i=0; i<M; i++) HT[i]= EMPTY; 
	}
	~hashdict() { delete HT; }
	bool hashInsert(const Elem&);
	bool hashSearch(const Key&, Elem&) const;
	Elem hashDelete(const Key& K);
	int size() { return currcnt; } // ɢ�б�������Ԫ����
};




#endif