#include <iostream>
#include <thread>

int x; //wartość globalna

void Task_0(void)
{
	auto loc{ x }; //lokalna wartość do której wpisana zostanie globalna wartość x
	// niechronione współdzielenie zmiennej
	x += 5;
	// wypisanie odczytanej wartości i wartości po modyfikacji
	std::cout << loc << "," << x << "\n";
}

int main() {
	//stworzenie kilku wątków wykonujących Task_0
	std::thread t1(Task_0);
	std::thread t2(Task_0);
	std::thread t3(Task_0);
	std::thread t4(Task_0);
	//zaczekanie na zakończenie stworzonych wątków
	t1.join();
	t2.join();
	t3.join();
	t4.join();
}
