// Héctor Marcelo Arroyo Morantte - A00837236
// TC1033.304
// Creado 14/11/2022
// Actualizado 28/11/2022

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