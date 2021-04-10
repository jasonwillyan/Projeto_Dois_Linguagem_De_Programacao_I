#ifndef SERVIDOR_H
#define SERVIDOR_H

#include <iostream>
#include <vector>
#include "canal.hpp"
#include "canalTexto.hpp"
#include "canalVoz.hpp"

using namespace std;

class Servidor{
    private:
        int idUser;
        string nome;
        string descricao;
        string codigoConvite;
        vector<Canal> canais;
        vector<int> participantesIDs;
        
    public:
        Servidor();
        int getDono();
        string getNome();
        vector<int>& getParticipantes();
        void setDescricao(const string& descricao);
        string getDescricao();
        Servidor(int id, const string& nome);
        string getConvite();
        void setConvite(const string& codigo);
        void addParticipante(int id);
        vector<Canal>& getCanais();
        string addCanal(const string& nome, const string& tipo);
        ~Servidor();
};

#endif