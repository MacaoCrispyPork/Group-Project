files: Character.cpp Enemy.cpp Entity.cpp Game.cpp main.cpp Player.cpp Projectile.cpp Skeleton.cpp Weapon.cpp Zombie.cpp
	g++ Character.cpp Enemy.cpp Game.cpp Entity.cpp main.cpp Player.cpp Projectile.cpp Skeleton.cpp Weapon.cpp Zombie.cpp -o main.o -lsfml-graphics -lsfml-window -lsfml-system
	./main.o

units: Character.cpp Enemy.cpp Entity.cpp Game.cpp test.cpp Player.cpp Projectile.cpp Skeleton.cpp Weapon.cpp Zombie.cpp UnitTesting.cpp
	g++ Character.cpp Enemy.cpp Game.cpp Entity.cpp test.cpp Player.cpp Projectile.cpp Skeleton.cpp UnitTesting.cpp Weapon.cpp Zombie.cpp -o test.o -lsfml-graphics -lsfml-window -lsfml-system
	./test.o