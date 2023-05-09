#include "stdafx.h"

#ifndef MARIO_H
#define MARIO_H

class Mario :public Entity
{
	public:

	#ifndef MARIOIDLE_H
	#define MARIOIDLE_H
	class MarioIdle : public FSMState
	{
		public:
		Mario *mario;

		MarioIdle(Mario *);
		~MarioIdle();

		void enter();
		void exit();
		void update();
	};
	#endif // !MARIOIDLE_H

	#ifndef MARIOWALK_H
	#define MARIOWALK_H
	class MarioWalk : public FSMState
	{
		public:
		Mario *mario;

		MarioWalk(Mario *);
		~MarioWalk();

		void enter();
		void exit();
		void update();
	};
	#endif // !MARIOWALK_H

	#ifndef MARIOJUMP_H
	#define MARIOJUMP_H
	class MarioJump : public FSMState
	{
		public:
		Mario *mario;

		MarioJump(Mario *);
		~MarioJump();

		void enter();
		void exit();
		void update();
	};
	#endif // !MARIOJUMP_H

	#ifndef MARIOSHOOT_H
	#define MARIOSHOOT_H
	class MarioShoot : public FSMState
	{
	public:
		Mario *mario;

		MarioShoot(Mario *);
		~MarioShoot();

		void enter();
		void exit();
		void update();
	};
	#endif // !MARIOSHOOT_H

	#ifndef MARIOHIT_H
	#define MARIOHIT_H
	class MarioHit : public FSMState
	{
	public:
		Mario *mario;

		MarioHit(Mario *);
		~MarioHit();

		void enter();
		void exit();
		void update();
	};
	#endif // !MARIOHIT_H

#ifndef MARIOKO_H
#define MARIOKO_H
	class MarioKO : public FSMState
	{
	public:
		Mario *mario;

		MarioKO(Mario *);
		~MarioKO();

		void enter();
		void exit();
		void update();
	};
#endif // !MARIOKO_H

	MarioIdle *marioIdle;
	MarioWalk *marioWalk;
	MarioJump *marioJump;
	MarioShoot *marioShoot;
	MarioHit *marioHit;
	MarioKO *marioKO;

	bool leftButton;
	bool rightButton;
	bool upButton;
	bool downButton;
	bool fireButton;
	bool jumpButton;


	Mario(float x, float y);
	~Mario();

	void print() const;
	void update();
};

#endif // !MARIO_H





