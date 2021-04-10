#include "canal.hpp"

Canal::Canal()
{
    //Construtor padrão
}
string Canal::getNome()
{
    return this->nome;
}
Canal::Canal(const string& nome, const string& tipo):nome(nome),tipo(tipo)
{
    //Construtor parametrizado
}
string Canal::getTipo()
{
    return this->tipo;
}
Canal::~Canal()
{
    //Destrutor padrão
}