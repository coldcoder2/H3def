	/*********************************************************
	* This is the format of H3def files
	* Auther : coldcoderH3
	* Verson : 0.3
	*********************************************************/
	
	#ifndef DEF_H
	#define DEF_H
	
	#include <vector>
	#include <memory.h>
	#include <fstream>
	using std::vector;
	using std::ifstream;
	using std::ofstream;
	using std::memset;
	
	typedef unsigned char ui8;
	
	struct RGB
	{
		ui8 r;
		ui8 g;
		ui8 b;
	};
	
	struct Entry
	{
		char name[13];
		int offset;
	};
	
	struct Block
	{
		int id;
		int totalEntries;
		int unknown1;
		int unknown2;
		vector<Entry> entries;
	};
	
	class Def
	{
		public:
			Def();
			Def(ifstream& file);
		protected:
			ui8 readChar();
		private:
			ifstream def;
			int type;
			int fullWidth;
			int fullHeight;
			int totalBlocks;
			RGB palette[256];
			vector<Block> blocks;
			vector<ui8> data;
	};
	
	Def::Def()
	{
		def.close();
		type = 0;
		fullWidth = 0;
		fullHeight = 0;
		totalBlocks = 0;
		memset(palette,0,sizeof(palette));
		blocks.clear();
		data.clear();
	}
	
	Def::Def(ifstream& file)
	{
		def = file;
	}
	
	#endif
	
