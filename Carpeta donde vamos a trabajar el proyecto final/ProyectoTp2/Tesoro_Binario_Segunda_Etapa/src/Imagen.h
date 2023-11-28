#ifndef IMAGEN_H_
#define IMAGEN_H_

#include "EasyBMP/EasyBMP.h"
using namespace std;

class Imagen{
private:
        BMP *imagen;
        unsigned int alto;
        unsigned int ancho;
public:
        /*
        * pre: alto y ancho deben ser mayores a 0.
        * post: Crea una imagen blanca de tamaño alto * ancho en pixeles.
        * */
        Imagen(unsigned int alto, unsigned int ancho);

        /*
        * pre: -
        * post: Libera la memoria reservada por la imagen.
        * */
        virtual ~Imagen();

        /*
        * pre: -
        * post: Devuelve el alto de la imagen
        * */
        unsigned int getAlto();

        /*
        * pre: -
        * post: Devuelve el ancho de la imagen
        * */
        unsigned int getAncho();

        /*
        * pre: rutaImagenACopiar no puede ser nula.
        *       x e y deben ser mayores o iguales a 0.
        * post: Copia la imagen en la ruta recibida a partir de la posición
        *       (x,y) recibida en la imagen de rutaImagenDestino.
        * */
        void copiarImagen(string rutaImagenACopiar, int x, int y, string rutaImagenDestino);
};

#endif //IMAGEN_H_