#ifndef POLY_H
#define POLY_H

class PolyInterface {
public:
	virtual void Counter(int64_t n) = 0;

	virtual int64_t getValue() = 0;
};

class PolyDerived : public PolyInterface {
public:
	PolyDerived() noexcept;

	PolyDerived (const PolyDerived& copy);

	PolyDerived& operator=(PolyDerived& copy);

	PolyDerived (PolyDerived&& move);

	PolyDerived& operator=(PolyDerived&& move);

	~PolyDerived();

	void Counter(int64_t n) override;

	int64_t getValue();

private:
	int64_t counter;
};

void PolyRunner(PolyInterface* poly);

#endif
