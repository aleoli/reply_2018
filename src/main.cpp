#include <iostream>
#include <list>
#include <thread>

#define __n_threads__ 8

using std::cout;
using std::endl;
using std::list;
using std::thread;

#include "reply.hpp"
using namespace reply;

Lock lock;
list<Project *>::reverse_iterator it;
int n=0;

void thread_f(list<Project *> projects, list<Package *> packages);

int main(int argc, char *argv[]) {
    if(argc != 3) {
        cout << "Mancano argomenti" << endl;
        exit(1);
    }
    
    Reader r((string(argv[1])));
    cout << "1)" << endl;
    list<Package *> packages = r.getPackages();
    cout << "2)" << endl;
    list<Project *> projects = r.getProjects();
    cout << "3)" << endl;
    
    it = projects.rbegin();
    thread threads[__n_threads__];
    for(int a=0; a<__n_threads__; a++) {
        threads[a] = thread(thread_f, projects, packages);
    }
    for(int a=0; a<__n_threads__; a++) {
        threads[a].join();
    }
    
    cout << "4)" << endl;
    
    Output o(projects, string(argv[2]));
    cout << "5)" << endl;
    
    return 0;
}

void thread_f(list<Project *> projects, list<Package *> packages) {
    while(true) {
        lock.lock();
        if(n>=(int)projects.size()) {
            lock.unlock();
            return;
        }
        Project *p = *it;
        ++it;
        n++;
        lock.unlock();
        cout << p->getId() << endl;
        p->buy_res(&packages);
    }
}
