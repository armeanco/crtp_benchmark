#include <chrono>
#include "../crtp_s/crtp_s.cpp"
#include "../poly_s/poly_s.cpp"

using namespace std;
using namespace std::chrono;

void CRTP(Base<Derived> *obj) {
	
	time_point<high_resolution_clock> start_point, end_point;

	start_point = high_resolution_clock::now();

	Runner(obj);

	end_point = high_resolution_clock::now();

	auto start = time_point_cast<microseconds>(start_point).time_since_epoch().count();

	auto end = time_point_cast<microseconds>(end_point).time_since_epoch().count();

	cout << "Time taken = " << (end-start) << " microseconds" << '\n';
}

void Poly(PolyInterface* obj) {

	time_point<high_resolution_clock> start_point, end_point;

	start_point = high_resolution_clock::now();

	PolyRunner(obj);

	end_point = high_resolution_clock::now();

	auto start = time_point_cast<microseconds>(start_point).time_since_epoch().count();

	auto end = time_point_cast<microseconds>(end_point).time_since_epoch().count();

	cout << "Time taken = " << (end-start) << " microseconds" << '\n';
}

int main(int argc, char** argv) {
	
	Base<Derived>* base = new Base<Derived>();
	PolyInterface* poly = new PolyDerived();
	CRTP(base);
	Poly(poly);
	delete base;
	delete poly;

	return EXIT_SUCCESS;
}
