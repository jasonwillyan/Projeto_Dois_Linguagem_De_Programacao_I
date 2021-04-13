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
string Servidor::addCanal(const string& nome, const string& tipo)
{
    if(tipo == "texto")
    {
        for(auto& canal : canais)
        {
            if(canal->getNome() == nome && canal->getTipo() == "texto")
            {
                    return "Canal de texto "+nome+" já existe";
            } 
        }
        CanalTexto* canalTexto = new CanalTexto(nome,tipo);
        canais.emplace_back(canalTexto);
        return "Canal de texto "+nome+" criado";
    }
    else if(tipo == "voz")
    {
        for(auto& canal : canais)
        {
            if(canal->getNome() == nome && canal->getTipo() == "voz")
            {
                    return "Canal de voz "+nome+" já existe";
            } 
        }
        CanalVoz* canalVoz = new CanalVoz(nome,tipo);
        canais.emplace_back(canalVoz);
        return "Canal de Voz "+nome+" criado";
    }
    return "Nao foi possivel criar o canal";
}
vector<Canal*>& Servidor::getCanais()
{
    return canais;
}
