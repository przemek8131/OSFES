#include <iostream>
#include <thread>
#include <vector>
#include <chrono>
#include <atomic>

std::atomic<int> x; //wartość globalna
void Task_0(void)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	// chronione współdzielenie zmiennej
	x += 5;	//wykorzystanie przeciążonego operatora +=
}

int main() {

	std::vector<std::thread> threads;
	const int num_threads = 20;
	//stworzenie kilku wątków wykonujących Task_0

	for (int i = 0; i < num_threads; i++) {
		threads.push_back(std::thread(Task_0));
	}
	for (auto& thread : threads) {
		thread.join();
	}
	std::cout << "Wynik operacji: " << x << "\n";
}
