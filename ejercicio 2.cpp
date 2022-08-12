#include <iostream>             
#include <string>               
#include <vector>               


class Objeto           
{
public:
    std::string _objeto;
    void operator = (std::string dato)     
    {
        this->_objeto = dato;
    }

    std::vector<int> operator ()(int _inicio, int _fin, std::string buscar)         
    {
        std::vector<int> resultado;
        int inicio{_inicio-1},fin{_fin-1};
        if (inicio<0 || inicio>_fin)      
        {
            inicio = 0;
        }
        if (fin<_inicio || fin > this->_objeto.size())        
        {
            fin = this->_objeto.size();
        }
        
        int cont{0},ok{0};
        for (int i = inicio; i < fin; i++)
        {
            ok = i;
            for (int k = 0, j = i; k < buscar.size(); k++, j++)
            {
                if (buscar[k] == this->_objeto[j])
                {
                    cont++;
                }else
                {
                    break;
                }
            }
            if (cont == buscar.size())
            {
                resultado.push_back(ok);
                i += buscar.size(); 
            }
            cont = 0;
        }

        return resultado;
    }
};



int main()      
{
    Objeto cadena;
    cadena = "Hola a todos, Hola a ti tambien.";
    std::vector<int> vector = cadena(1,33,"Hola");
    std::cout<<"-> Las ocurrencias de la palabra estan en las posisiciones: ";
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout<< vector[i]+1<<", ";
    }

    std::cout<<std::endl;

    Objeto cadena2;
    cadena2 = "El curso, es el curso que fue cursando por el alumno del cursonuevo";
    vector = cadena2(1,67,"curso");
    std::cout<<"-> Las ocurrencias de la palabra estan en las posisiciones: ";
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout<< vector[i]+1<<", ";
    }
    vector.~vector();

    return 0;
}

