#include <iostream>
#include "Playlist.h"

int main() {
  Playlist playlist;
  playlist.creaPlaylist();
  while (playlist.verificarCampoNombre())
    playlist.agregarCancion();
  playlist.mostrarMensajeCreacion();
  playlist.consultaPlaylist();
  playlist.modoAleatorio();
  playlist.mostrarCuartaCancion();
  playlist.consultaPlaylistAleatoria();

  return 0;
}