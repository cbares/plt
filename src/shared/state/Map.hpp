// Generated by dia2code
#ifndef STATE__MAP__H
#define STATE__MAP__H

#include <vector>

namespace state {
  class Case;
}

#include "Case.hpp"
#include "GameStatus.hpp"

namespace state {

  /// class Map - 
  class Map {
    // Associations
    // Attributes
  private:
    int Length;
    int Width;
    std::vector<std::vector<Case>> ListCase;
    // Operations
  public:
    Map (int length, int width);
    int GetLength ();
    int GetWidth ();
    std::vector<std::vector<Case>> GetListCase ();
    void SetListCase (Case case1, int i, int j);
    // Setters and Getters
  };

};

#endif
