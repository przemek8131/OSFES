#include <iostream>
#include <thread>
#include <vector>
#include <chrono>


#if 0	//1 - mutex lock, 0 - std::lock_guard
int x; //wartość globalna
std::mutex m;
void Task_0(void)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	m.lock();
	auto loc{ x };
	x += 5;
	std::cout << loc << " , " << x << "\n";
	m.unlock();
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
#else
int x; //wartość globalna
std::mutex m;
void Task_0(void)
{
	std::this_thread::sleep_for(std::chrono::milliseconds(10));
	std::lock_guard<std::mutex> lock(m);
	auto loc{ x };
	x += 5;
	std::cout << loc << " , " << x << "\n";
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
	std::cout << " Wynik operacji: " << x << "\n";
}

#endif 
