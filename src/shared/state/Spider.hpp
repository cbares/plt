// Generated by dia2code
#ifndef STATE__SPIDER__H
#define STATE__SPIDER__H

#include <vector>

namespace state {
  class Insect;
  class Case;
}

#include "Insect.hpp"
#include "Case.hpp"

namespace state {

  /// class Spider - 
  class Spider : public state::Insect {
    // Operations
  public:
    Spider ();
    std::vector<std::vector<int>> Possible_Deplacement_Insect (std::vector<Insect> list_insect_placed, std::vector<Case> list_case);
    // Setters and Getters
  };

};

#endif
