#include "canalTexto.hpp"

CanalTexto::CanalTexto()
{
    //Construtor padrão
}
CanalTexto::CanalTexto(const string& nome, const string& tipo):Canal(nome,tipo)
{
    //Construtor parametrizado
}
CanalTexto::~CanalTexto()
{
    //Destrutor padrão
}
 vector<Mensagem>& CanalTexto::getMensagens()
{
    return mensagens;
}