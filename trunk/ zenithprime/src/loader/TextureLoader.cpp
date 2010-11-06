#include "TextureLoader.h"

bool Texture::LoadBitmap(LPTSTR szFileName, GLuint &texid)                    // Creates Texture From A Bitmap File
{
    HBITMAP hBMP;                                                        // Handle Of The Bitmap
    BITMAP    BMP;                                                        // Bitmap Structure
    glGenTextures(1, &texid);                                            // Create The Texture
    hBMP=(HBITMAP)LoadImage(GetModuleHandle(NULL), szFileName, IMAGE_BITMAP, 0, 0, LR_CREATEDIBSECTION | LR_LOADFROMFILE );
    if (!hBMP)                                                            // Does The Bitmap Exist?
        return FALSE;                                                    // If Not Return False
    GetObject(hBMP, sizeof(BMP), &BMP);                                    // Get The Object
    glPixelStorei(GL_UNPACK_ALIGNMENT, 4);                                // Pixel Storage Mode (Word Alignment / 4 Bytes)
    glBindTexture(GL_TEXTURE_2D, texid);                                // Bind To The Texture ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);    // Linear Min Filter
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);    // Linear Mag Filter
    glTexImage2D(GL_TEXTURE_2D, 0, 3, BMP.bmWidth, BMP.bmHeight, 0, GL_BGR_EXT, GL_UNSIGNED_BYTE, BMP.bmBits);
    DeleteObject(hBMP);                                                    // Delete The Object
    return TRUE;                                                        // Loading Was Successful
}