#include "servidor.hpp"

Servidor::Servidor()
{
    //Construtor padrão
}
Servidor::Servidor(int id, string nome):
    idUser(id), nome(nome){}
    
Servidor::~Servidor()
{
    //Destrutor padrão
}
int Servidor::getDono()
{
    return idUser;
}
string Servidor::getNome()
{
    return nome;
}
void Servidor::setDescricao(string descricao)
{
    this->descricao = descricao;
}
const vector<int>& Servidor::getParticipantes()
{
    return participantesIDs;
} 