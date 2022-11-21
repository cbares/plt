#include "PlacementCommand.hpp"


engine::PlacementCommand::PlacementCommand(state::GameStatus gamestatus, std::vector<int> position_insect,
                                           state::Insect insect, engine::CommandTypeId commandId,state::Player player) {
    this->insect=insect;
    this->commandTypeId=commandId;
    this->playing=gamestatus;
    this->position=position_insect;
    this->player=player;

}

bool engine::PlacementCommand::execute(engine::Engine& engine) {

    state::Insect& insect_to_move = this->insect;

    std::vector<state::Case> listCase;
    std::vector<std::vector<state::Case>>CaseVector=engine.getState().GetMap().GetListCase();
    for (int i=0;i<engine.getState().GetMap().GetLength();i++){
        for (int j=0;j<engine.getState().GetMap().GetWidth();j++){
            listCase.push_back(CaseVector[i][j]);
        }
    }

    std::vector<state::Insect> allinsects = engine.getState().GetAllInsects();
    std::vector<state::Insect> allinsects_placed;
    for (int i =0;i<allinsects.size();i++){
        if(allinsects[i].GetIsPlaced()){
            allinsects_placed.push_back(allinsects[i]);
        }
    }



    std::vector<std::vector<int>> listcoordpossible = insect_to_move.Possible_Placement_Insect(allinsects_placed,listCase);

    bool authorisation_placement=0;
    for(std::vector<int> temp : listcoordpossible){
        if((temp[0]==this->position[0])&&(temp[1]==this->position[1])){
            authorisation_placement=1;
            break;
        }
    }


    if (authorisation_placement){
        insect.SetPosition(this->position);
        engine.getState().GetMap().SetListCase(state::Case({position[0],position[1]},0),position[0],position[1]);


        //Vider la liste insecte remaining du joueur
        this->player.Remove_Insect_Remaining(insect);

        //Remplir la liste insecte placed du joueur
        this->player.Add_Insect_Played(insect);

        return true;
    }
    else{
        return false;
    }



}
