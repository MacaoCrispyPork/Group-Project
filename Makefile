files: Character.cpp Enemy.cpp Entity.cpp Game.cpp main.cpp Player.cpp Projectile.cpp Skeleton.cpp Weapon.cpp Zombie.cpp Button.cpp GameState.cpp
	g++ Character.cpp Enemy.cpp Game.cpp Entity.cpp main.cpp Player.cpp Projectile.cpp Skeleton.cpp Weapon.cpp Zombie.cpp Button.cpp GameState.cpp -o main.o -lsfml-graphics -lsfml-window -lsfml-system
	./main.o