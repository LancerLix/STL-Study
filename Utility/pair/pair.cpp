namespace std {
	template<typename T1,typename T2>
	struct pair
	{
		typedef T1 first_type;
		typedef T2 second_type;

		T1 first;
		T2 second;

		pair () : first(T1()), second(T2()) {}

		pair (const T1& a , const T2& b) : first(a), second(b) {}

		//ģ�����͵Ĺ��캯�������ڸ��ɱ�����Ĭ����ʽ���ɵĶ�Ӧ�Ĺ��캯�����˴���copy���죬����������Ĭ������һ��copy���죩
		//�˴�ʹ��ģ�濼�ǵ�������̿�����Ҫ��ʽ����ת��
		template<typename U,typename V>
		pair (const pair<U,V>& copy) : first(copy.first), second(copy.second){}
		
	};

	template<typename T1,typename T2>
	pair<T1,T2>& make_pair (const T1& a, const T2& b) {
		return pair<T1,T2>(a,b);
	}

	template<typename T1,typename T2>
	bool operator == (const pair<T1,T2>& a, const pair<T1,T2>& b) {
		return (a.first == b.first) && (a.second == b.second);
	}
		
	template<typename T1,typename T2>
	bool operator != (const pair<T1,T2>& a, const pair<T1,T2>& b) {
		return !(a == b);
	}

	template<typename T1,typename T2>
	bool operator < (const pair<T1,T2>& a, const pair<T1,T2>& b) {
		return (a.first < b.fisrt) || (a.first == b.first) && (a.second < b.second);
	}

	template<typename T1,typename T2>
	bool operator > (const pair<T1,T2>& a, const pair<T1,T2>& b) {
		return (a.first > b.fisrt) || (a.first == b.first) && (a.second > b.second);
	}

	template<typename T1,typename T2>
	bool operator <= (const pair<T1,T2>& a, const pair<T1,T2>& b) {
		return !(a > b);
	}

	template<typename T1,typename T2>
	bool operator >= (const pair<T1,T2>& a, const pair<T1,T2>& b) {
		return !(a < b);
	}

}
