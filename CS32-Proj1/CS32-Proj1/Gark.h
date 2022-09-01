//
//  Gark.hpp
//  CS32-Proj1
//
//  Created by Adi Mehta on 1/10/22.
//

#ifndef GARK_H
#define GARK_H
class Mesa;
class Gark
{
  public:
        // Constructor
    Gark(Mesa* mp, int r, int c);

        // Accessors
    int  row() const;
    int  col() const;

        // Mutators
    void move();
    bool getAttacked(int dir);

  private:
    Mesa* m_mesa;
    int   m_row;
    int   m_col;
    int   m_health;
};


#endif
