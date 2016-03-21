#include "filetool.h"

unsigned char readUint8(std::ifstream& file) {
	char bytes[1];
	file.read(bytes, 1);
	return bytes[0];
}

signed char readSint8(std::ifstream& file) {
	char bytes[1];
	file.read(bytes, 1);
	return bytes[0];
}

unsigned short readUint16(std::ifstream& file) {
	char bytes[2];
	file.read(bytes, 2);
	return (((unsigned char)bytes[0] << (8 * 0)) | ((unsigned char)bytes[1] << (8 * 1)));
}

signed short readSint16(std::ifstream& file) {
	char bytes[2];
	file.read(bytes, 2);
	return ((bytes[0] << (8 * 0)) | (bytes[1] << (8 * 1)));
}

unsigned int readUint32(std::ifstream& file) {
	char bytes[4];
	file.read(bytes, 4);
	return (((unsigned char)bytes[0] << (8 * 0)) |
			((unsigned char)bytes[1] << (8 * 1)) |
			((unsigned char)bytes[2] << (8 * 2)) |
			((unsigned char)bytes[3] << (8 * 3)));
}

signed int readSint32(std::ifstream& file) {
	char bytes[4];
	file.read(bytes, 4);
	return ((bytes[0] << (8 * 0)) |
			(bytes[1] << (8 * 1)) |
			(bytes[2] << (8 * 2)) |
			(bytes[3] << (8 * 3)));
}

void writeUint8(std::ofstream& file, unsigned char val) {
	char bytes = val & 0xFF;
	file.write(&bytes, 1);
}

void writeSint8(std::ofstream& file, signed char val) {
	char bytes = val & 0xFF;
	file.write(&bytes, 1);
}

void writeUint16(std::ofstream& file, unsigned short val) {
	char bytes[2];
	bytes[0] = (char)val & 0xFF;
	bytes[1] = (char)(val >> 8) & 0xFF;
	file.write(bytes, 2);
}

void writeSint16(std::ofstream& file, signed short val) {
	char bytes[2];
	bytes[0] = (char)val & 255;
	bytes[1] = (char)(val >> 8) & 0xFF;
	file.write(bytes, 2);
}

void writeUint32(std::ofstream& file, unsigned int val) {
	char bytes[4];
	bytes[0] = (val >> (8 * 0)) & 0xFF;
	bytes[1] = (val >> (8 * 1)) & 0xFF;
	bytes[2] = (val >> (8 * 2)) & 0xFF;
	bytes[3] = (val >> (8 * 3)) & 0xFF;
	file.write(bytes, 4);
}

void writeSint32(std::ofstream& file, signed int val) {
	char bytes[4];
	bytes[0] = (val >> (8 * 0)) & 0xFF;
	bytes[1] = (val >> (8 * 1)) & 0xFF;
	bytes[2] = (val >> (8 * 2)) & 0xFF;
	bytes[3] = (val >> (8 * 3)) & 0xFF;
	file.write(bytes, 4);
}

float readFloat(std::ifstream& file) {
	float val;
	file.read((char*)&val, 4);
	return val;
}

void writeFloat(std::ofstream& file, float val) {
	file.write((const char*)&val, 4);
}

std::string readString(std::ifstream& file) {
	unsigned int i = 0;
	char buffer[256];
	//while(file.read(buffer + i++, 1));
	file.read(buffer, 1);
	while(buffer[i++]) {
		file.read(&buffer[i], 1);
	}
	
	buffer[i - 1] = '\0';
	
	std::string string(buffer);
	return string;
}

void writeString(std::ofstream& file, const std::string& val) {
	unsigned int length = val.length();
	file.write(val.c_str(), length + 1);
}
