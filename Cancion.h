#include <string>

class Cancion {
 private:
  std::string _nombre;
  std::string _artista;
  std::string _album;
  std::string _duracion;

 public:
  std::string getNombre();
  std::string getArtista();
  std::string getAlbum();
  std::string getDuracion();
  void setNombre(std::string nombre);
  void setArtista(std::string artista);
  void setAlbum(std::string album);
  void setDuracion(std::string duracion);
}

std::string Cancion::getNombre() { return _nombre; }
std::string Cancion::getArtista() { return _artista; }
std::string Cancion::getAlbum() { return _album; }
std::string Cancion::getDuracion() { return _duracion }