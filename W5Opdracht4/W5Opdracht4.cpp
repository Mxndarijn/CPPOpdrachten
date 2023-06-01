#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool isResourceAvailable = true;

void threadFunction(int threadId, const std::string& message) {
    std::unique_lock<std::mutex> lock(mtx);

    // Wait until the resource is available
    cv.wait(lock, [] { return isResourceAvailable; });

    // Acquire the resource
    isResourceAvailable = false;

    // Text output
    std::cout << "Thread " << threadId << ": " << message << std::endl;

    // Release the resource
    isResourceAvailable = true;

    // Notify other threads
    cv.notify_all();
}


int main() {
    // Threads aanmaken
    std::thread thread1(threadFunction, 1, "Hallo");
    std::thread thread2(threadFunction, 2, "3-verschillende");
    std::thread thread3(threadFunction, 3, "Woorden");

    // Wachten tot alle threads zijn voltooid
    thread1.join();
    thread2.join();
    thread3.join();

    return 0;
}