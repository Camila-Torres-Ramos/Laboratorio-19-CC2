#include <iostream>                    
#include <vector>                     

#include <random>                      
#include <chrono>                     

#include <algorithm>                      

class Elemento         
{
public:
    int a;
    int b;
    void operator ()()        
    {
        auto num_base = std::chrono::system_clock::now().time_since_epoch().count();
        std::mt19937 generador(num_base);
        std::uniform_int_distribution<int>distrib(1,100);
        this->a = distrib(generador);          
        this->b = distrib(generador);           
    }
};

class Funcion          
{
public:
    bool operator()(Elemento E1,Elemento E2)                  
    {
        return (E1.a<E2.b);
    }
};

int main()
{
    std::vector<Elemento> *vector;
    vector = new std::vector<Elemento> (5,Elemento());
    
    std::cout<<"Lista Inicial:\n";
    for (int i = 0; i < 20; i++)      
    {
        (*vector)[i]();
        std::cout<<"("<<(*vector)[i].a<<","<<(*vector)[i].b<<");";     
    }

    std::sort(vector->begin(),vector->begin()+20,Funcion());       
    std::cout<<std::endl;

    std::cout<<"Lista ordenada con a<b:\n";
    for (int i = 0; i < 20; i++)                
    {
        std::cout<<"("<<(*vector)[i].a<<","<<(*vector)[i].b<<");";
    }
    return 0;
}
