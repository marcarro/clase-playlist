// Héctor Marcelo Arroyo Morantte - A00837236
// TC1033.304
// Creado 14/11/2022
// Actualizado 28/11/2022

#include <string>
#include <sstream>
#include <iomanip>
#include <random>
#include <algorithm>
#include "Cancion.h"

class Playlist {
 private:
  std::string _nombre;
  int _numeroCancion = 0;
  Cancion _canciones[1000];
  
  // Convierte la duracion tipo string a un int que representa esa misma duración en segundos
  // Entradas - duracionString: string
  // Salidas - duracion: int (segundos)
  int _stringDuracionASegundos(std::string duracionString);
  
  // Llena el arreglo con números en orden del 0 al n - 1 donde n es el número de elementos
  // Entradas - indices: int[], numCanciones: int
  // Salidas - Ninguna, modifica por referencia
  void _poblarIndices(int *arreglo, int numElementos);
  bool _campoNombreIngresado = true;
 public:
  // Constructor por omisión
  // Entradas - Ninguna
  // Salidas - Objeto con valores indefinidos
  Playlist();
  
  // Función para entrada de datos
  // Entradas - Ninguna
  // Salidas - Dato de entrada: string
  std::string pedirDato();
  
  // Consulta del nombre de la playlist
  // Entradas - Ninguna
  // Salidas - Nombre de la playlist: string
  std::string getNombre();

  // Consulta del numero de canciones
  // Entradas - Ninguna
  // Salidas - Número de canciones: int
  int getNumCanciones();

  // Consulta de duración total de la playlist
  // Entradas - Ninguna
  // Salida - Duración total de la playlist: string
  std::string getDuracionTotal();

  // Verificación del ingreso del campo del nombre de la canción
  // Entradas - Ninguna
  // Salidas - Verificación: bool
  bool verificarCampoNombre();

  // Obtención del nombre para la playlist - Modificación interna
  // Entradas - Ninguna
  // Salidas - Ninguna
  void creaPlaylist();

  // Agregación de una canción al playlist - Modificación interna
  // Entradas - Ninguna
  // Salidas - Ninguna
  void agregarCancion();

  // Listado de canciones en la playlist - Output a consola
  // Entradas - Ninguna
  // Salidas - Ninguna
  void consultaPlaylist();

  // Listado de canciones en la playlist en orden aleatorio - Output a consola
  // Entradas - Ninguna
  // Salidas - Ninguna
  void consultaPlaylistAleatoria();

  // Desplegado del mensaje de creación de la playlist - Output a consola
  // Entradas - Ninguna
  // Salidas - Ninguna
  void mostrarMensajeCreacion();

  // Desplegado de la cuarta canción en la playlist - Output a consola
  // Entradas - Ninguna
  // Salidas - Ninguna
  void mostrarCuartaCancion();

  // Desplegado del mensaje del modo aleatorio - Output a consola
  // Entradas - Ninguna
  // Salidas - Ninguna
  void modoAleatorio();
};

// Constructor por omisión
// Entradas - Ninguna
// Salidas - Objeto con valores indefinidos
Playlist::Playlist() {}

// Convierte la duracion tipo string a un int que representa esa misma duración en segundos
// Entradas - duracionString: string
// Salidas - duracion: int (segundos)
int Playlist::_stringDuracionASegundos(std::string duracionString) {
  std::istringstream inputDuracion(duracionString);
  int duracionMinutos;
  int duracionSegundos;
  inputDuracion >> duracionMinutos >> duracionSegundos;
  return (duracionMinutos * 60) + duracionSegundos;
}

// Llena el arreglo con números en orden del 0 al n - 1 donde n es el número de elementos
// Entradas - indices: int[], numCanciones: int
// Salidas - Ninguna, modifica por referencia
void Playlist::_poblarIndices(int *arreglo, int numElementos) {
  for (int indice = 0; indice < numElementos; indice++)
    arreglo[indice] = indice;
}

// Función para entrada de datos
// Entradas - Ninguna
// Salidas - Dato de entrada: string
std::string Playlist::pedirDato() {
  std::string dato;
  std::getline(std::cin, dato);
  return dato;
}

// Consulta del nombre de la playlist
// Entradas - Ninguna
// Salidas - Nombre de la playlist: string
std::string Playlist::getNombre() {
  return _nombre;
}

// Consulta del numero de canciones
// Entradas - Ninguna
// Salidas - Número de canciones: int
int Playlist::getNumCanciones() {
  return _numeroCancion;
}

