
#include "stdafx.h"

#ifndef TROOPA_H
#define TROOPA_H

class Troopa :public Entity
{
	public:

#ifndef TROOPAIDLE_H
#define TROOPAIDLE_H
		class TroopaIdle : public FSMState
		{
		public:
			Troopa *troopa;

			TroopaIdle(Troopa *);
			~TroopaIdle();

			void enter();
			void exit();
			void update();
		};
#endif // !TROOPAIDLE_H

	#ifndef TROOPAWALK_H
	#define TROOPAWALK_H
	class TroopaWalk : public FSMState
	{
		public:
			Troopa *troopa;

			TroopaWalk(Troopa *);
			~TroopaWalk();

			void enter();
			void exit();
			void update();
		};
	#endif // !TROOPAWALK_H

#ifndef TROOPASHELL_H
#define TROOPASHELL_H
	class TroopaShell : public FSMState
	{
	public:
		Troopa *troopa;

		TroopaShell(Troopa *);
		~TroopaShell();

		void enter();
		void exit();
		void update();
	};
#endif // !TROOPASHELL_H

#ifndef TROOPAKO_H
#define TROOPAKO_H
	class TroopaKO : public FSMState
	{
	public:
		Troopa *troopa;

		TroopaKO(Troopa *);
		~TroopaKO();

		void enter();
		void exit();
		void update();
	};
#endif // !TROOPAKO_H

	Troopa(float x, float y);
	~Troopa();

	GLfloat shellTime;

	void print() const;
	void update();
};

#endif // !TROOPA_H



