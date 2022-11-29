// Héctor Marcelo Arroyo Morantte - A00837236
// TC1033.304
// Creado 14/11/2022
// Actualizado 28/11/2022

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
  // Constructor por omisión
  // Entradas - Ninguna
  // Salidas - Objeto con valores predefinidos
  Cancion();

  // Constructor
  // Entradas - nombre:string, artista: string, album: string, duracion: int
  // Salidas - Objeto con valores definidos
  Cancion(std::string nombre, std::string artista, std::string album, int duracion);
  
  // Consulta de nombre de canción
  // Entradas - Ninguna
  // Salidas - nombre: string
  std::string getNombre();

  // Consulta de artista de canción
  // Entradas - Ninguna
  // Salidas - artista: string
  std::string getArtista();

  // Consulta de album de canción
  // Entradas - Ninguna
  // Salidas - album: string
  std::string getAlbum();

  // Consulta de la duración de canción como string
  // Entradas - Ninguna
  // Salidas - duracion: string
  std::string getDuracionString();

  // Consulta de la duración de canción en segundos
  // Entradas - Ninguna
  // Salidas - duracion: int
  int getDuracionInt();

  // Setter del nombre de la canción - Modificación interna
  // Entradas - nombre: string
  // Salidas - Ninguna
  void setNombre(std::string nombre);

  // Setter del artista de la canción - Modificación interna
  // Entradas - artista: string
  // Salidas - Ninguna
  void setArtista(std::string artista);

  // Setter del album de la canción - Modificación interna
  // Entradas - album: string
  // Salidas - Ninguna
  void setAlbum(std::string album);

  // Setter de la duración de la canción en segundos - Modificación interna
  // Entradas - duracion: int
  // Salidas - Ninguna
  void setDuracion(int duracion);
};

// Constructor por omisión
// Entradas - Ninguna
// Salidas - Objeto con valores indefinidos
Cancion::Cancion()
: _nombre { "" },
  _artista { "" },
  _album { "" },
  _duracion { 0 }
{
}

// Constructor
// Entradas - nombre:string, artista: string, album: string, duracion: int
// Salidas - Objeto con valores definidos
Cancion::Cancion(std::string nombre, std::string artista, std::string album, int duracion) 
: _nombre { nombre },
  _artista { artista },
  _album { album },
  _duracion { duracion }
{}

// Consulta de nombre de canción
// Entradas - Ninguna
// Salidas - nombre: string
std::string Cancion::getNombre() { return _nombre; }

// Consulta de artista de canción
// Entradas - Ninguna
// Salidas - artista: string
std::string Cancion::getArtista() { return _artista; }

// Consulta de album de canción
// Entradas - Ninguna
// Salidas - album: string
std::string Cancion::getAlbum() { return _album; }

// Consulta de la duración de canción como string
// Entradas - Ninguna
// Salidas - duracion: string
std::string Cancion::getDuracionString() { 
  std::ostringstream duracionString;
  int minutos = getDuracionInt() / 60;
  int segundos = getDuracionInt() % 60;
  duracionString << minutos << ":" << std::setfill('0') << std::setw(2) << segundos;
  return duracionString.str();
}

// Consulta de la duración de canción en segundos
// Entradas - Ninguna
// Salidas - duracion: int
int Cancion::getDuracionInt() { return _duracion; }

// Setter del nombre de la canción - Modificación interna
// Entradas - nombre: string
// Salidas - Ninguna
void Cancion::setNombre(std::string nombre) {
  _nombre = nombre;
}

// Setter del artista de la canción - Modificación interna
// Entradas - artista: string
// Salidas - Ninguna
void Cancion::setArtista(std::string artista) {
  _artista = artista;
}

// Setter del album de la canción - Modificación interna
// Entradas - album: string
// Salidas - Ninguna
void Cancion::setAlbum(std::string album) {
  _album = album;
}

// Setter de la duración de la canción en segundos - Modificación interna
// Entradas - duracion: int
// Salidas - Ninguna
void Cancion::setDuracion(int duracion) {
  _duracion = duracion;
}