// Consulta de duración total de la playlist
// Entradas - Ninguna
// Salida - Duración total de la playlist: string
std::string Playlist::getDuracionTotal() {
  std::ostringstream duracionString;
  int duracionTotal;
  for (int cancion = 0; cancion < getNumCanciones(); cancion++) {
    duracionTotal += _canciones[cancion].getDuracionInt();
  }
  int minutos = duracionTotal / 60;
  int segundos = duracionTotal % 60;
  duracionString << minutos << ":" << std::setfill('0') << std::setw(2) << segundos;
  return duracionString.str();
}

// Verificación del ingreso del campo del nombre de la canción
// Entradas - Ninguna
// Salidas - Verificación: bool
bool Playlist::verificarCampoNombre() {
  return _campoNombreIngresado;
}

// Obtención del nombre para la playlist - Modificación interna
// Entradas - Ninguna
// Salidas - Ninguna
void Playlist::creaPlaylist() {
  std::string nombre = pedirDato();
  _nombre = nombre;
}

// Agregación de una canción al playlist - Modificación interna
// Entradas - Ninguna
// Salidas - Ninguna
void Playlist::agregarCancion() {
  std::string nombre = pedirDato();
  if (nombre.empty()) {
    _campoNombreIngresado = false;
    return;
  }
  std::string artista = pedirDato();
  std::string album = pedirDato();
  std::string duracionString = pedirDato();
  int duracion = _stringDuracionASegundos(duracionString);
  
  _canciones[_numeroCancion++] = Cancion(nombre, artista, album, duracion);
}

// Listado de canciones en la playlist - Output a consola
// Entradas - Ninguna
// Salidas - Ninguna
void Playlist::consultaPlaylist() {
  std::cout << "-Playlist consulta-" << std::endl;
  std::cout << "Playlist: " << getNombre() << std::endl;
  std::cout << "Cantidad de canciones: " << getNumCanciones() << std::endl;
  std::cout << "Duracion total: " << getDuracionTotal() << std::endl;
  std::cout << "Modo de ejecución: Secuencial" << std::endl;
  std::cout << "Canciones:" << std::endl;
  for (int cancion = 0; cancion < getNumCanciones(); cancion++) {
    std::cout << cancion + 1 << "." << _canciones[cancion].getNombre() << std::endl;
    std::cout << "  " << _canciones[cancion].getArtista() << std::endl;
    std::cout << "  " << _canciones[cancion].getAlbum() << std::endl;
    std::cout << "  " << _canciones[cancion].getDuracionString() << std::endl;
  }
  std::cout << std::endl;
}

// Listado de canciones en la playlist en orden aleatorio - Output a consola
// Entradas - Ninguna
// Salidas - Ninguna
void Playlist::consultaPlaylistAleatoria() {
  int indices[getNumCanciones()];
  _poblarIndices(indices, getNumCanciones());

  std::random_device rd;
  std::mt19937 g(rd());
  std::shuffle(indices, indices + getNumCanciones(), g);

  std::cout << "-Lista de reproducción-" << std::endl;
  for (int cancion = 0; cancion < getNumCanciones(); cancion++) {
    int indice = indices[cancion];
    std::cout << cancion + 1 << "." << _canciones[indice].getNombre() << std::endl;
  }
}

// Desplegado del mensaje de creación de la playlist - Output a consola
// Entradas - Ninguna
// Salidas - Ninguna
void Playlist::mostrarMensajeCreacion() {
  std::cout << "-Playlist creada-" << std::endl;
  std::cout << "Playlist: " << getNombre() << std::endl;
  std::cout << "Cantidad de canciones: " << getNumCanciones() << std::endl;
  std::cout << "Duracion total: " << getDuracionTotal() << std::endl;
  std::cout << std::endl;
}

// Desplegado de la cuarta canción en la playlist - Output a consola
// Entradas - Ninguna
// Salidas - Ninguna
void Playlist::mostrarCuartaCancion() {
  if (getNumCanciones() < 3) {
    std::cout << "Cuarta canción no existente!" << std::endl;
    std::cout << std::endl;
    return;
  }
  std::cout << "-Canción consulta-" << std::endl;
  std::cout << "Número de canción: 4" << std::endl;
  std::cout << "Título: " << _canciones[3].getNombre() << std::endl;
  std::cout << "Artista: " << _canciones[3].getArtista() << std::endl;
  std::cout << "Álbum: " << _canciones[3].getAlbum() << std::endl;
  std::cout << "Duración: " << _canciones[3].getDuracionString() << std::endl;
  std::cout << std::endl;
}

// Desplegado del mensaje del modo aleatorio - Output a consola
// Entradas - Ninguna
// Salidas - Ninguna
void Playlist::modoAleatorio() {
  std::cout << "-Playlist cambio-" << std::endl;
  std::cout << "Modo de ejecucion: Aleatorio" << std::endl;
  std::cout << std::endl;
}