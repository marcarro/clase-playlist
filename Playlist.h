#include <string>
#include <Cancion.h>

class Playlist {
 private:
  std::string _nombre;
  std::string _pedirDato(std::string dato);
  int _numeroCancion = 0;
  Cancion _canciones[1000];
 public:
  void agregarCancion();
};

void Playlist::agregarCancion() {
  _canciones[_numeroCancion++];
}