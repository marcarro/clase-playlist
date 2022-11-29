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
  int _stringDuracionASegundos(std::string duracionString);
  void _poblarIndices(int *indices, int numCanciones);
  bool _campoNombreIngresado = true;
 public:
  Playlist();
  std::string pedirDato();
  std::string getNombre();
  int getNumCanciones();
  std::string getDuracionTotal();
  bool verificarCampoNombre();
  void creaPlaylist();
  void agregarCancion();
  void consultaPlaylist();
  void consultaPlaylistAleatoria();
  void mostrarMensajeCreacion();
  void mostrarCuartaCancion();
  void modoAleatorio();
};

Playlist::Playlist() {}

int Playlist::_stringDuracionASegundos(std::string duracionString) {
  std::istringstream inputDuracion(duracionString);
  int duracionMinutos;
  int duracionSegundos;
  inputDuracion >> duracionMinutos >> duracionSegundos;
  return (duracionMinutos * 60) + duracionSegundos;
}

void Playlist::_poblarIndices(int *indices, int numCanciones) {
  for (int indice = 0; indice < numCanciones; indice++)
    indices[indice] = indice;
}

std::string Playlist::pedirDato() {
  std::string dato;
  std::getline(std::cin, dato);
  return dato;
}

std::string Playlist::getNombre() {
  return _nombre;
}

int Playlist::getNumCanciones() {
  return _numeroCancion;
}

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

bool Playlist::verificarCampoNombre() {
  return _campoNombreIngresado;
}

void Playlist::creaPlaylist() {
  std::string nombre = pedirDato();
  _nombre = nombre;
}

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

void Playlist::mostrarMensajeCreacion() {
  std::cout << "-Playlist creada-" << std::endl;
  std::cout << "Playlist: " << getNombre() << std::endl;
  std::cout << "Cantidad de canciones: " << getNumCanciones() << std::endl;
  std::cout << "Duracion total: " << getDuracionTotal() << std::endl;
  std::cout << std::endl;
}

void Playlist::mostrarCuartaCancion() {
  std::cout << "-Canción consulta-" << std::endl;
  std::cout << "Número de canción: 4" << std::endl;
  std::cout << "Título: " << _canciones[3].getNombre() << std::endl;
  std::cout << "Artista: " << _canciones[3].getArtista() << std::endl;
  std::cout << "Álbum: " << _canciones[3].getAlbum() << std::endl;
  std::cout << "Duración: " << _canciones[3].getDuracionString() << std::endl;
  std::cout << std::endl;
}

void Playlist::modoAleatorio() {
  std::cout << "-Playlist cambio-" << std::endl;
  std::cout << "Modo de ejecucion: Aleatorio" << std::endl;
  std::cout << std::endl;
}