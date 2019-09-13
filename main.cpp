#include <iostream>
#include <new>
using namespace std;
#include "deque.hpp"

int main(void){
    Deque<int> d;
    inicializar(d);
    print_deque(d);
    inserir_dir(d,813);
    print_deque(d);
    inserir_dir(d,813);
    print_deque(d);
    inserir_dir(d,813);
    print_deque(d);
    inserir_dir(d,813);
    print_deque(d);
    inserir_dir(d,813);
    print_deque(d);
    inserir_dir(d,813);
    print_deque(d);
    inserir_dir(d,813);
    print_deque(d);
    remover_dir(d);    
    print_deque(d);

}   