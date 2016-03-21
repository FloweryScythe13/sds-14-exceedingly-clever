#ifndef FILETOOL_H
#define FILETOOL_H

#include <fstream>
#include <string>

//Binary int reading and writing
extern unsigned char readUint8(std::ifstream& file);
extern signed char readSint8(std::ifstream& file);
extern unsigned short readUint16(std::ifstream& file);
extern signed short readSint16(std::ifstream& file);
extern unsigned int readUint32(std::ifstream& file);
extern signed int readSint32(std::ifstream& file);

extern void writeUint8(std::ofstream& file, unsigned char val);
extern void writeSint8(std::ofstream& file, signed char val);
extern void writeUint16(std::ofstream& file, unsigned short val);
extern void writeSint16(std::ofstream& file, signed short val);
extern void writeUint32(std::ofstream& file, unsigned int val);
extern void writeSint32(std::ofstream& file, signed int val);

//Binary float reading and writing
extern float readFloat(std::ifstream& file);
extern void writeFloat(std::ofstream& file, float val);

//Binary string reading and writing
extern std::string readString(std::ifstream& file);
extern void writeString(std::ofstream& file, const std::string& val);

#endif
