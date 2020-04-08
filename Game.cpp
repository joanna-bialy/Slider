#include "Game.h"

Game::Game()
{
}

Game::Game(std::string initialBoardState) :
    _initialBoardState(initialBoardState)
{
}

Game::Game(std::string initialBoardState, std::string currentBoardState, int moves) :
    _initialBoardState(initialBoardState),
    _currentBoardState(currentBoardState),
    _moves(moves)
{
}

void Game::SetInitialBoardState(std::string initialBoardState)
{
    _initialBoardState = initialBoardState;
}

std::string Game::GetInitialBoardState() const
{
    return _initialBoardState;
}

void Game::SetCurentBoardState(std::string currentBoardState)
{
    _currentBoardState = currentBoardState;
}


std::string Game::GetCurentBoardState() const
{
    return _initialBoardState;
}
