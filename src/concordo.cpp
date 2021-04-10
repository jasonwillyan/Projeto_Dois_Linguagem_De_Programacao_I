#include <iostream>
#include <list>
#include <vector>
#include <string>
#include <clocale>
#include "sistema.hpp"
#include "executor.hpp"

using namespace std;

int main()
{
  setlocale(LC_ALL, "");
  // inicialização do sistema
  Sistema sistema;
  Executor executor(sistema);

  cout << sistema.create_user("jasonwillyan@hotmail.com", "123", "jason willyan") << endl;
  cout << sistema.login("jasonwillyan@hotmail.com", "123") << endl;
  cout << sistema.create_server("canal-do-jason") << endl;
  





  executor.iniciar(cin, cout);



  return 0;
}