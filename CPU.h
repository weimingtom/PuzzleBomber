#ifndef CPU_H
#define CPU_H

enum { IDLED, ATTACKED, HURTED };

enum { easy, medium,hard };
enum { CPU_SET_RND_BLOCK,CPU_GEM_DROP,CPU_GEM_HIT,CPU_GEM_BREAK };

class CPU  {
	public:
		int logic;
		Character **character;
		int Mood;
		int ACPU();
		void Start_AI(int diff);
		void Easy_Mode();
};

#include "CPU.cpp"

#endif
