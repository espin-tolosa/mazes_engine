#ifndef BITMAPFILEHEADER_H
#define BITMAPFILEHEADER_H

#include <cstdint>


namespace set {


#pragma pack(2)
#pragma pack(push)
struct BitmapFileHeader
{
  char header[2]{'B', 'M'};  
  int32_t fileSize;
  int32_t reserved{0};
  int32_t dataOffset;
};

}
#pragma pack(pop)

#endif //BITMAPFILEHEADER
