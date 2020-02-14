#include <iostream>
#include <list>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <atomic>
#include <vector>

using namespace std;

class Workers{

public:

    Workers(int threads) {
        noOfThreads = threads;
    }


    void post(function<void()> task){
        lock_guard<mutex> lock(tasks_mutex);
        tasks.emplace_back(task);
       // not correct place to place this --  cout << "task " << &task << " runs in thread " << this_thread::get_id() << endl;
    }

    void start(){
        for(int i=0; i<noOfThreads; i++){
                threads.emplace_back([this]{
                    while (true)
                    {
                        function<void()> task;
                        {
                            lock_guard<mutex> lock(tasks_mutex);
                            // TODO: use conditional variable

                            if (!tasks.empty())
                            {
                                task = *tasks.begin(); // Copy task for later use
                                tasks.pop_front(); // Remove task from list
                            }

                        }
                        if (task)
                            task(); // Run task outside of mutex lock
                    }

                });
            }
    }

    void stop(vector<thread> threads){
        for (auto &thread : threads)
            thread.join();
    }

    void post_timeout(int timeoutMs){
        this_thread::sleep_for(std::chrono::milliseconds(timeoutMs));
    }


private:
    vector<thread> threads;
    list<function<void()>> tasks;
    mutex tasks_mutex;
    int noOfThreads;
};

int main() {
    Workers worker_threads(4);
    Workers event_loop(1);
    worker_threads.start(); // Create 4 internal threads
    event_loop.start(); // Create 1 internal thread
    worker_threads.post([] {
        // Task A
    });
    worker_threads.post([] {
        // Task B
        // Might run in parallel with task A
    });
    event_loop.post([] {
        // Task C
        // Might run in parallel with task A and B
    });
    event_loop.post([] {
        // Task D
        // Will run after task C
        // Might run in parallel with task A and B
    });

}
