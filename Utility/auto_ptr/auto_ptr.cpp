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

			//拷贝构造 template类型的拷贝构造用于父子类指针自动类型转换
			auto_ptr (auto_ptr& rhs) throw() : ap(rhs.release()) {}
			template <typename U>
			auto_ptr (auto_ptr<U>& rhs) throw() : ap(rhs.release()) {}

			//拷贝赋值 template类型的拷贝构造用于父子类指针自动类型转换
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

			//转移所有权（指针）
			T* release() throw() {
				T* tmp(ap);
				ap = 0;
				return tmp;
			}

			//获得一个新的所有权（指针）
			void reset (T* ptr = 0) throw() {
				if(ap != ptr) {
					delete ap;
					ap = ptr;
				}
			}

			//当auto_ptr作为函数参数或返回值（右值）时，转换为左值使用，保证拷贝构造不会转移所有权
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
**  auto_ptr需要用到auto_ptr_ref的原因：

double dval = 3.14;
const int &ri = dval;
编译器会把这些代码转换成如以下形式的编码：
int temp = dval;          // create temporary int from the double
const int &ri = temp;   // bind ri to that temporary
如果 ri 不是 const，那么可以给 ri 赋一新值。这样做不会修改 dval，而是修改了 temp。
期望对 ri 的赋值会修改 dval 的程序员会发现 dval 并没有被修改。
仅允许 const 引用绑定到需要临时使用的值完全避免了这个问题，因为 const 引用是只读的。

非const引用只能绑定到与该引用同类型的对象
const引用则可以绑定到不同但相关类型的对象或绑定到右值
**
*/