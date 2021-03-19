#include "usuario.hpp"

Usuario::Usuario()
{
    //Construtor padrão
}
Usuario::Usuario(int id, string nome, string email, string senha):
    id(id), nome(nome), email(email), senha(senha){}
    
Usuario::~Usuario()
{
    //Destrutor padrão
}
string Usuario::getEmail()
{
    return email;
}
string Usuario::getSenha()
{
    return senha;
}
int Usuario::getId()
{
    return id;
}
void Usuario::addServer(Servidor* servidor)
{
    this->servidor = servidor;
}
Servidor* Usuario::getServer()
{
    return servidor;
}
string Usuario::getNome()
{
    return nome;
}