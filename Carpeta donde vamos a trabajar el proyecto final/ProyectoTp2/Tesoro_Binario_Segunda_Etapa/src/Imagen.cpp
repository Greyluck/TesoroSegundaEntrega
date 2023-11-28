#include "Imagen.h"

Imagen::Imagen(unsigned int alto, unsigned int ancho)
{
        if(alto <= 0 || ancho <= 0){
                throw std::string("El alto y ancho de la imagen deben ser mayores a 0");
        }

        this->imagen = new BMP();
        this->alto = alto;
        this->ancho = ancho;
        this->imagen->SetSize(ancho, alto);
        this->imagen->SetBitDepth(24);
}

Imagen::~Imagen()
{
        delete this->imagen;
}

unsigned int Imagen::getAlto()
{
        return this->alto;
}

unsigned int Imagen::getAncho()
{
        return this->ancho;
}

void Imagen::copiarImagen(string rutaImagenACopiar, int x, int y, string rutaImagenDestino)
{
        BMP auxilar;
        auxilar.ReadFromFile(rutaImagenACopiar.c_str());
        RangedPixelToPixelCopy(auxilar, 0, auxilar.TellWidth()-1, auxilar.TellHeight()-1, 0, *(this->imagen), x-1, y-1);
        this->imagen->WriteToFile(rutaImagenDestino.c_str()); 
}
