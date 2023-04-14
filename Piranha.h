#pragma once
#include "stdafx.h"

#ifndef PIRANHA_H
#define PIRANHA_H

class Piranha :public Entity
{
	public:	

#ifndef PIRANHAIDLE_H
#define	PIRANHAIDLE_H

		class PiranhaIdle : public FSMState
		{
		public:
			Piranha *piranha;
			PiranhaIdle(Piranha *);
			~PiranhaIdle();

			void enter();
			void exit();
			void update();
		};
#endif //!PIRANHAIDLE_H

#ifndef PIRANHAATTACK_H
#define	PIRANHAATTACK_H

		class PiranhaAttack : public FSMState
		{
		public:
			Piranha *piranha;
			PiranhaAttack(Piranha *);
			~PiranhaAttack();

			void enter();
			void exit();
			void update();
		};
#endif //!PIRANHAATTACK_H

#ifndef PIRANHAKO_H
#define	PIRANHAKO_H

		class PiranhaKO : public FSMState
		{
		public:
			Piranha *piranha;
			PiranhaKO(Piranha *);
			~PiranhaKO();

			void enter();
			void exit();
			void update();
		};
#endif //!PIRANHAKO_H

	PiranhaIdle *piranhaIdle;
	PiranhaAttack *piranhaAttack;
	PiranhaKO *piranhaKO;

	Piranha(float x, float y);
	~Piranha();

	void print() const;
	void update();
};

#endif // !PIRANHA_H



