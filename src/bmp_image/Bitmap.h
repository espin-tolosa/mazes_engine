#ifndef BITMAP_H
#define BITMAP_H
#include <string>
#include <cstdint>
#include <memory>



namespace set {

class Bitmap {

public:
    Bitmap() = default;
    Bitmap(std::string filename);
    Bitmap(uint32_t width, uint32_t height);

    static bool Read(std::string filename);
    void Log();

    void SetPixel(uint32_t x, uint32_t y, uint8_t red, uint8_t green, uint8_t blue);
    uint32_t GetPixel(int32_t x, uint32_t y);
    void SetBackGround(uint8_t red, uint8_t green, uint8_t blue);
    bool Write(std::string filename);
    uint32_t ResolutionImage();
    uint32_t GetWidth();
    uint32_t GetHeight();

protected:
    uint32_t m_width;
    uint32_t m_height;
    //std::unique_ptr<uint8_t[]> m_pPixels{nullptr};
    uint8_t* m_pPixels{nullptr};
};

} //namespace set

#endif
