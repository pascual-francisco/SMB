#include "stdafx.h"

#ifndef GOOMBA_H
#define GOOMBA_H

class Goomba: public Entity
{
	public:

	#ifndef GOOMBAIDLE_H
	#define	GOOMBAIDLE_H

	class GoombaIdle : public FSMState
	{
		public:
		Goomba *goomba;
		GoombaIdle(Goomba *);
		~GoombaIdle();

		void enter();
		void exit();
		void update();
	};
	#endif //!GOOMBAIDLE_H

#ifndef GOOMBAWALK_H
#define	GOOMBAWALK_H

	class GoombaWalk : public FSMState
	{
	public:
		Goomba *goomba;
		GoombaWalk(Goomba *);
		~GoombaWalk();

		void enter();
		void exit();
		void update();
	};
#endif //!GOOMBAWALK_H

#ifndef GOOMBAKO_H
#define GOOMBAKO_H
	class GoombaKO : public FSMState
	{
	public:
		Goomba *goomba;
		GoombaKO(Goomba *);
		~GoombaKO();

		void enter();
		void exit();
		void update();
	};
#endif // !GOOMBAKO_H

	GoombaIdle *goombaIdle;
	GoombaIdle *goombaWalk;
	GoombaKO *goombaHit;

	Goomba(float x, float y);
	~Goomba();

	void print() const;
	void update();
};

#endif // !GOOMBA_H





