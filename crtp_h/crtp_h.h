#include <iostream>
#include <cstdint>

#ifndef CRTP_H
#define CRTP_H
#define MAX 100000

template<typename Derived>
class Base {
public:
	void Counter(int64_t n);

	int64_t getValue();
};

class Derived : public Base<Derived> {
public:
	Derived() noexcept;

	Derived (const Derived& derived) = default;

	Derived& operator=(Derived& derived) = default;

	Derived (Derived&& derived) = default;

	Derived& operator=(Derived&& derived) = default;

	~Derived();

	void Counter(int64_t);

	int64_t getValue();
private:
	int64_t counter;
};

template<typename T>
void Runner(Base<T>* base);

#endif
