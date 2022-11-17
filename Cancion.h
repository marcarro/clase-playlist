#include <string>

class Cancion {
 private:
  std::string _nombre;
  std::string _artista;
  std::string _album;
  std::string _duracion;

 public:
  Cancion(std::string nombre, std::string artista, std::string album, std::string duracion);
  std::string getNombre();
  std::string getArtista();
  std::string getAlbum();
  std::string getDuracion();
  void setNombre(std::string nombre);
  void setArtista(std::string artista);
  void setAlbum(std::string album);
  void setDuracion(std::string duracion);
};

Cancion::Cancion(std::string nombre, std::string artista, std::string album, std::string duracion) 
: _nombre { nombre },
  _artista { artista },
  _album { album },
  _duracion { duracion }
{
  // Asignacion utilizando miembros inicializadores
}

std::string Cancion::getNombre() { return _nombre; }
std::string Cancion::getArtista() { return _artista; }
std::string Cancion::getAlbum() { return _album; }
std::string Cancion::getDuracion() { return _duracion; }

void Cancion::setNombre(std::string nombre) {
  _nombre = nombre;
}

void Cancion::setArtista(std::string artista) {
  _artista = artista;
}

void Cancion::setAlbum(std::string album) {
  _album = album;
}

void Cancion::setDuracion(std::string duracion) {
  _duracion = duracion;
}