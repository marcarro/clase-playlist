#include <string>
#include <sstream>
#include <iomanip>

class Cancion {
 private:
  std::string _nombre;
  std::string _artista;
  std::string _album;
  int _duracion;

 public:
  Cancion();
  Cancion(std::string nombre, std::string artista, std::string album, int duracion);
  std::string getNombre();
  std::string getArtista();
  std::string getAlbum();
  std::string getDuracionString();
  int getDuracionInt();
  void setNombre(std::string nombre);
  void setArtista(std::string artista);
  void setAlbum(std::string album);
  void setDuracion(int duracion);
};

Cancion::Cancion()
: _nombre { "" },
  _artista { "" },
  _album { "" },
  _duracion { 0 }
{
}

Cancion::Cancion(std::string nombre, std::string artista, std::string album, int duracion) 
: _nombre { nombre },
  _artista { artista },
  _album { album },
  _duracion { duracion }
{}

std::string Cancion::getNombre() { return _nombre; }
std::string Cancion::getArtista() { return _artista; }
std::string Cancion::getAlbum() { return _album; }

std::string Cancion::getDuracionString() { 
  std::ostringstream duracionString;
  int minutos = getDuracionInt() / 60;
  int segundos = getDuracionInt() % 60;
  duracionString << minutos << ":" << std::setfill('0') << std::setw(2) << segundos;
  return duracionString.str();
}

int Cancion::getDuracionInt() { return _duracion; }

void Cancion::setNombre(std::string nombre) {
  _nombre = nombre;
}

void Cancion::setArtista(std::string artista) {
  _artista = artista;
}

void Cancion::setAlbum(std::string album) {
  _album = album;
}

void Cancion::setDuracion(int duracion) {
  _duracion = duracion;
}