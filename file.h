	/******************************************
	* This is the extended file class header.
	* And now it is only for the binary files.
	* Auther : coldcoderH3
	* Verson : 0.2
	******************************************/
	
	#ifndef FILE_H
	#define FILE_H
	
	#include <fstream>
	
	enum fType
	{
		high,
		low
	};
	
	class File
	{
		public:
			File();
			~File();
			char read8();
			short read16(fType type = high);
			int read32(fType type = high);
		private:
			std::fstream * file;
			std::ios_base::openmode mode;
	};
	
	File::File()
	{
		file = NULL;
	}
	
	File::~File()
	{
		file->close();
	}
	
	char File::read8()
	{
		char * buffer;
		file->read(buffer,1);
		return (*buffer);
	}
	
	short File::read16(fType type)
	{
		
	}
	
	int File::read32(fType type)
	{
		
	}
	
	#endif /* FILE_H */
	
