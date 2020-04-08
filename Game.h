#ifndef GAME_H
#define GAME_H

#include <vector>
#include <string>

class Game
{
public:
    Game();
    Game(std::string initialBoardState);
    Game(std::string initialBoardState, std::string currentBoardState, int moves);

    void SetInitialBoardState(std::string initialBoardState);
    std::string GetInitialBoardState() const;
    void SetCurentBoardState(std::string currentBoardState);
    std::string GetCurentBoardState() const;

private:
    std::string _initialBoardState;
    std::string _currentBoardState;
    int _moves;
};

#endif // GAME_H
