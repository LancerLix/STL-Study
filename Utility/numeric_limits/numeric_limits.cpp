namespace std {

	//通用性的template,为所有型别提供缺省极值
	template <class T>
	class numeric_limits {
		
		public:
			//标记该通用性template非特化，对型别T而言，无所谓极值存在
			static const bool is_specialized = false;	
			
			/*
				//所有型别共同接口
				...
				...
			*/
	};
	
	//各具体型别的极值，由特化版本提供
	template<> class numeric_limits<int> {
		
		public:
			//对int版的numeric_limits特化，有极值存在
			static const bool is_specialized = true;
			
			static int min() throw() {
				return -2147483648;
			}
			
			static int max() throw() {
				return 2147483647;
			}
			
			static const int digits = 31;
			
			/*
				//int特化版本其他成员
				...
				...
			*/
	};
	
	//float特化的numeric_limits的一个略完整实现
	template<> class numeric_limits<float> {
		
		public:
			//对float版的numeric_limits特化，有极值存在
			static const bool is_specialized = true;
			
			inline static float min() throw() {
				return 1.175494351E-38F;	
			}
			
			inline static float max() throw() {
				return 3.402823466E+38F;
			}
			
			static const int digits = 24;
			static const int digits10 = 6;
			
			static const bool is_signed = true;
			static const bool is_integer = false;
			static const bool is_exact = false;
			static const bool is_bounded = true;
			static const bool is_modulo = false;
			static const bool is_iec559 = true;
			
			static const int radix = 2;
			
			inline static float epsilon() throw() {
				return 1.19209290E-07F;
			}
			
			inline static float round_error() throw() {
				return 0.5F;
			}
			
			static const int min_exponent = -125;
			static const int max_exponent = +128;
			static const int min_exponent10 = -37;
			static const int max_exponent10 = +38;
			
			static const bool has_denorm_loss = false;
			inline static float denorm_min() throw() {
				return min();
			}
			
			static const bool traps = true;
			static const bool tinyness_before = true;
	};
	
}
