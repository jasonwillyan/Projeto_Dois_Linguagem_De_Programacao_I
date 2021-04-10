#ifndef CANALVOZ_H
#define CANALVOZ_H

#include "mensagem.hpp"
#include "canal.hpp"

class CanalVoz: public Canal{
    private:
        Mensagem ultimaMensagem;
        
    public:
        CanalVoz();
        CanalVoz(const string& nome, const string& tipo);
        ~CanalVoz();
};

#endif