#include <stdio.h>
#include <stdlib.h>

#include <chrono>    // std::chrono::seconds
#include <iostream>  // std::cout
#include <thread>    // std::thread, std::this_thread::sleep_for

#include <semaphore.h>

sem_t firstJobDone;
sem_t secondJobDone;

void thread_task(int n) {
    if(n==1){	
    std::cout << "hello thread "
        << std::this_thread::get_id()
        << " paused " << n << " seconds" << std::endl;
    sem_post(&firstJobDone);
    }else if(n==2){
    sem_wait(&firstJobDone);	    
    std::cout << "hello thread "
        << std::this_thread::get_id()
        << " paused " << n << " seconds" << std::endl;
    sem_post(&secondJobDone);
    }else{
    sem_wait(&secondJobDone);	    
    std::cout << "hello thread "
        << std::this_thread::get_id()
        << " paused " << n << " seconds" << std::endl;
    }


}

int main(int argc, const char *argv[])
{
    sem_init(&firstJobDone,0,1);
    sem_init(&secondJobDone,0,0);
    std::thread threads[3];
    std::cout << "Spawning 3 threads...\n";
    for (int i = 0; i < 3; i++) {
        threads[i] = std::thread(thread_task, i + 1);
    }
    std::cout << "Done spawning threads! Now wait for them to join\n";
    for (int i=0;i<3;i++) {
        threads[i].join();
    }
    std::cout << "All threads joined.\n";
    int v1;
    sem_getvalue(&firstJobDone,&v1);
    std::cout<<v1<<std::endl;
    return EXIT_SUCCESS;
}
