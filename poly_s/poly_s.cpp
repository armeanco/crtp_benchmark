#include "../poly_h/poly_h.h"

PolyDerived::PolyDerived() noexcept : counter(0) {

}

PolyDerived::~PolyDerived() {

}

void PolyDerived::Counter(int64_t n) {
	counter += n;
}

int64_t PolyDerived::getValue() {
	return counter;
}

void PolyRunner(PolyInterface* poly) {
	for(unsigned int i = 0; i < MAX; ++i) {
		for(unsigned int j = 0; j < i; ++j) {
			poly->Counter(j);
		}
	}
}
