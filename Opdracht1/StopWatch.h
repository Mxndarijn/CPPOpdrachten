#pragma once
#include <chrono>

using namespace std::chrono;
using namespace std;

class StopWatch
{
	private:
		steady_clock::time_point startTime;
		steady_clock::time_point endTime;

	public:
		StopWatch() {
			start();
		}

		void start() {
			startTime = steady_clock::now();
		}

		void stop() {
			endTime = steady_clock::now();
		}

		long getElapsedTime() {
			return duration_cast<milliseconds>(endTime - startTime).count();
		}
	
};

