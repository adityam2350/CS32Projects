//
//  Game.hpp
//  CS32-Proj1
//
//  Created by Adi Mehta on 1/10/22.
//

#ifndef GAME_H
#define GAME_H

class Mesa;
class Game
{
  public:
        // Constructor/destructor
    Game(int rows, int cols, int nGarks);
    ~Game();

        // Mutators
    void play();

  private:
    Mesa* m_mesa;
};

#endif /* Game_hpp */
