namespace std {
	template <typename Y>
	struct auto_ptr_ref {
		Y* yp;
		auto_ptr_ref (Y* rhs) : yp(rhs) {}
	};

	template <typename T>
	class auto_ptr {
		private:
			T* ap;

		public:
			typedef T element_type;
		
		    explicit auto_ptr (T* ptr = 0) throw() : ap(ptr) {}

			//�������� template���͵Ŀ����������ڸ�����ָ���Զ�����ת��
			auto_ptr (auto_ptr& rhs) throw() : ap(rhs.release()) {}
			template <typename U>
			auto_ptr (auto_ptr<U>& rhs) throw() : ap(rhs.release()) {}

			//������ֵ template���͵Ŀ����������ڸ�����ָ���Զ�����ת��
			auto_ptr& operator= (auto_ptr& rhs) throw() {
				reset(rhs.release());
				return *this;
			}
			template <typename U>
			auto_ptr& operator= (auto_ptr<U>& rhs) throw() {
				reset(rhs.release());
				return *this;
			}

			~auto_ptr() throw() {
				delete ap;
			}

			T* get() const throw() {
				return ap;
			}

			T& operator*() const throw() {
				return *ap;
			}

			T* operator-> () const throw() {
				return ap;
			}

			//ת������Ȩ��ָ�룩
			T* release() throw() {
				T* tmp(ap);
				ap = 0;
				return tmp;
			}

			//���һ���µ�����Ȩ��ָ�룩
			void reset (T* ptr = 0) throw() {
				if(ap != ptr) {
					delete ap;
					ap = ptr;
				}
			}

			//��auto_ptr��Ϊ���������򷵻�ֵ����ֵ��ʱ��ת��Ϊ��ֵʹ�ã���֤�������첻��ת������Ȩ
			auto_ptr (auto_ptr_ref<T> rhs) throw() : ap(rhs.ap) {}

			auto_ptr& operator= (auto_ptr_ref<T> rhs) throw() {
				reset(rhs.yp);
				return *this;
			}

			template<typename Y>
			operator auto_ptr_ref<Y>() throw() {
				return auto_ptr_ref<Y>(release());
			}

			template<typename Y>
			operator auto_ptr<Y>() throw() {
				return auto_ptr<Y>(release());
			}
	};
}

/*
**  auto_ptr��Ҫ�õ�auto_ptr_ref��ԭ��

double dval = 3.14;
const int &ri = dval;
�����������Щ����ת������������ʽ�ı��룺
int temp = dval;          // create temporary int from the double
const int &ri = temp;   // bind ri to that temporary
��� ri ���� const����ô���Ը� ri ��һ��ֵ�������������޸� dval�������޸��� temp��
������ ri �ĸ�ֵ���޸� dval �ĳ���Ա�ᷢ�� dval ��û�б��޸ġ�
������ const ���ð󶨵���Ҫ��ʱʹ�õ�ֵ��ȫ������������⣬��Ϊ const ������ֻ���ġ�

��const����ֻ�ܰ󶨵��������ͬ���͵Ķ���
const��������԰󶨵���ͬ��������͵Ķ����󶨵���ֵ
**
*/