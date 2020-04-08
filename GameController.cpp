#include "GameController.h"

GameController::GameController(Game* game, int dimension)
{
    if (game)
    {

    }
    else
    {
        _dimension = dimension;
        _board.InsertValues(CreateValuesVector(_dimension));
        Mix();
        _game = std::make_unique<Game>(GetValuesString());
    }
}


void GameController::Start()
{
    _moves = 0;
    _blankFieldBackwardPositions.clear();
    _blankFieldForwardPositions.clear();
}

void GameController::Mix()
{
    _blankFieldBackwardPositions.clear();
    _blankFieldBackwardPositions.clear();

    srand(time(NULL));

    for (int i = 0; i < 100*_dimension; i++)
    {
        auto neighbours =_board.GetBlankNeighbors();

        auto rand = std::rand()%neighbours.size();
        _board.MoveToBlank(neighbours[rand]);
    }
}

std::vector<int> GameController::CreateValuesVector(int dimension)
{
    std::vector<int> valuesSet;

    for (int i = 1; i < dimension * dimension; i++)
    {
        valuesSet.push_back(i);
    }

    valuesSet.push_back(0);

    return valuesSet;
}

std::map<Position, int> GameController::GetValues() const
{
    return _board.GetValues();
}

std::string GameController::GetValuesString() const
{
    std::string valuesString;

    auto values = GetValues();
    for (auto value: values)
    {
        valuesString +=value.second;
    }

    return valuesString;
}

Position* GameController::GetPositionForValue(int value) const
{
    return _board.GetPositionForValue(value);
}

int GameController::GetMoves() const
{
    return _moves;
}

bool GameController::MoveToBlank(Position position)
{
    _blankFieldBackwardPositions.push_back(_board.GetBlankPosition());
    if (_blankFieldBackwardPositions.size() > 3)
    {
        _blankFieldBackwardPositions.erase(_blankFieldBackwardPositions.begin());
    }

    if (_board.MoveToBlank(position))
    {
        _moves++;
        _blankFieldForwardPositions.clear();
        return true;
    }

    _blankFieldBackwardPositions.pop_back();
    return false;
}

bool GameController::IsFinished() const
{
    auto values = _board.GetValues();
    auto it = values.begin();

    for(auto val: values)
    {
        it++;

        if (it->second == 0)
            break;

        if (val.second >= it->second)
            return false;
    }

    return (it->first == Position(_dimension-1, _dimension-1));
}

bool GameController::NavigateForward()
{
    if (CanNavigateForward())
    {
        _blankFieldBackwardPositions.push_back(_board.GetBlankPosition());

        if (_board.MoveToBlank(_blankFieldForwardPositions.back()))
        {
            _blankFieldForwardPositions.pop_back();
            _moves++;

            return true;
        }
        _blankFieldBackwardPositions.pop_back();
    }

    return false;
}

bool GameController::NavigateBackward()
{
    if (CanNavigateBackward())
    {
        _blankFieldForwardPositions.push_back(_board.GetBlankPosition());

        if (_board.MoveToBlank(_blankFieldBackwardPositions.back()))
        {

            _blankFieldBackwardPositions.pop_back();
            _moves--;

            return true;
        }
        _blankFieldForwardPositions.pop_back();
    }

    return false;
}

bool GameController::CanNavigateBackward() const
{
    return _blankFieldBackwardPositions.size() > 0;
}

bool GameController::CanNavigateForward() const
{
    return _blankFieldForwardPositions.size() > 0;
}
