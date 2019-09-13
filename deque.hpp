#include <iostream>
#include <new>
using namespace std;
template <typename T>
struct Deque{
    T* vector;
    int esquerda, direita, tamanho,elementos;
};
//Alocando e inicializando deque
template <typename T>
bool inicializar(Deque<T> &D){
    D.vector = new T[1];
    if (D.vector == nullptr){
        return true;
    }
    D.esquerda =0;
    D.direita =0;
    D.tamanho =1;
    D.elementos =0;
    return false;
}
//Desalocando deque
template <typename T>
void terminar(Deque<T> &D){
    delete[] D.vector;
}
//Realocando deque dinamicamente
template <typename T>
bool redimensionar(int tam_vn,Deque<T> &D){
    T *v = new(nothrow)T[tam_vn];
    if(v == nullptr)return true;
    int j =D.esquerda;
    D.esquerda = (tam_vn - D.elementos)/2;
    D.direita = D.esquerda + D.elementos-1;
    for(int i=D.esquerda;i<=D.direita;i+=1){
        v[i] = D.vector[j];
        j+=1;
    }
    delete[] D.vector;D.vector=v;
    D.tamanho = tam_vn;
    return false;
}

//Checar se o deque está vazio;
template <typename T>
bool vazio(Deque<T> &D){
    if(D.elementos==0){
        return true;
    }
    return false;
}

//Tratando elementos da esquerda;
template <typename T>
bool inserir_esq(Deque<T> &D, T e){
    if(D.esquerda==0){
        if(redimensionar(D.tamanho*2,D))return true;
    }
    D.esquerda-=1;
    D.vector[D.esquerda] = e;
    D.elementos +=1;
    return false;
}

template <typename T>
T remover_esq(Deque<T> &D){
    T value = D.vector[D.esquerda];
    D.esquerda +=1;
    D.elementos -=1;
    return value;
}

//Tratando elementos da direita;
template <typename T>
bool inserir_dir(Deque<T> &D, T e){
    if(D.direita==D.tamanho-1){
        if(redimensionar(D.tamanho*2,D))return true;
    }
    D.direita +=1;
    D.vector[D.direita] = e;
    D.elementos +=1;
    return false;
}

template <typename T>
T remover_dir(Deque<T> &D){
    T value = D.vector[D.direita];
    D.direita -=1;
    D.elementos -=1;
    return value;
}

template <typename T>
void print_deque(const Deque<T> &D){
    cout << "Deque: [";
    for(int i=0;i<D.tamanho;++i){
        cout << D.vector[i] << " ";
    }
    cout << "];\n";
}

//CASO ESQUERDA=DIREITA VAZIA (EXCEÇÃO)
//MUDAR FORMULA DIREITO