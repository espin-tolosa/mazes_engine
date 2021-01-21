//#include <string>
#include <iostream>
#include <fstream>
#include <inttypes.h>
#include "Bitmap.h"
#include "BitmapInfoHeader.h"
#include "BitmapFileHeader.h"

static const uint8_t channels = 3;

namespace set {

Bitmap::Bitmap(uint32_t w, uint32_t h)
: m_width{w}, m_height{h}, m_pPixels{new uint8_t[w*h*channels]{0}} { }

Bitmap::Bitmap(std::string filename) {

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    std::ifstream file;
    file.open(filename, std::ios::in | std::ios::binary);

    if(file){

      file.read((char *)&fileHeader, sizeof(fileHeader));
      file.read((char *)&infoHeader, sizeof(infoHeader));
      
      m_width=infoHeader.width;
      m_height=infoHeader.height;
      m_pPixels=new uint8_t[m_width*m_height*channels];

      file.read((char *)m_pPixels, ResolutionImage());
      file.close();
    }
    else {std::cout << "Error Bitmap::Bitmap(string filename): no such filename" << std::endl;}
}

bool Bitmap::Read(std::string filename) {

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    std::ifstream file;
    file.open(filename, std::ios::in | std::ios::binary);

    if(!file) return false;

    file.read((char *)&fileHeader, sizeof(fileHeader));
    file.read((char *)&infoHeader, sizeof(infoHeader));
//    file.read((char *)m_pPixels.get(), ResolutionImage());

  Bitmap(infoHeader.width, infoHeader.height);
  file.close();
  return true;
}

void Bitmap::Log() {
  std::cout << "Width: " << m_width << std::endl;
  std::cout << "Height: " << m_height << std::endl;
}

void Bitmap::SetPixel(uint32_t x, uint32_t y, uint8_t red, uint8_t green, uint8_t blue) {

//    uint8_t* pPixel = m_pPixels.get(); //case for unique_ptr
    uint8_t* pPixel = m_pPixels;
    pPixel += channels*(y*m_width + x);

    pPixel[0] = blue;
    pPixel[1] = green;
    pPixel[2] = red;
}

uint32_t Bitmap::GetPixel(int32_t x, uint32_t y) {

//    uint8_t* pPixel = m_pPixels.get(); //case for unique_ptr
    uint8_t* pPixel = m_pPixels;
    pPixel += channels*(y*m_width + x);

    return (pPixel[0] + pPixel[1] + pPixel[2] < (200)?1000000000:1);
}

void Bitmap::SetBackGround(uint8_t red, uint8_t green, uint8_t blue) {

    for(uint32_t i = 0; i < ResolutionImage(); i++)
        m_pPixels[i] = 200;

}

bool Bitmap::Write(std::string filename) {

    BitmapFileHeader fileHeader;
    BitmapInfoHeader infoHeader;

    fileHeader.fileSize = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader)  + ResolutionImage();
    fileHeader.dataOffset = sizeof(BitmapFileHeader) + sizeof(BitmapInfoHeader);

    infoHeader.width = m_width;
    infoHeader.height = m_height;

    std::ofstream file;
    file.open(filename, std::ios::out | std::ios::binary);

    if(!file) return false;

    file.write((char *)&fileHeader, sizeof(fileHeader));
    file.write((char *)&infoHeader, sizeof(infoHeader));
//    file.write((char *)m_pPixels.get(), ResolutionImage()); //unique_ptr
    file.write((char *)m_pPixels, ResolutionImage());


    std::cout << "Writen file: " << filename << std::endl;
    file.close();
    return true;
}

uint32_t Bitmap::ResolutionImage() {
    return channels*m_width*m_height;
}

uint32_t Bitmap::GetWidth() {
  return m_width;
}

uint32_t Bitmap::GetHeight() {
  return m_height;
}

} //namespace set

