
#include <iostream>
#include <cmath>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include "unistd.h"
#include <iomanip>
using namespace std;
int test_thread();
void serial_test();
void mutli_thread_test(int MINV, int MAXV);
void worker(int MINV, int MAXV);
void work_mutli_thread(int MINV, int MAXV);

//#define MAX 1e8
static const int MAX = 1e8;
#define LL long long
//using LL = long long;
static LL sum = 0;
static std::mutex mtx;



void serial_test()
{   // Calculate the sum of the squares of thing that form 1 to 1e8 by singal thread.
    auto start_time = std::chrono::steady_clock::now();
    sum = 0;
    worker(1,MAX);
    auto end_time = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    //std::cout << "Serial task finish, " << ms << " ms consumed, Result: " << std::fixed << std::setprecision(3) << sum << std::endl;
    printf("the time-consumed is %d\n", ms);

    printf("serial result %lld\n",sum);
}

void mutli_thread_test(int MINV, int MAXV)
{
    auto start_time = std::chrono::steady_clock::now();
    sum = 0;
    //int MIN = 1;
    unsigned concurrent_count = std::thread::hardware_concurrency(); // 获取当前硬件支持多少个线程并发执行
    printf("the num of threads is %lld\n", concurrent_count);
    vector<thread> threads;
    for (int ii = MINV; ii <= concurrent_count;ii++) {
        int ranger = MAXV / concurrent_count * (ii);
        threads.push_back(thread(work_mutli_thread, MINV, ranger));
        MINV = ranger + 1;
    }
    for (auto& t : threads) {
        t.join();
    }
    auto end_time = std::chrono::steady_clock::now();
    auto ms = chrono::duration_cast<chrono::milliseconds>(end_time - start_time).count();
    // std::cout<<"concurrency task finish, "<< ms <<" ms consumed, Result: " << std::fixed << std::setprecision(3)<<sum << std::endl;
    printf("the time-consumed is %d\n", ms);
    printf("并发：%lld\n", sum);

    

}

void worker(int MINV, int MAXV)
{
    for (int ii = MINV; ii <= MAXV;ii++ ) {
        sum += ii * (LL)ii;
    }
}

void work_mutli_thread(int MINV, int MAXV)
{
    LL mutli_sum = 0;
    for (int ii = MINV; ii <= MAXV; ii++) {
        mutli_sum += ii * (LL)ii;
    }
    mtx.lock();
    sum += mutli_sum;
    mtx.unlock();


}

int test_thread()
{   //serial execute
    serial_test();
    //mutli execute
    mutli_thread_test(1,MAX);
    return 0;
}

//mian function as a entry
int main() {
    //call the function named test_thread(),the test of mutli thread.  
    test_thread();
    return 0;
}




/*
#include <iostream>
#include <cmath>
#include <mutex>
#include <chrono>
#include <thread>
#include <vector>
#include <string>
#include "unistd.h"
#include <iomanip> 

static const int MAX = 1e8;
using LL = long long;
static LL sum = 0;
void worker(int minV, int maxV) {
    for (int i = minV; i <= maxV; i++) {
        sum += i * (LL)i;
    }
}
void serial_task() {
    // 单线程 计算1e8的平方根之和
    auto start_time = std::chrono::steady_clock::now();
    sum = 0;
    worker(1, MAX);
    auto end_time = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout<<"Serial task finish, "<< ms <<" ms consumed, Result: " << std::fixed << std::setprecision(3)<<sum << std::endl;
    printf("线性：%lld\n", sum);
}
static std::mutex mtx;
void concurrent_worker(int minV, int maxV) {
    LL tmp_sum = 0;
    for (int i = minV; i <= maxV; i++) {
        tmp_sum += i * (LL)i;

    }
    mtx.lock();
    sum += tmp_sum;
    mtx.unlock();
}
void concurrent_task(int minV, int maxV) {
    auto start_time = std::chrono::steady_clock::now();
    unsigned concurrent_count = std::thread::hardware_concurrency(); // 获取当前硬件支持多少个线程并发执行
    std::cout << " hardware_concurrency: " << concurrent_count << std::endl;
    std::vector<std::thread> threads;
    minV = 0;
    sum = 0;
    for (int t = 0; t < concurrent_count; t++) {
        int range = maxV / concurrent_count * (t + 1);
        threads.push_back(std::thread(concurrent_worker, minV, range));
        minV = range + 1;
    }
    for (auto& t : threads) {
        t.join();
    }
    auto end_time = std::chrono::steady_clock::now();
    auto ms = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time).count();
    std::cout<<"concurrency task finish, "<< ms <<" ms consumed, Result: " << std::fixed << std::setprecision(3)<<sum << std::endl;
    printf("并发：%lld\n", sum);
}

int test_thread() {
    serial_task();
    concurrent_task(1, MAX);
    return 0;
}
int main() {
    test_thread();
    return 0;
}
*/


