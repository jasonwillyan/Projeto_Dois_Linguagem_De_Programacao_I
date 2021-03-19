#include "servidor.hpp"

Servidor::Servidor()
{
    //Construtor padrão
}
Servidor::Servidor(int id, const string& nome):
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
void Servidor::setDescricao(const string& descricao)
{
    this->descricao = descricao;
}
vector<int>& Servidor::getParticipantes()
{
    return participantesIDs;
} 
void Servidor::setConvite(const string& codigo)
{
    this->codigoConvite = codigo;
}
string Servidor::getConvite()
{
    return codigoConvite;
}
string Servidor::getDescricao()
{
    return descricao;
}
void Servidor::addParticipante(int id)
{
    this->participantesIDs.emplace_back(id);
}