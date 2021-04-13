#include "canalVoz.hpp"

CanalVoz::CanalVoz()
{
    //Construtor padrão
}
CanalVoz::CanalVoz(const string& nome, const string& tipo):Canal(nome,tipo)
{
    //Construtor parametrizado
}
CanalVoz::~CanalVoz()
{
    //Destrutor padrão
}
void CanalVoz::SendMensage(const Mensagem& mensagem)
{
    this->ultimaMensagem = mensagem;
}
Mensagem CanalVoz::getUltimaMensagem()
{
    return ultimaMensagem;
}

