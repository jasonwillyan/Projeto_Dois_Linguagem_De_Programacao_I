#include "mensagem.hpp"

Mensagem::Mensagem()
{
    //Construtor padrão
}
Mensagem::~Mensagem()
{
    //Destrutor padrão
}
Mensagem::Mensagem(const string& dataHora, const string& conteudo, int idUser)
:dataHora(dataHora),conteudo(conteudo),idUser(idUser)
{
    //Construtor parametrizado
}
string Mensagem::getDataHora()
{
    return dataHora;
}
string Mensagem::getConteudo()
{
    return conteudo;
}
int Mensagem::getIdUser()
{
    return idUser;
}