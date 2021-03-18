#ifndef USUARIO_H
#define USUARIO_H

#include <iostream>
using namespace std;

class Usuario{
    private:
        int id;
        string nome;
        string email;
        string senha;
        bool status;

    public:
        Usuario();
        string getEmail();
        string getSenha();
        int getId();
        Usuario(int id, string nome, string email, string senha);
        ~Usuario();
};


#endif