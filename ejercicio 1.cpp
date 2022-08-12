#include <iostream>       
#include <vector>        

class Sumatoria_x          
{
public:
    int operator()(std::vector<int>& x)     
    {
        int resul{0};
        for (int i = 0; i < x.size(); i++)
        {
            resul += x[i];
        }
        return resul;
    }
};

class Sumatoria_y          
{
public:
    int operator()(std::vector<int>& y)     
    {
        int resul{0};
        for (int i = 0; i < y.size(); i++)
        {
            resul += y[i];
        }
        return resul;
    }
};

class Sumatoria_xy         
{
public:
    int operator()(std::vector<int>& x,std::vector<int>& y)     
    {
        int resul{0};
        for (int i = 0; i < x.size(); i++)
        {
            resul += (x[i]*y[i]);
        }
        return resul;
    }
};

class Sumatoria_xx          
{
public:
    int operator()(std::vector<int>& x)     
    {
        int resul{0};
        for (int i = 0; i < x.size(); i++)
        {
            resul += (x[i]*x[i]);
        }
        return resul;
    }
};

class Regresion        
{
public:
    void operator()(std::vector<int>& x,std::vector<int>& y)       
    {
        if (x.size() != y.size())
        {
            std::cout<<"-> Lista de datos con tamaños diferentes.\n";
            return;
        }

        Sumatoria_x X;
        Sumatoria_y Y;
        Sumatoria_xy XY;
        Sumatoria_xx XX;

        auto sumatoria_x{(float)X(x)};
        auto sumatoria_y{(float)Y(y)};
        auto sumatoria_xy{(float)XY(x,y)};
        auto sumatoria_xx{(float)XX(x)};
        auto n = (float)x.size();

        auto b = ((n*sumatoria_xy)-(sumatoria_x*sumatoria_y))/
                ((n*sumatoria_xx)-(sumatoria_x*sumatoria_x));
        auto a = ((sumatoria_y)-(b*sumatoria_x))/(n);

        std::cout<<"La ecuacion es: y = "<<a<<" + "<<b<<"(x)";
    }
};



int main()     
{
    std::vector<int> Vy = {3,5,9,10,20,21,24,24,27,35};
    std::vector<int> Vx = {100,90,80,45,50,50,60,40,25,20};

    std::cout<<"\t\ty = a + bx\n";

    Regresion R;
    R(Vx,Vy);

    return 0;
}

