#include <stdio.h>
#include <stdlib.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

GLuint loadBMP_custom(const char * imagepath) {
  unsigned char header[54];
  unsigned int dataPos;
  unsigned int width, height;
  unsigned int imageSize;

  unsigned char * data;

  // open file & check format
  FILE * file = fopen(imagepath, "rb");
  if (!file) {
    printf("Image couldn't be opened\n");
    return 0;
  }
  if (fread(header, 1, 54, file) != 54) {
    printf("Not a correct BMP file\n");
    return 0;
  }
  if (header[0] != 'B' || header[1] != 'M') {
    printf("Not a correct BMP file\n");
    return 0;
  }

  // read in BMP file data
  dataPos   = *(int*)&(header[0x0A]);
  imageSize = *(int*)&(header[0x22]);
  width     = *(int*)&(header[0x12]);
  height    = *(int*)&(header[0x16]);

  // supplement values if they are unspecified
  if (imageSize == 0) imageSize = width * height * 3;
  if (dataPos == 0) dataPos = 54;

  // create a buffer for image
  data = new unsigned char [imageSize];
  // read the BMP file data into the buffer
  fread(data, 1, imageSize, file);
  // everything is read into memory, close file
  fclose(file);

  // Create one OpenGL texture
	GLuint textureID;
	glGenTextures(1, &textureID);

	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
  glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
}