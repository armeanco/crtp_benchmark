#include "../crtp_h/crtp_h.h"

template<>
void Base<Derived>::Counter(int64_t n) {
	static_cast<Derived*>(this)->Counter(n);
}
template<>
int64_t Base<Derived>::getValue() {
	return static_cast<Derived*>(this)->getValue();
}

Derived::Derived() noexcept : counter(0) {

}

Derived::~Derived() {

}

void Derived::Counter(int64_t n) {
	counter += n;
}

int64_t Derived::getValue() {
	return counter;
}

template<>
void Runner(Base<Derived>* base) {
	for(unsigned int i = 0; i < MAX; ++i) {
		for(unsigned int j = 0; j < i; ++j) {
			base->Counter(j);
		}
	}
}
