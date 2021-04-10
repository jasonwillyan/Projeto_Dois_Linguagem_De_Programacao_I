#ifndef CANALTEXTO_H
#define CANALTEXTO_H

#include <vector>
#include "mensagem.hpp"
#include "canal.hpp"

using namespace std;

class CanalTexto: public Canal{
    private:
    vector<Mensagem> mensagens;

    public:
        CanalTexto();
        vector<Mensagem> &getMensagens();
        CanalTexto(const string& nome, const string& tipo);
        ~CanalTexto();
};

#endif