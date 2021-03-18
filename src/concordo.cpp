#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include "sistema.hpp"
#include "executor.hpp"

using namespace std;

int main() {
  setlocale(LC_ALL, "");
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  sistema.create_user("jasonwillyan@hotmail.com", "123456", "jason willyan");
  sistema.login("jasonwillyan@hotmail.com", "123456");
  sistema.create_server("jabulani");
  // o executor recebe o cin e o cout. Ele irá os utilizar para ler as linhas
  // de comando, executar o método correto em "sistema" e exibir as mensagens
  executor.iniciar(cin, cout);


  return 0;
}